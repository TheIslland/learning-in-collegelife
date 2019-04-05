/*************************************************************************
	> File Name: unique_ptr中序遍历.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年04月05日 星期五 11时55分03秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <memory>

using namespace std;

struct Tree
{
    int data;
    unique_ptr<Tree> left;
    unique_ptr<Tree> right;

    Tree(int theData, unique_ptr<Tree> theLeft = nullptr, unique_ptr<Tree> theRight = nullptr)
        :data{ theData }
        , left{ theLeft.release() }
        , right{ theRight.release() }
    {
    }
};

unique_ptr<Tree> MakeTree()
{
    return make_unique<Tree>(1
        , make_unique<Tree>(2
            , make_unique<Tree>(4)
            , nullptr
            )
        , make_unique<Tree>(3
            , make_unique<Tree>(5)
            , make_unique<Tree>(6)
            )
        );
}

void PrintTree(const unique_ptr<Tree>& tree)
{
    if (tree->left) {
		PrintTree(tree->left);
    }
    cout << tree->data << " ";
    if (tree->right) {
		PrintTree(tree->right);
    }
}

int main()
{
    auto tree = MakeTree();
    PrintTree(tree);
    return 0;
}
