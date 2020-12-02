#include <iostream>
#include <cmath>

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
 * 给定一个二叉树，判断它是否是高度平衡的二叉树。
 * 
 * 本题中，一棵高度平衡二叉树定义为：
 * 
 * 一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。
 * 
 * 思路：
 * 注:不平衡的情况分为三种，左子树不平衡、右子树不平衡、左右子树的高度差值大于1  
 * 三者分别进行判断即可
 * 
 *      1
 *     2    3
 *   4  5  6  
 * 8
 * @param root 
 * @return true 
 * @return false 
 */
struct res
{
    bool isBalanced;
    int depth;
    bool isDone = false;
    res() : isBalanced(true), depth(0) {}
    res(int depth) : isBalanced(true), depth(depth) {}
    res(bool isB, int depth, bool isDone) : isBalanced(isB), depth(depth), isDone(isDone) {}
};
bool isBalanced(TreeNode *root)
{
    return isBalanced(root, 0).isBalanced;
}

res isBalanced(TreeNode *root, int depth)
{
    // 判断是否为空结点
    if (root == NULL)
    {
        return res(depth);
    }
    //分别对两个子树进行平衡性判断
    res l = isBalanced(root->left, depth);
    res r = isBalanced(root->right, depth);
    if (l.isDone || r.isDone)
    {
        return res(false, depth, true);
    }
    //判断三种情况，若满足任何一种则不平衡
    if (!l.isBalanced || !r.isBalanced || abs(l.depth - r.depth) > 1)
    {
        return res(false, depth, true);
    }
    int cur_depth = l.depth > r.depth ? l.depth : r.depth;
    return res(cur_depth + 1);
}