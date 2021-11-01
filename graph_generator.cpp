#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include "graph_generator.h"

graph_node::graph_node(int v, int w) : vertex(v), weight(w){};

graph_generator::
graph_generator(int avg_degree, int num_nodes) : avg_degree(avg_degree), num_nodes(num_nodes){

    for(int i=0;i<num_nodes;i++){
        for(int j=i+2;j<num_nodes;j++){
            unique_edges.push_back({i,j});
        }
    }
    random_shuffle(unique_edges.begin(), unique_edges.end());

    final_graph = new vector<vector<graph_node>>(num_nodes, vector<graph_node>());

}

float graph_generator::get_avg_degree(){
    return (float)2*current_edges/num_nodes;
}

void graph_generator::add_edge(int n1, int n2){
    int w=rand()%num_nodes;
    (*final_graph)[n1].push_back(graph_node (n2, w));
    (*final_graph)[n2].push_back(graph_node (n1, w));
    current_edges++;
}

vector<vector<graph_node>>* graph_generator::get_graph(){

    for(int i=0;i<num_nodes;i+=1){
        add_edge(i,(i+1)%(num_nodes-1));
    }

    for(int i=0;i<unique_edges.size();i++){
        add_edge(unique_edges[i][0],unique_edges[i][1]);
        if(get_avg_degree() >= avg_degree){
            break;
        }
    }

    return final_graph;
}

vector<vector<graph_node>>* get_graph(int degree, int num_nodes){

    graph_generator gh(degree, num_nodes);
    return gh.get_graph();
}


