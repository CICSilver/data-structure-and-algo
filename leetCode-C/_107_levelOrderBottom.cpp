#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    /**
 * @brief 给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
 * 
 * 例如：
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * 返回其自底向上的层次遍历为：
 * 
 * [
 *   [15,7],
 *   [9,20],
 *   [3]
 * ]
 * @param root 
 * @return vector<vector<int>> 
 */
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        stack<vector<int>> stack;
        queue<TreeNode *> tq;
        if (root != NULL)
        {
            tq.push(root);
        }
        vector<vector<int>> res;
        while (!tq.empty())
        {
            //记录当前层的结点个数
            int size = tq.size();
            vector<int> val;
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
                val.push_back(node->val);
                tq.pop();
            }
            stack.push(val);
        }
        while(!stack.empty())
        {
            res.emplace_back(stack.top());
            stack.pop();
        }
        return res;
    }
};