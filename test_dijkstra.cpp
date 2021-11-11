#include <bits/stdc++.h>
#include "dijkstra.h"
#include "graph_generator.h"

using namespace std;

void printv(vector<int> &v){
    for(int i:v){
        cout<<i<<" ";
    }
    cout<<endl;
}

int unvisited=0, visited=1, fringe=2;

int main(){
    vector<vector<int>> test_graph={
        { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } 
        };

    vector<vector<graph_node>> test_graph_final (9,vector<graph_node>());
    for(int i=0;i<test_graph.size();i++){
        for(int j=0;j<test_graph[i].size();j++){
            test_graph_final[i].push_back(graph_node(j,test_graph[i][j]));
        }
    }

    vector<vector<int>> test_source_target={{0,8},{0,3}};
    vector<vector<int>> ans_paths={{0,7,8},{0,7,1,2,3}};

    DijkstraWithoutHeap djnoh(test_graph.size());
    for(int i=0;i<test_source_target.size();i++){
        auto v = test_source_target[i];
        vector<int> *p = djnoh.find_max_bw_path(test_graph_final, v[0], v[1]);
        cout << "ans_paths" << endl;
        printv(ans_paths[i]);
        cout << "actual_paths from running algo:" << endl;
        printv(*p);
        if(!((*p)==ans_paths[i])){
            free(p);
            throw runtime_error("expected ans_path and ans_path from algo not equal!!");
        }
        else{
            cout<<"Test passed!!"<<endl;
        }
        free(p);
    }
}
