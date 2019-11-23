/************************************************************
    File Name : 107二叉树的层次遍历II.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2019-11-23 星期六 14:12:14
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
    vector<vector<int>> levels;
    void Sub_Node(TreeNode* root, int level) {
        if (!root) return;
        if (levels.size() == level) levels.push_back(vector<int>());
        levels[level].push_back(root->val);
        if (root->left != NULL) Sub_Node(root->left, level + 1);
        if (root->right != NULL) Sub_Node(root->right, level + 1);
        return ;
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root) return levels;
        Sub_Node(root, 0);
        reverse(levels.begin(), levels.end());
        return levels;
    }
};
int main() {
    
    return 0;
}