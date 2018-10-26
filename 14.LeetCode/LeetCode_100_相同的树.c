/*************************************************************************
	> File Name: LeetCode_100_相同的树.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年10月26日 星期五 16时15分05秒
 ************************************************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    //如果树ｐ和树ｑ都为空则一致
    if (!p && !q) return true;
    //如果ｐ不为空ｑ为空则不一致
    if (!p && q) return false;
    //反之亦然
    if (p && !q) return false;
    //在ｐｑ都存在时值不相等，则树不一致
    if (p->val != q->val) return false;
    //如两树相等则两树的左子树和右子树也相等
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
