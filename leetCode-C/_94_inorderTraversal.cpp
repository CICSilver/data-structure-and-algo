#include <vector>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> res;
    if (root == NULL)
    {
        return res;
    }
    stack<TreeNode *> stack;
    bool isRoot = true;
    if (root->right)
    {
        stack.push(root->right);
    }
    stack.push(root);
    if (root->left)
    {
        stack.push(root->left);
    }

    while (!stack.empty())
    {
        bool flag = false;
        TreeNode *node = stack.top();
        stack.pop();

        if (!node->left)
        {
            //最左子结点,同时弹出自身与父结点
            res.push_back(node->val);
            if (!isRoot)
            {
                res.push_back(stack.top()->val);
                stack.pop();
            }
            flag = true;
        }
        if (isRoot)
        {
            isRoot = false;
            continue;
        }
        if (node->right)
        {
            stack.push(node->right);
        }
        if (!flag)
        {
            stack.push(node);
            stack.push(node->left);
        }
    }

    return res;
}