#include <vector>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

/**
 * @brief N叉树的前序遍历
 * 
 * @param root 
 * @return vector<int> 
 */
vector<int> preorder(Node *root)
{
    vector<int> res;
    func(root, res);
}

void func(Node *root, vector<int> res)
{
    if (root == NULL)
    {
        return;
    }
    res.push_back(root->val);
    for(auto const& n:root->children)
    {
        func(n, res);
    }
}
