#include <iostream>
#include "dijkstra.h"
#include "graph_generator.h"
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

DijkstraWithoutHeap::DijkstraWithoutHeap(int nodes) : nodes(nodes){
    status = (int *)malloc(sizeof(int)*nodes);
    cur_bw = (int *)malloc(sizeof(int)*nodes);
    parent = (int *)malloc(sizeof(int)*nodes);
}

int DijkstraWithoutHeap::get_node_fringe_max_bw(){
    int max_node = -1, max_weight=-1;
    for(int i=0;i<nodes;i++){
        if(status[i] == fringe && cur_bw[i]>max_weight){
            max_weight=cur_bw[i];
            max_node=i;
        }
    }

    return max_node;
}

result DijkstraWithoutHeap::find_max_bw_path(graph_node **gh, int s, int t){

    cur_bw[s]=std::numeric_limits<int>::max();
    status[s]=visited;
    nodes_seen=1;

    for(auto neigh=gh[s];neigh!=NULL;neigh=neigh->next){
        cur_bw[neigh->vertex]=neigh->weight;
        status[neigh->vertex]=fringe;
        parent[neigh->vertex]=s;
    }

    while (nodes_seen<nodes)
    {
        int max_node = get_node_fringe_max_bw();  
        status[max_node]=visited;

        if(max_node==t){
            break;
        }

        for(auto neigh_node=gh[max_node];neigh_node!=NULL;neigh_node=neigh_node->next){
            int neigh=neigh_node->vertex;
            int weight = neigh_node->weight;

            if(status[neigh]==unvisited){
                status[neigh]=fringe;
                cur_bw[neigh]=weight;
                parent[neigh]=max_node;
            }
            else if(status[neigh]==fringe){
                if(cur_bw[neigh]<min(cur_bw[max_node],weight)){
                    cur_bw[neigh]=min(cur_bw[max_node],weight);
                    parent[neigh]=max_node;
                }
            }
        }
    }

    if(status[t]==unvisited){
        throw runtime_error("Unexpected: could not find path from s to t");
    }

    int cur=t;
    int total_nodes=0;
    while(cur!=s){
        cur=parent[cur];
        total_nodes++;
    }
    total_nodes++;
    int *final_path = (int *)malloc(total_nodes*sizeof(int));
    int p=total_nodes-1;
    cur=t;
    while(cur!=s){
        final_path[p]=cur;
        p--;
        cur=parent[cur];
    }
    final_path[p]=cur;
    result r(final_path, total_nodes);

    return r;

}

result::result(int *path, int len):path(path),length(len){}


