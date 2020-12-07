#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> rightSideView(TreeNode *root)
{
    queue<TreeNode *> tq;
    if (root != NULL)
    {
        tq.push(root);
    }
    vector<int> res;
    while (!tq.empty())
    {
        //记录当前层的结点个数
        int size = tq.size();
        for (int i = 0; i < size; ++i)
        {
            TreeNode *node = tq.front();
            if (node->left != NULL)
            {
                tq.push(node->left);
            }
            if (node->right != NULL)
            {
                tq.push(node->right);
            }
            if(i == size - 1)
            {
                res.push_back(node->val);
            }
            tq.pop();
        }
    }
    return res;
}