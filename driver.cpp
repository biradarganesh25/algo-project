// #include <bits/stdc++.h>
#include <ctime>
#include <iostream>
#include "dijkstra.h"
#include "graph_generator.h"
#include "kruskal.h"
#include "common.h"

using namespace std;

int unvisited=0, visited=1, fringe=2;
int MAX_NODES=5000;

void print_info(int s, int t, result r){

    cout<<"Source: "<<s<<" Target: "<<t<<endl;
    cout<<"######################"<<endl;
    for(int i=0;i<r.length;i++){
        cout<<r.path[i]<<" ";
    }
    cout<<endl;
    cout<<"######################"<<endl;
}

void run_algos(graph_node **gh, edge** edges, int num_edges){
    srand(time(NULL));
    for(int i=0;i<5;i++){
        cout<<i<<"th iteration of source & target"<<endl;
        int s = rand() % MAX_NODES;
        int t = rand() % MAX_NODES;
        cout<<"source: "<<s<<"target: "<<t<<endl;
        
        clock_t t1;
        result r;
        float time_taken;
        t1 = clock();
        DijkstraWithoutHeap *dj_noh = new DijkstraWithoutHeap(MAX_NODES);
        r = dj_noh->find_max_bw_path(gh, s, t);
        time_taken = float(clock()-t1)/CLOCKS_PER_SEC;
        cout<<"Dijkstra without heap time taken is: "<<time_taken<<endl;
        print_info(s,t,r);
        free(r.path);
        delete dj_noh;

        t1 = clock();
        DijkstraWithHeap *dj = new DijkstraWithHeap(MAX_NODES);
        r = dj->find_max_bw_path(gh, s, t);
        time_taken = float(clock()-t1)/CLOCKS_PER_SEC;
        print_info(s,t,r);
        free(r.path);
        cout<<"Dijkstra with heap time taken is: "<<time_taken<<endl;
        delete dj;

        t1 = clock();
        kruskal *k = new kruskal();
        r = k->find_max_bw_path(edges, num_edges, MAX_NODES, s, t);
        time_taken = float(clock()-t1)/CLOCKS_PER_SEC;
        print_info(s,t,r);
        free(r.path);
        cout<<"kruskal time taken is: "<<time_taken<<endl;
        delete k;
    }
}

int main(){

    for(int i=0;i<5;i++){
        cout<<"*********For pair of graphs******"<<endl;
        graph_generator gh_obj1(6, MAX_NODES);
        graph_node **gh1 = gh_obj1.get_graph();
        edge** edges1 = gh_obj1.get_edges();
        graph_generator gh_obj2(1000,MAX_NODES);
        graph_node **gh2 = gh_obj2.get_graph();
        edge** edges2 = gh_obj2.get_edges();

        // for(int i=0;i<MAX_NODES;i++){
        //     cout<<"i: "<<i<<" ";
        //     for(auto j=gh1[i];j!=NULL;j=j->next){
        //         cout<<j->vertex<<"("<<j->weight<<")"<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;


        cout<<"For first graph:"<<endl;
        run_algos(gh1, edges1, gh_obj1.current_edges);
        cout<<"For second graph:"<<endl;
        run_algos(gh2, edges2, gh_obj2.current_edges);


    }
}
