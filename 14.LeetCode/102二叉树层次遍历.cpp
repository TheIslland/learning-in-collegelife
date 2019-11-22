/************************************************************
    File Name : 102二叉树层次遍历.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2019-11-21 星期四 19:24:31
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>

using namespace std;
/**
 * Definition for a binary tree node.
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
   public:
    vector<int> Sub_Node(TreeNode *root) {
        vector<int> v;
        vector<>
    }
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> v;
        vector<int> temp;
        temp.push_back(root->val);
        v.push_back(vector<int>(root->val));
        temp.
    }
};
int main() { return 0; }