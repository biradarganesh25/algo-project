#ifndef DJK_H
#define DJK_H
#include <vector>
#include "graph_generator.h"
extern int unvisited, visited, fringe;

class DijkstraWithoutHeap{
    private: 
    std::vector<int> status, cur_bw;
    int nodes_seen, nodes;
    vector<int> parent;
    public:

    DijkstraWithoutHeap(int nodes);

    int get_node_fringe_max_bw();
    vector<int> *find_max_bw_path(vector<vector<graph_node>> &gh, int s, int t);
};
#endif