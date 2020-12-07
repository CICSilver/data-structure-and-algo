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

// 二叉树的层平均值
vector<double> averageOfLevels(TreeNode *root)
{
    queue<TreeNode *> tq;
    if (root != NULL)
    {
        tq.push(root);
    }
    vector<double> res;
    while (!tq.empty())
    {
        //记录当前层的结点个数
        int size = tq.size();
        double sum = 0;
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
            sum += node->val;
            tq.pop();
        }
        res.push_back(sum / size);
    }
    return res;
}
