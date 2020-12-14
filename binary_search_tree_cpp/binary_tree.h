#ifndef _BINARY_TREE_H
#define _BINARY_TREE_H

#include <iostream>
#include <vector>
#include <iterator>

//二叉查找树
template <typename K, typename V>
class BinarySearchTree
{
private:
    class Node
    {
    private:
        K key;
        V val;
        Node *left;
        Node *right;
        //以该结点为根的子树中的结点总数
        int N;

    public:
        Node(K key, V val, int N) : key(key), val(val), N(N){};
        K GetKey()
        {
            return this->key;
        }
        V GetVal()
        {
            return this->val;
        }
        int GetN()
        {
            return this->N;
        }
        ~Node(){};

        friend class BinarySearchTree;
    };

    Node *root = nullptr;

    int Size(Node *node)
    {
        if (node == NULL)
        {
            return 0;
        }
        else
        {
            return node->N;
        }
    }
    //在n为根的子树中查找key
    V Get(Node *n, K key)
    {
        if (n == nullptr)
        {
            return nullptr;
        }
        if (key < n->key)
        {
            return Get(n->left, key);
        }
        else if (key > n->key)
        {
            return Get(n->right, key);
        }
        return n->val;
    }
    //在n为根的子树中查找key,找到则更新，否则插入新结点
    Node *Put(Node *n, K key, V val)
    {
        if (n == nullptr)
        {
            return new Node(key, val, 1);
        }
        if (key < n->key)
        {
            n->left = Put(n->left, key, val);
        }
        else if (key > n->key)
        {
            n->right = Put(n->right, key, val);
        }
        else
        {
            n->val = val;
        }
        n->N = Size(n->left) + Size(n->right) + 1;
        return n;
    }

    std::vector<Node *> InorderTraversal(Node *node, std::vector<Node *> &res)
    {
        if (node == nullptr)
        {
            return res;
        }
        InorderTraversal(node->left, res);
        res.emplace_back(node);
        InorderTraversal(node->right, res);

        return res;
    }

    std::vector<Node *> PreorderTraversal(Node *node, std::vector<Node *> &res)
    {
        if (node == nullptr)
        {
            return res;
        }
        res.emplace_back(node);
        PreorderTraversal(node->left, res);
        PreorderTraversal(node->right, res);

        return res;
    }

    std::vector<Node *> PostorderTraversal(Node *node, std::vector<Node *> &res)
    {
        if (node == nullptr)
        {
            return res;
        }
        PostorderTraversal(node->left, res);
        PostorderTraversal(node->right, res);
        res.emplace_back(node);

        return res;
    }

    Node *Min(Node *node)
    {
        if (node == nullptr)
        {
            return nullptr;
        }
        if (node->left)
        {
            return Min(node->left);
        }
        return node;
    }

    Node *Max(Node *node)
    {
        if (node == nullptr)
        {
            return nullptr;
        }
        if (node->right)
        {
            return Max(node->right);
        }
        return node;
    }

    //从node开始往下找，找到第一个小于等于key的node返回
    Node *Floor(K key, Node *node)
    {
        if (node == nullptr)
        {
            return nullptr;
        }
        if (node->key <= key)
        {
            return node;
        }
        else
        {
            return Floor(key, node->left);
        }
    }

    Node *Ceilling(K key, Node *node)
    {
        if (node == nullptr)
        {
            return nullptr;
        }
        if (node->key >= key)
        {
            return node;
        }
        else
        {
            return Floor(key, node->right);
        }
    }

public:
    BinarySearchTree(){};
    BinarySearchTree(BinarySearchTree<K, V> *tree){};
    ~BinarySearchTree(){};

    int Size()
    {
        return Size(root);
    }

    V Get(K key)
    {
        return Get(root, key);
    }
    void Put(K key, V val)
    {
        root = Put(root, key, val);
    }

    std::vector<Node *> InorderTraversal()
    {
        std::vector<Node *> res;
        return InorderTraversal(root, res);
    }

    std::vector<Node *> PreorderTraversal()
    {
        std::vector<Node *> res;
        return PreorderTraversal(root, res);
    }

    std::vector<Node *> PostorderTraversal()
    {
        std::vector<Node *> res;
        return PostorderTraversal(root, res);
    }

    Node *Min()
    {
        return Min(root);
    }
    Node *Max()
    {
        return Max(root);
    }
    //向下取整
    Node *Floor(K key)
    {
        return Floor(key, root);
    }
    //向上取整
    Node *Ceilling(K key)
    {
        return Ceilling(key, root);
    }
};

#endif