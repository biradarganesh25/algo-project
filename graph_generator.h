#ifndef GRAPHG_H
#define GRAPHG_H
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;



class graph_node{
    public:
    int vertex;
    int weight;
    graph_node *next;
    graph_node(int v, int w);
};

class graph_generator{
    private: 
    int avg_degree, num_nodes, current_edges=0;
    vector<vector<int>> unique_edges;
    graph_node **final_graph;

    public:

    graph_generator(int avg_degree, int num_nodes);  
    float get_avg_degree();
    void add_edge(int n1, int n2);
    graph_node** get_graph();
};


graph_node** get_graph(int degree, int num_nodes);


#endif