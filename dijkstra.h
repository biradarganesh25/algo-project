#ifndef DJK_H
#define DJK_H
#include <vector>
#include "graph_generator.h"
extern int unvisited, visited, fringe;


class result{
    public:
    int *path;
    int length;
    result(int *path, int len);
};

class DijkstraWithoutHeap{
    private: 
    int *status, *cur_bw, *parent;
    int nodes_seen, nodes;
    public:

    DijkstraWithoutHeap(int nodes);

    int get_node_fringe_max_bw();
    result find_max_bw_path(graph_node **gh, int s, int t);
};
#endif