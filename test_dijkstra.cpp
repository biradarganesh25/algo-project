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
int MAX_NODES=50;

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

    int n = test_graph.size();
    graph_node ** test_graph_final = new graph_node*[test_graph.size()];
    for(int i=0;i<n;i++){
        test_graph_final[i]=NULL;
    }
    for(int i=0;i<test_graph.size();i++){
        test_graph_final[i]=new graph_node(0,test_graph[i][0]);
        for(int j=1;j<test_graph[i].size();j++){
            auto temp = new graph_node(j, test_graph[i][j]);
            temp->next=test_graph_final[i];
            test_graph_final[i]=temp;
        }
    }

    vector<vector<int>> test_source_target={{0,8},{0,3}};
    vector<vector<int>> ans_paths={{0,7,8},{0,7,1,2,3}};

    DijkstraWithoutHeap djnoh(test_graph.size());
    for(int i=0;i<test_source_target.size();i++){
        auto v = test_source_target[i];
        result r = djnoh.find_max_bw_path(test_graph_final, v[0], v[1]);
        vector<int> path(r.path, r.path+r.length);
        cout << "ans_paths" << endl;
        printv(ans_paths[i]);
        cout << "actual_paths from running algo:" << endl;
        printv(path);
        if(!(path==ans_paths[i])){
            free(r.path);
            throw runtime_error("expected ans_path and ans_path from algo not equal!!");
        }
        else{
            cout<<"Test passed!!"<<endl;
        }
        free(r.path);
    }

    free(test_graph_final);
}
