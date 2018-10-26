/*************************************************************************
	> File Name: LeetCode_111_二叉树最小深度.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年10月26日 星期五 21时14分09秒
 ************************************************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int minDepth(struct TreeNode* root) {
    if (!root) return 0;
    int l = minDepth(root->left) + 1, r = minDepth(root->right) + 1;
    if (l == 1) return r;
    if (r == 1) return l;
    return l < r ? l : r; 
}
