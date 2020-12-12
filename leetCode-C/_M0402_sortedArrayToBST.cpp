#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode *Insert(int left, int right, vector<int> &nums);
TreeNode *sortedArrayToBST(vector<int> &nums);

TreeNode *sortedArrayToBST(vector<int> &nums)
{
    int left = 0;
    int right = nums.size();
    TreeNode *root;
    root = Insert(left, right, nums);

    return root;
}

TreeNode *Insert(int left, int right, vector<int> &nums)
{
    if (left == right)
    {
        return NULL;
    }
    int mid = left + (right - left) / 2;
    TreeNode *node = new TreeNode(nums[mid]);
    // cout << nums[mid] << endl;
    node->left = Insert(left, mid, nums);
    node->right = Insert(mid + 1, right, nums);

    return node;
}

vector<TreeNode *> InoderTraversal(TreeNode *root, vector<TreeNode *> &res)
{
    if (root == NULL)
    {
        return res;
    }
    InoderTraversal(root->left, res);
    res.push_back(root);
    InoderTraversal(root->right, res);

    return res;
}

int main()
{
    vector<int> nums = {-10, -3, 0, 5, 9};
    TreeNode *root = sortedArrayToBST(nums);
    vector<TreeNode *> res;
    InoderTraversal(root, res);

    for (auto const &n : res)
    {
        cout << n->val << endl;
    }
}