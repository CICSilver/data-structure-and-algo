#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H
#include <vector>
#include <string>
#include <algorithm>

class LinkedList
{
public:
    LinkedList(const std::vector<int> vector);
    LinkedList(const std::string str);
    LinkedList(const LinkedList &LinkedList)
    {
    }
    LinkedList();
    ~LinkedList();

    void InsertAt(int pos, int val);
    void DeleteAt(int pos);
    int At(int pos);
    // 倒置整个链表
    void Reverse();

    // 尾后插入
    void PushBack(int val)
    {
        InsertAt(size_, val);
    }
    // 头前插入
    void PushFront(int val)
    {
        InsertAt(0, val);
    }
    // 丢弃最后一个结点
    void PopBack()
    {
        return DeleteAt(size_ - 1);
    }
    // 丢弃最前一个结点
    void PopFront()
    {
        return DeleteAt(0);
    }
    // 返回链表长度
    int Size()
    {
        return size_;
    }
    // 判断链表是否为空
    bool Empty()
    {
        return size_ == 0;
    }
    // 查看第一个元素
    int Front()
    {
        return head_->GetVal();
    }
    // 查看末尾元素
    int Back()
    {
        return tail_->GetVal();
    }

private:
    class Node
    {
    public:
        Node(int val = 0, Node *next = nullptr) : val_(val), next_(next){};
        Node(const Node &node) : val_(0)
        {
            Node temp(node.val_, node.next_);
            std::swap(this->val_, temp.val_);
            std::swap(this->next_, temp.next_);
        }
        ~Node()
        {
            delete next_;
            next_ = nullptr;
        };
        int GetVal()
        {
            return this->val_;
        }
        Node *GetNext()
        {
            return this->next_;
        }
        int SetNext(Node *);

    private:
        int val_;
        Node *next_ = nullptr;
        friend class LinkedList;
    };
    Node *head_ = nullptr;
    Node *tail_ = nullptr;
    int size_ = 0;

    // 判断位置是否有效
    bool isPosValid(int pos)
    {
        return pos >= 0 && pos <= size_;
    }
    Node *NodeAt(int pos);
};

#endif