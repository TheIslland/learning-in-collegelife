/*************************************************************************
	> File Name: LeetCode_226_翻转二叉树.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年10月26日 星期五 22时04分59秒
 ************************************************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* invertTree(struct TreeNode* root) {
    if (!root) return root;
    struct TreeNode *temp = root->right;
    root->right = root->left;
    root->left = temp;
    invertTree(root->left);
    invertTree(root->right);
    return root;
}
