#ifndef _UNION_FIND_H
#define _UNION_FIND_H

//记录每个结点的父结点
int *parent;
//记录连通分量
int count;
//记录每棵树的重量，即结点数
int *size_of_nodes;

//初始化并查集，所有结点全部独立
void union_init(int);
//连通两个结点
void union_f(int, int);
//返回root
int find_root(int);
//查看两个结点是否连通
int connected(int, int);
//查看根节点数,即连通分量
int getCount();

#endif