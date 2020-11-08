#include "union_find.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void union_init(int size)
{
    parent = (int *)calloc(size, sizeof(int));
    for(int i = 0;i<size;i++)
    {
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
        parent[root_b] = root_a;
        count--;
    }
}
int find_root(int a)
{
    while(parent[a]!=a)
    {
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