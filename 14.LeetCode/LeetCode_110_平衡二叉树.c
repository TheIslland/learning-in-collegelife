/*************************************************************************
	> File Name: LeetCode_110_平衡二叉树.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年10月26日 星期五 20时19分21秒
 ************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int getDepth(struct TreeNode *root) {
    if (!root) return 0;
    int l = getDepth(root->left);
    int r = getDepth(root->right);

}

bool isBalanced(struct TreeNode* root) {
    if (!root) return true;
    return __isBalanced(root->left, root->right);
}
