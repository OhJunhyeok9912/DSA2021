#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 1001 // 사이즈 1을 추가  
#define MAX_Q 1001 // 사이즈 1을 추가

typedef struct GraphType {
	int n;
	int adj[MAX_VERTICES][MAX_VERTICES]; // 그래프를 행렬로 표현
};

int visited1[MAX_VERTICES]; // dfs
int visited2[MAX_VERTICES]; // bfs


void init(GraphType* g)
{
	int r, c;
	g->n = 0;
	for (r = 0; r < MAX_VERTICES; r++)
		for (c = 0; c < MAX_VERTICES; c++)
			g->adj[r][c] = 0;
}
// 정점 삽입 연산
void insert_vertex(GraphType* g, int v)
{
	if (((g->n) + 1) > MAX_VERTICES)
		return;
	g->n++;
}
// 간선 삽입 연산
void insert_edge(GraphType* g, int start, int end)
{
	if (start > g->n || end > g->n) 
		return;
	g->adj[start][end] = 1;
	g->adj[end][start] = 1;
}
// 인접 행렬로 표현된 그래프에 대한 깊이 우선 탐색
void dfs(GraphType* g, int v)
{
	int w;
	visited1[v] = TRUE;		// 정점 v의 방문 표시 
	printf("%d ", v);		// 방문한 정점 출력
	for (w = 1; w <= g->n; w++) 		// 인접 정점 탐색, 1번부터 입력 받기 때문에 시작을 1로 한다. 
		if (g->adj[v][w] && !visited1[w])
			dfs(g, w);	//정점 w에서 DFS 새로 시작
}


typedef int element;
typedef struct { // 큐 타입
	element  queue[MAX_Q];
	int  front, rear;
} QueueType; // 원형 큐로 생성


void queue_init(QueueType* q)
{
	q->front = q->rear = 0;
} // 큐 초기화 


int is_empty(QueueType* q)
{
	return (q->front == q->rear);
} // 공백 상태 검출 함수


int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX_Q == q->front);
} // 포화 상태 검출 함수


void enqueue(QueueType* q, element item)
{
	if (is_full(q))exit(1);
	q->rear = (q->rear + 1) % MAX_Q;
	q->queue[q->rear] = item;
} // 삽입 함수


element dequeue(QueueType* q)
{
	if (is_empty(q)) exit(1);
	q->front = (q->front + 1) % MAX_Q;
	return q->queue[q->front];
 }// 삭제 함수

// 행렬로 표현된 그래프에 대한 너비 우선 탐색
void bfs(GraphType* g, int v)
{
	int w;
	QueueType q;

	queue_init(&q);     // 큐 초기화 
	visited2[v] = TRUE;          // 정점 v 방문 표시 
	printf("%d ", v);
	enqueue(&q, v);			// 시작 정점을 큐에 저장 
	while (!is_empty(&q)) {
		v = dequeue(&q);		// 큐에 정점 추출 
		for (w = 1; w <= g->n; w++)	// 인접 정점 탐색, 1번부터 입력 받기 때문에 시작을 1로 한다.  
			if (g->adj[v][w] && !visited2[w]) {
				visited2[w] = TRUE;    // 방문 표시
				printf("%d ", w);
				enqueue(&q, w); 	// 방문한 정점을 큐에 저장
			}
	}
}

int main() {
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	init(g);
	int n, m, v, i;
	int s, e;
	scanf_s("%d %d %d", &n, &m, &v);
	for (i = 1; i <= n; i++) {
		insert_vertex(g, i); // 1번 정점부터 삽입  
	}

	for (i = 0; i < m; i++) {
		scanf_s("%d %d", &s, &e);
		insert_edge(g, s, e); // 간선을 삽입
	}
	dfs(g, v);
	printf("\n");
	bfs(g, v);
}

