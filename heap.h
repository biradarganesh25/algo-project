#ifndef HEAP_H
#define HEAP_H

#include<vector>

extern int MAX_NODES;

class Myheap{

    private: 
    int *node_to_indx;
    int *indx_to_node;
    int *heap_array;
    int size=0;
    void fix_heap_up(int i);
    void fix_heap_down(int i);

    public: 
    Myheap();
    ~Myheap();
    void insert(int node, int bandwidth);
    void remove(int node);
    int get_max_bandwidth_node();
    int get_size();
    // void reset();

    // for debugging
    void verify_heap_array(std::vector<int>&test_heap_array, int test_size);
    void verify_indx_to_node_array(std::vector<int> &test_indx_to_node_array, int test_size);
    void verify_node_to_indx_array(std::vector<int> &test_node_to_indx_array, int test_size);
    void print_heap_array();
};

#endif