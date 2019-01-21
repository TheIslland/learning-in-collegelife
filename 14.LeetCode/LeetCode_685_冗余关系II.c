/*************************************************************************
	> File Name: LeetCode_685_冗余关系II.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月21日 星期一 11时09分53秒
 ************************************************************************/
typedef struct DisjointSet {
    int *father;
    int *rank;
    int cnt;
} DisjointSet;

DisjointSet *init(int n) {
    DisjointSet *s = (DisjointSet *)malloc(sizeof(DisjointSet));
    s->father = (int *)malloc(sizeof(int) * n);
    s->rank = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i) {
        s->father[i] = i;
        s->rank[i] = 1;
    }
    s->cnt = n - 1;
    return s;
}

void clear(DisjointSet *s) {
    if (s == NULL) return ;
    free(s->father);
    free(s->rank);
    free(s);
    return ;
}

int find(DisjointSet *s, int node) {
    if (s->father[node] == node) return node;
    s->father[node] = find(s, s->father[node]);
    return s->father[node];
}

int joint(DisjointSet *s, int node1, int node2) {
    int father1 = find(s, node1);
    int father2 = find(s, node2);
    if (father1 == father2) return 0;
    if (s->rank[father1] >= s->rank[father2]) {
        s->father[father2] = father1;
        s->rank[father1] += s->rank[father2];
    } else {
        s->father[father1] = father2;
        s->rank[father2] += s->rank[father1];    
    }
    s->cnt--;
    return 1;
}

int* findRedundantDirectedConnection(int** edges, int edgesRowSize, int edgesColSize, int* returnSize) {
    DisjointSet *set = init(edgesRowSize + 1);
    int *ans = (int *)calloc(sizeof(int), 2);
    int *count = (int *)calloc(sizeof(int), (edgesRowSize + 1));
    int flag = 0, temp = 1;
    *returnSize = 2;
    for (int i = 0; i < edgesRowSize; ++i) {
        if (count[edges[i][1]]) {
            flag = i;
            break;
        }
        count[edges[i][1]] = i + 1;
    }   
    if (flag) {
        for (int i = 0; i < edgesRowSize; ++i) {
            if (i == flag) continue;
            if (joint(set, edges[i][0], edges[i][1])) continue;
            temp = 0;
        }
        if (temp && set->cnt == 1) {
            ans[0] = edges[flag][0];
            ans[1] = edges[flag][1];
        } else {
            ans[0] = edges[count[edges[flag][1]] - 1][0];
            ans[1] = edges[count[edges[flag][1]] - 1][1];
        }
    } else {
        for (int i = 0; i < edgesRowSize; ++i) {
            if (joint(set, edges[i][0], edges[i][1])) continue;
            ans[0] = edges[i][0];
            ans[1] = edges[i][1];
        }
    }
    clear(set);
    return ans;
}
