#include <bits/stdc++.h>
#include "graph_generator.cpp"

using namespace std;

int main(){
    int degree=6, num_nodes=10;
    complete_graph cg = get_graph(degree, num_nodes);
    vector<vector<int>> gh = (*cg.graph);

    int total_deg=0;
    vector<int> degrees(num_nodes);

    for(int node=0;node<num_nodes;node++){
        degrees[node]=gh[node].size();
        total_deg += degrees[node];
    }

    cout<<"Avg degree: "<<total_deg/num_nodes<<endl;
    cout<<"Degrees: "<<endl;
    for(int i=0;i<num_nodes;i++){
        cout<<degrees[i]<<" ";
    }
    cout<<endl;
    cout<<"Graph adj list: "<<endl;
    for(int i=0;i<num_nodes;i++){
        cout<<i<<": ";
        for(int neigh:gh[i]){
            cout<<neigh<<" ";
        }
    cout<<endl;
    }
}

