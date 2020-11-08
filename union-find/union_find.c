#include "union_find.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void union_init(int size)
{
    parent = (int *)calloc(size, sizeof(int));
    size_of_nodes = (int *)calloc(size, sizeof(int));
    for(int i = 0;i<size;i++)
    {
        size_of_nodes[i] = 1;
        parent[i] = i;
    }
    count = size;
}
void union_f(int a, int b)
{
    int root_a = find_root(a);
    int root_b = find_root(b);
    if(root_a != root_b)
    {
        //把小的树接到大的树后面，防止单链表型的极端树出现，保证树的大致平衡
        if(size_of_nodes[root_a] <= size_of_nodes[root_b])
        {
            parent[root_b] = root_a;
            size_of_nodes[root_b] += size_of_nodes[root_a];
        }else
        {
            parent[root_a] = root_b;
            size_of_nodes[root_a] += size_of_nodes[root_b];
        }
        count--;
    }
}
int find_root(int a)
{
    while(parent[a]!=a)
    {
        //缩短路径
        parent[a] = parent[parent[a]];
        a = parent[a];
    }
    return a;
}
int connected(int a, int b)
{
    int root_a = find_root(a);
    int root_b = find_root(b);
    return root_b == root_a;
}
int getCount()
{   
    return count;
}