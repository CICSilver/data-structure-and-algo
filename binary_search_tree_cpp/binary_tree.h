#ifndef _BINARY_TREE_H
#define _BINARY_TREE_H
#include "node.h"
#include <vector>
//二叉查找树
template<typename T>
class BinarySearchTree
{
private:
    node<T> *root;
    int height = 0;


public:
    BinarySearchTree() : root(nullptr) { };
    ~BinarySearchTree(){};

    //获取树高度
    int GetHeight();
    //获取结点深度
    int GetDepth(node* node);

    //递归的前中后序遍历
    std::vector<T> PreOrder_r();
    std::vector<T> InOrder_r();
    std::vector<T> LastOrder_r();
    //非递归的前中后序遍历
    std::vector<T> PreOrder_nr();
    std::vector<T> InOrder_nr();
    std::vector<T> LastOrder_nr();

    

};

#endif