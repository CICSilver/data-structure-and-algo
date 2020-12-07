#include <iostream>
#include <vector>
#include <queue>

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

// N叉树的层序遍历，和普通层序遍历是同一模型
vector<vector<int>> levelOrder(Node* root)
{
    queue<Node *> tq;
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
            Node *node = tq.front();
            for(auto const& n:node->children)
            {
                if(n != NULL)
                {
                    tq.push(n);
                }
            }
            val.push_back(node->val);
            tq.pop();
        }
        res.push_back(val);
    }
    return res;
}
