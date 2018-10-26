/*************************************************************************
	> File Name: LeetCode_101_对称的二叉树.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年10月26日 星期五 16时25分22秒
 ************************************************************************/
 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 bool __isSymmetric(struct TreeNode *p, struct TreeNode *q) {
     //在相等时不断递归直到叶子节点都一致后
     if (!p && !q) return true;
     if (!p && q) return false;
     if (p && !q) return false;
     if (p->val != q->val) return false;
     //那么原树的左子树的左子树应该和原树的右子树的右子树相等且原树左子树的右子树应该和原树右子树的左子树相等
     return __isSymmetric(p->left, q->right) && __isSymmetric(p->right, q->left);
 }

bool isSymmetric(struct TreeNode* root) {
    //如果树为空无所谓镜不镜像都对
    if (!root) return true;
    //如果树不为空则树的左子树应和右子树一致
    return __isSymmetric(root->left, root->right);
}
