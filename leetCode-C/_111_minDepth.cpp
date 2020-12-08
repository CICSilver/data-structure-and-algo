#include <iostream>
#include <queue>
#include <vector>

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

/**
 * 给定一个二叉树，找出其最小深度。
 * 
 * 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
 * 
 * 说明：叶子节点是指没有子节点的节点。
 * 
 * @param root 
 * @return int 
 */
#define MIN(a, b) a < b ? a : b
int minDepth(TreeNode *root)
{
    int res = 0;
    if (root == nullptr)
    {
        return res;
    }
    int leftDepth = minDepth(root->left);
    int rightDepth = minDepth(root->right);
    //若左子树为空则为右子树最小结点高度+1，反之相同
    if (leftDepth == 0)
    {
        res = rightDepth + 1;
    }
    else if (rightDepth == 0)
    {
        res = leftDepth + 1;
    }
    else
    {
        res = MIN(rightDepth, leftDepth);
        ++res;
    }
    return res;
}

int minDepth_nr(TreeNode *root)
{
    queue<TreeNode *> tq;
    if(root == NULL)
    {
        return 0;
    }
    tq.push(root);
    int depth = 0;
    while (!tq.empty())
    {
        int size = tq.size();
        depth++;
        for (int i = 0; i < size; ++i)
        {
            TreeNode *node = tq.front();
            if(node->left)
            {
                tq.push(node->left);
            }
            if(node->right)
            {
                tq.push(node->right);
            }
            if(!node->left && !node->right)
            {
                return depth;
            }
            tq.pop();
        }
    }
    return depth;
}