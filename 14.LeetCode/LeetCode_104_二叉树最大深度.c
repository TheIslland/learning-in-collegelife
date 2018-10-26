/*************************************************************************
	> File Name: LeetCode_104_二叉树最大深度.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年10月26日 星期五 18时54分03秒
 ************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    if (!root) return 0;
    int l = maxDepth(root->left), r = maxDepth(root->right);
    return (l > r ? l : r) + 1;
}
