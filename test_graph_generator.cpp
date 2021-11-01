#include <bits/stdc++.h>
#include "graph_generator.h"

using namespace std;

int main(){
    int degree=6, num_nodes=10;
    vector<vector<graph_node>>* gh_ptr= (get_graph(degree, num_nodes));
    vector<vector<graph_node>>& gh= *(gh_ptr);


    int total_deg=0;
    vector<int> degrees(num_nodes);

    for(int node=0;node<num_nodes;node++){
        degrees[node]=gh[node].size();
        total_deg += degrees[node];
    }

    cout<<"Avg degree: "<<total_deg/num_nodes<<endl;
    cout<<"Degrees: "<<endl;
    for(int i=0;i<num_nodes;i++){
        cout<<i<<":: ";
        for(int j=0;j<gh[i].size();j++){
            cout<<gh[i][j].vertex<<":w"<<gh[i][j].weight<<" ";
        }
        cout<<endl;
    }
    // cout<<endl;
    // cout<<"Graph adj list: "<<endl;
    // for(int i=0;i<num_nodes;i++){
    //     cout<<i<<": ";
    //     for(int neigh:gh[i]){
    //         cout<<neigh<<" ";
    //     }
    // cout<<endl;
    // }
}

