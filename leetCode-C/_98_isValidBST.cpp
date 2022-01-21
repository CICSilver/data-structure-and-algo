#include <iostream>
#include <climits>

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
bool helper(TreeNode *root, long lower, long upper);
bool isValidBST(TreeNode *root)
{
    return helper(root, LONG_MIN, LONG_MAX);
}

bool helper(TreeNode *root, long lower, long upper)
{
    // 退出条件:
    // 1.当前节点为空,则当前子树验证完毕
    if (root == nullptr)
    {
        return true;
    }

    // 2.判断当前root值是否合法
    if (root->val <= lower || root->val >= upper)
    {
        return false;
    }

    return helper(root->left, lower, root->val) && helper(root->right, root->val, upper);
}

int main(int argc, char *argv[])
{
    // auto node1 = new TreeNode(1);
    auto node2 = new TreeNode(1);
    auto root = new TreeNode(1, nullptr, node2);

    // cout << node2->right->val << endl;
    auto res = isValidBST(root);
    cout << "value = " << res << endl;
    return 0;
}