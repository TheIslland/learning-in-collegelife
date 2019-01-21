/*************************************************************************
	> File Name: LeetCode_685_冗余关系II.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月21日 星期一 14时54分59秒
 ************************************************************************/

int root(int* parent, int k) {
  if (parent[k] != k)
    parent[k] = root(parent, parent[k]);
  return parent[k];
}
int* findRedundantDirectedConnection(int** edges, int edgesRowSize, int edgesColSize, int* returnSize) {
  int* parent = (int*)calloc(sizeof(int), edgesRowSize + 1);
  int candA[2] = { 0,0 }, candB[2] = { 0,0 };
  int *result = (int*)malloc(sizeof(int) * 2);
  // step 1, check whether there is a node with two parents
  for (int i = 0; i < edgesRowSize; i++) {
    if (parent[edges[i][1]] == 0)
      parent[edges[i][1]] = edges[i][0];
    else {
      candA[0] = parent[edges[i][1]];
      candA[1] = edges[i][1];
      candB[0] = edges[i][0];
      candB[1] = edges[i][1];
      edges[i][1] = 0;
    }
  }
  // step 2, union find
  for (int i = 1; i <= edgesRowSize; i++)
    parent[i] = i;

  *returnSize = 2;
  for (int i = 0; i < edgesRowSize; i++) {
    if (edges[i][1] == 0)
      continue;
    int u = edges[i][0], v = edges[i][1], pu = root(parent, u);
    // Now every node only has 1 parent, so root of v is implicitly v
    if (pu == v) {
      if (candA[0] == 0 && candA[1] == 0) {
        result[0] = edges[i][0];
        result[1] = edges[i][1];
        return result;
      }
      else {
        result[0] = candA[0];
        result[1] = candA[1];
        return result;
      }
    }

    parent[v] = pu;
  }
  result[0] = candB[0];
  result[1] = candB[1];
  return result;
}
