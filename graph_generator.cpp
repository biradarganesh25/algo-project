#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include "graph_generator.h"

graph_node::graph_node(int v, int w) : vertex(v), weight(w){
    next=NULL;
};

graph_generator::
graph_generator(int avg_degree, int num_nodes) : avg_degree(avg_degree), num_nodes(num_nodes){

    for(int i=0;i<num_nodes;i++){
        for(int j=i+2;j<num_nodes;j++){
            unique_edges.push_back({i,j});
        }
    }
    random_shuffle(unique_edges.begin(), unique_edges.end());

    final_graph = (graph_node **)malloc(num_nodes*(sizeof(graph_node*)));
    for(int i=0;i<num_nodes;i++){
        final_graph[i]=NULL;
    }

}

float graph_generator::get_avg_degree(){
    return (float)2*current_edges/num_nodes;
}

void graph_generator::add_edge(int n1, int n2){
    int w=rand()%num_nodes;
    if((final_graph)[n1]==NULL){
        (final_graph)[n1]=new graph_node(n2, w);
    }
    else{
        auto temp=new graph_node(n2,w);
        temp->next=(final_graph)[n1];
        (final_graph)[n1]=temp;
    }
    if((final_graph)[n2]==NULL){
        (final_graph)[n2]=new graph_node(n1,w);
    }
    else{
        auto temp = new graph_node(n1,w);
        temp->next=(final_graph)[n1];
        (final_graph)[n1]=temp;
    }
    current_edges++;
}

graph_node** graph_generator::get_graph(){

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

graph_node** get_graph(int degree, int num_nodes){

    graph_generator gh(degree, num_nodes);
    return gh.get_graph();
}


