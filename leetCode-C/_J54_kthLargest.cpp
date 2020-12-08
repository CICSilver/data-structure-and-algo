#include <vector>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 二叉搜索树的第k大节点
// 1 ≤ k ≤ 二叉搜索树元素个数
int kthLargest(TreeNode *root, int k)
{
    if(root == NULL)
    {
        return 0;
    }
    vector<int> nums;
    inOrder(root, nums, k);

}

void inOrder(TreeNode *node, vector<int>& nums, int k)
{
    if(node == NULL)
    {
        return;
    }
    if(nums.size() == k)
    {
        return nums[nums.size() - 1];
    }
    nums.emplace_back()
}