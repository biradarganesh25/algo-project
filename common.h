#ifndef KRUSKAL_H
#define KRUSKAL_H

#include<iostream>

class edge{
    public:
    int u,v;
    int bandwidth;
    edge(int u, int v, int bw);
};

#endif