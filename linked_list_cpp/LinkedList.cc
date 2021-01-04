#include "LinkedList.h"

template<typename T>
LinkedList<T>::LinkedList() {}

template<typename T>
LinkedList<T>::~LinkedList() {}

template<typename T>
LinkedList<T>::Node *LinkedList<T>::NodeAt(int pos)
{
    if (!isPosValid(pos))
    {
        return nullptr;
    }
    auto temp = head_;
    while (pos-- != 0)
    {
        temp = temp->next_;
    }
    return temp;
}

template<typename T>
void LinkedList<T>::InsertAt(int pos, int val)
{
    // 获取插入位置的前一个位置
    if (pos == 0)
    {
        auto temp = head_;
        head_ = new Node(val, temp);
        tail_ = head_;
        size_++;
        return;
    }
    auto temp = NodeAt(pos - 1);
    Node *node = temp->next_;
    temp->next_ = new Node(val, node);
    if (pos == size_)
    {
        tail_ = temp->next_;
    }
    size_++;
}

template<typename T>
void LinkedList<T>::DeleteAt(int pos)
{
    if (pos == 0)
    {
        auto temp = head_;
        head_ = head_->next_;
        temp->next_ = nullptr;
        delete temp;
        temp = nullptr;
    }
    else
    {
        auto prev = NodeAt(pos - 1);
        auto temp = prev->next_->next_;
        prev->next_->next_ = nullptr;
        delete prev->next_;
        prev->next_ = temp;
        if (pos == size_ - 1)
        {
            tail_ = prev;
        }
    }

    size_--;
}
template<typename T>
int LinkedList<T>::At(int pos)
{
    if (pos == size_)
    {
        return 0;
    }
    auto temp = NodeAt(pos);
    return temp->GetVal();
}

template<typename T>
void LinkedList<T>::Reverse()
{
    if (size_ <= 1)
    {
        return;
    }
    Node *prev = nullptr;
    auto cur = head_;
    auto next = cur->next_;

    int count = size_;
    auto temp = tail_;
    tail_ = head_;
    head_ = temp;
    while (count-- != 0)
    {
        next = cur->next_;
        cur->next_ = prev;
        prev = cur;
        cur = next;
    }
}