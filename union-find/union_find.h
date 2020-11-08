#ifndef _UNION_FIND_H
#define _UNION_FIND_H

int *parent;
//记录连通分量
int count;

void union_init(int);
void union_f(int, int);
//返回root
int find_root(int);
int connected(int, int);
int getCount();

#endif