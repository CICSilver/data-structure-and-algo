#include "binary_tree.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<int> nums = {5, 3, 0, 9, 6, 7};
    vector<string> names = {"aaa", "bbb", "ccc", "ddd", "eeee", "fff"};
    BinarySearchTree<int, string> tree;
    for (int i = 0; i < nums.size();++i)
    {
        tree.Put(nums[i], names[i]);
    }

    /*      Traversals      */
    // auto res = tree.PreorderTraversal();
    // cout << "====================== PreorderTraversal ======================" << endl;
    // for (auto const &n : res)
    // {
    //     cout << n->GetKey() << " : " << n->GetVal() << endl;
    // }
    cout << "====================== InorderTraversal ======================" << endl;
    auto res1 = tree.InorderTraversal();
    for (auto const &n : res1)
    {
        cout << n->GetKey() << " : " << n->GetVal() << ", N = " << n->GetN() << endl;
    }
    // cout << "====================== PostorderTraversal ======================" << endl;
    // auto res2 = tree.PostorderTraversal();
    // for (auto const &n : res2)
    // {
    //     cout << n->GetKey() << " : " << n->GetVal() << endl;
    // }


    /*      Min & Max     */
    // auto res3 = tree.Min();
    // cout << res3->GetKey() << " : " << res3->GetVal() << endl;
    // auto res4 = tree.Max();
    // cout << res4->GetKey() << " : " << res4->GetVal() << endl;

    /*      Floor & Cellint     */

    // auto res5 = tree.Floor(4);
    // cout << res5->GetKey() << " : " << res5->GetVal() << endl;
    // auto res6 = tree.Ceilling(4);
    // cout << res6->GetKey() << " : " << res6->GetVal() << endl;

    for (auto it = nums.begin(); it != nums.end(); ++it)
    {
        cout << *it << endl;
    }
}