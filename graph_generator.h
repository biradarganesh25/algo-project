#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;


int sparse_graph_avg_degree = 6;

class graph_generator{
    private: 
    int avg_degree, num_nodes, current_edges=0;
    vector<vector<int>> unique_edges;
    vector<vector<int>>* final_graph;

    public:

    graph_generator(int avg_degree, int num_nodes) : avg_degree(avg_degree), num_nodes(num_nodes){

        for(int i=0;i<num_nodes;i++){
            for(int j=i+2;j<num_nodes;j++){
                unique_edges.push_back({i,j});
            }
        }
        random_shuffle(unique_edges.begin(), unique_edges.end());

        final_graph = new vector<vector<int>>(num_nodes, vector<int>());

    }

    float get_avg_degree(){
        return (float)current_edges/num_nodes;
    }

    void add_edge(int n1, int n2){
        (*final_graph)[n1].push_back(n2);
        (*final_graph)[n2].push_back(n1);
        current_edges++;
    }

    vector<vector<int>>* get_graph(){

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

    vector<int>* get_weights(){
        vector<int> * weights = new vector<int> (num_nodes,0);
        for(int i=0;i<num_nodes;i++){
            (*weights)[i] = rand()%num_nodes;
        }

        return weights;
    }

};

struct complete_graph{
    vector<vector<int>>* graph;
    vector<int> *weights;
};

complete_graph get_graph(int degree, int num_nodes){
    graph_generator gh(degree, num_nodes);
    complete_graph cg;
    cg.graph = gh.get_graph();
    cg.weights = gh.get_weights();

    return cg;
}

