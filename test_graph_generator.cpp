#include <bits/stdc++.h>
#include "graph_generator.h"

using namespace std;

int main(){
    int degree=6, num_nodes=10;
    graph_node** gh= (get_graph(degree, num_nodes));


    int total_deg=0;
    vector<int> degrees(num_nodes);

    for(int i=0;i<num_nodes;i++){
        cout<<i<<":: ";
        degrees[i]=0;
        for(auto j=gh[i];j!=NULL;j=j->next){
            degrees[i]++;
            cout<<"v: "<<j->vertex<<":w"<<j->weight<<" ";
        }
        total_deg+=degrees[i];
        cout<<" degree: "<<degrees[i];
        cout<<endl;
    }
    cout<<"Avg degree: "<<total_deg/num_nodes<<endl;
}

