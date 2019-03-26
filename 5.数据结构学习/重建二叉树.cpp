/*************************************************************************
	> File Name: 重建二叉树.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年03月26日 星期二 18时58分03秒
 ************************************************************************/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*关于重建二叉树，我们使用前序遍历与中序遍历建树时，根据前序遍历根左右的输出顺序，与中序遍历左根右的输出顺序
  得知，前序遍历的首位置为根节点，后接左子树与右子树,但区间不明确，故我们需要划分区间，中序遍历的根节点左部分为左子树，
  根节点右部分右子树，所以当我们在中序遍历中获取到根节点位置即可划分左右子树
  故我们在前序遍历中获取根节点后在中序遍历中寻找其位置的过程中同步划分前序遍历的左子树与中序遍历左子树，
  根节点位置找到后我们就得知了前序遍历左子树与右子树区间，与中序遍历的左子树与右子树，
  我们将前序遍历的左子树与中序遍历的左子树递归重复此过程，右子树同理，故重建二叉树
*/
class Solution {
public:
    TreeNode *build(vector<int> &pre, vector<int> &vin, int i, int j, int k, int l) {
        if(j < i) return nullptr;
        TreeNode *root = new TreeNode(pre[i]);
        int di = i + 1, dj = i + 1, dk = k, dl = k;;
        while(vin[dl] != pre[i]) dl += 1, dj += 1;
        dl -= 1, dj -= 1;
        root->left = build(pre, vin, di, dj, dk, dl);
        di = dj + 1; dj = j; dk = dl + 2; dl = l;
        root->right = build(pre, vin, di, dj, dk, dl);
        return root;
    }
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        return build(pre, vin, 0, pre.size() - 1, 0, vin.size() - 1);
        
    }
};
