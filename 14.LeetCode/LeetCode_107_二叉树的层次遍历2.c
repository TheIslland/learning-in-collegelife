/*************************************************************************
	> File Name: LeetCode_107_二叉树的层次遍历2.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年10月26日 星期五 19时02分00秒
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

int getHight(struct TreeNode *root) {
    if (!root) return 0;
    int l = getHight(root->left), r = getHight(root->right);
    return (l > r ? l : r) + 1;
}

void getcolumnSizes(struct TreeNode *root, int *cols, int k) {
    if (!root) return ;
    cols[k]++;
    getcolumnSizes(root->left, cols, k + 1);
    getcolumnSizes(root->right, cols, k + 1);
    return ;
}

void getResult(struct TreeNode *root, int **ret, int *cols, int k) {
    if (!root) return ;
    ret[k][cols[k]++] = root->val;
    getResult(root->lfet, ret, cols, k - 1);
    getResult(root->right, ret, cols, k - 1);
    
    return ;
}

int** levelOrderBottom(struct TreeNode* root, int** columnSizes, int* returnSize) {
    *returnSize = getHight(root);
    *columnSizes = (int *)calloc(sizeof(int), (*returnSize));
    getcolumnSizes(root, *columnSizes, 0);
    int** ret = (int **)malloc(sizeof(int *) * (*returnSize));
    for (int i = 0; i < *returnSize; i++) {
        ret[i] = (int *)malloc(sizeof(int) * (*columnSizes)[*returnSize - i - 1]);
        (*columnSizes)[*returnSize - i - 1] = 0;
    }
    getResult(root, ret, *columnSizes, *returnSize - 1);
    return ret;
}

/*int getHight(struct TreeNode *root) {
    if (!root) return 0;
    int l = getHight(root->left), r = getHight(root->right);
    return (l > r ? l : r) + 1;
}

void getcolumnSizes(struct TreeNode *root, int *cols, int k) {
    if (!root) return ;
    cols[k]++;
    getcolumnSizes(root->left, cols, k - 1);
    getcolumnSizes(root->right, cols, k - 1);
    return ;
}

void getResult(struct TreeNode *root, int **ret, int *cols, int k) {
    if (!root) return ;
    ret[k][cols[k]++] = root->val;
    getResult(root->left, ret, cols, k - 1);
    getResult(root->right, ret, cols, k - 1);  
    return ;
}

int** levelOrderBottom(struct TreeNode* root, int** columnSizes, int* returnSize) {
    *returnSize = getHight(root);
    *columnSizes = (int *)calloc(sizeof(int),(*returnSize));
    getcolumnSizes(root, *columnSizes, *returnSize - 1);
    int** ret = (int **)malloc(sizeof(int *) * (*returnSize));
    for (int i = *returnSize - 1; i >= 0; i--) {
        ret[i] = (int *)malloc(sizeof(int) * (*columnSizes)[i]);
        (*columnSizes)[i] = 0;
    }
    getResult(root, ret, *columnSizes, *returnSize - 1);
    return ret;
}*/
