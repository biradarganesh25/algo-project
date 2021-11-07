#include <iostream>
#include "dijkstra.h"
#include "graph_generator.h"
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

DijkstraWithoutHeap::DijkstraWithoutHeap(int nodes) : nodes(nodes){
    status.resize(nodes, unvisited);
    cur_bw.resize(nodes, -1);
    parent.resize(nodes,-1);
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
vector<int> * DijkstraWithoutHeap::find_max_bw_path(vector<vector<graph_node>> &gh, int s, int t){

    cur_bw[s]=std::numeric_limits<int>::max();
    status[s]=visited;
    nodes_seen=1;

    for(auto neigh:gh[s]){
        cur_bw[neigh.vertex]=neigh.weight;
        status[neigh.vertex]=fringe;
        parent[neigh.vertex]=s;
    }

    while (nodes_seen<nodes)
    {
        int max_node = get_node_fringe_max_bw();  
        status[max_node]=visited;

        if(max_node==t){
            break;
        }

        for(int j=0;j<gh[max_node].size();j++){
            int neigh=gh[max_node][j].vertex;
            int weight = gh[max_node][j].weight;

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

    vector<int>* path_ptr = new vector<int>();
    auto &path = *(path_ptr);

    int cur=t;
    while(cur!=s){
        path.push_back(cur);
        cur=parent[cur];
    }

    path.push_back(s);

    std::reverse(path.begin(),path.end());

    return path_ptr;

}


