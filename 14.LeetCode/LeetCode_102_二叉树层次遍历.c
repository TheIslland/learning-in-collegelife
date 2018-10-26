/*************************************************************************
	> File Name: LeetCode_102.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年10月25日 星期四 19时21分05秒
 ************************************************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int getHight(struct TreeNode  *root) {
    //获取树深，当树为空时返回０
    if (!root) return 0;
    //递归调用左右子树获取深度
    int l = getHight(root->left), r = getHight(root->right);
    //取最深的一侧为原树深度，每一层加１
    return (l >r ? l: r) + 1;
}

//
void getColumns(struct TreeNode *root, int *cols, int k) {
    //判断第ｋ层是否为空，空则返回空，该层内元素个数不增加
    if(!root)return;　
    //第ｋ层内有元素，ｋ层总元素个数增加
        cols[k] += 1;
    //检查左右子树
        getColumns(root->left, cols, k + 1);
        getColumns(root->right, cols, k + 1);
        return ;
}

void  getResult(struct TreeNode *root, int **ret, int *cols, int k) {
    if (!root) return ;
    //传出参数的ｒｅｔ和传出参数ｃｏｌｓ的参数不断按层更新
    ret[k][cols[k]++] = root->val;
    getResult(root->left, ret, cols, k + 1);
    getResult(root->right, ret, cols, k + 1);
    return ;
}

//columnSizes　和returnSize是传出参数
int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
    *returnSize = getHight(root);
    //初始化了二维数组的第一行
    *columnSizes = (int *)calloc(sizeof(int), *returnSize);
    getColumns(root, *columnSizes, 0);
    int **ret = (int **)malloc(sizeof(int *) * (*returnSize));
    for(int i = 0; i < *returnSize; i++) {
//(*columnSizes)[i]是数组指针
        ret[i] = (int *)malloc(sizeof(int ) * (*columnSizes)[i]);
//将第一行同一行上的第ｉ列值为０
        (*columnSizes)[i] = 0;   
    }
    getResult(root, ret, *columnSizes, 0);
    return ret;
}
