/************************************************************
    File Name : 101对称的树.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2019-11-21 星期四 19:02:04
************************************************************/
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>

using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool cmp_tree(TreeNode *p, TreeNode *q) {
        if (!p && !q) return true;
        if ((!p && q) || (p && !q)) return false;
        if (p->val != q->val) return false;
        return cmp_tree(p->left, q->right) && cmp_tree(p->right, q->left);
    }
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return cmp_tree(root->left, root->right);
    }
};
int main() {
    
    return 0;
}