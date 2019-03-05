/*************************************************************************
	> File Name: 深度优先搜寻的实现.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年03月05日 星期二 20时35分13秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 10000

typedef struct Node {
    int vertex;
    struct Node *next;
}Node, *LinkedList;

LinkedList insert_node(LinkedList head, int index) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->vertex = index;
    node->next = head;
    head = node;
    return head;
}

typedef struct Graph {
    LinkedList edges[MAX_N];
    int n;
    int visited[MAX_N];
}Graph;

void init(Graph *g, int n) {
    g->n = n;
    for (int i = 0; i < g->n; ++i) {
        g->edges[i] = NULL;
    }
    memset(g->visited, 0, sizeof(g->visited));
}

void insert(Graph *g, int x, int y) {
    if (x < 0 || x >= g->n || y < 0 || y >= g->n) {
        return ;
    }
    g->edges[x] = insert_node(g->edges[x], y);
    g->edges[y] = insert_node(g->edges[y], x);
}

void clear(Graph *g) {
    for (int i = 0; i < g->n; ++i) {
        Node *head = g->edges[i];
        while (head != NULL) {
            Node *delete_node = head;
            head = head->next;
            free(delete_node);
        }
    }
    free(g);
}

void dfs(Graph *g, int vertex) {
	printf("%d\n", vertex);
    g->visited[vertex] = 1;
    for (Node *adj = g->edges[vertex]; adj != NULL; adj = adj->next) {
		if (!g->visited[adj->vertex]) {
			dfs(g,adj->vertex);
        }
    }
}

int main() {
    int n, m, k;
    scanf("%d %d", &n, &m);
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    init(graph, n);
    for (int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        insert(graph, x, y);
    }
    scanf("%d", &k);
    dfs(graph, k);
    clear(graph);
    return 0;
}
