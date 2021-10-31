#include<iostream>
#include"heap.h"

using namespace std;

class MaxNodesException: public std::exception{
    const char * what() const throw()
    {
        return "Exceeded max number of nodes, cannot insert to heap!!";
    }
};

inline void swap(vector<int> &v, int p1, int p2){
    int temp=v[p1];
    v[p1]=v[p2];
    v[p2]=temp;
}

Myheap::Myheap(){
    size=0;
    node_to_indx.resize(MAX_NODES, -1);
    indx_to_node.resize(MAX_NODES, -1);
    heap_array.resize(MAX_NODES, -1);
}

void Myheap::insert(int node, int bandwidth){
    if(size==MAX_NODES){
        throw MaxNodesException(); 
    }
    node_to_indx[node]=size;
    indx_to_node[size]=node;
    heap_array[size] = bandwidth;
    fix_heap_up(size);    
    size++;
}

void Myheap::fix_heap_up(int i){
    int parent;
    if(i%2==0){
        parent = (i-2)/2;
    }
    else{
        parent = (i-1)/2;
    }

    while(i!=0){
        if(heap_array[parent]<heap_array[i]){
            int node1 = indx_to_node[parent];
            int node2 = indx_to_node[i];
            
            indx_to_node[i] = node1;
            indx_to_node[parent] = node2;

            int temp=node_to_indx[node1];
            node_to_indx[node1]=node_to_indx[node2];
            node_to_indx[node2]=temp;

            temp = heap_array[i];
            heap_array[i]=heap_array[parent];
            heap_array[parent]=temp;

            i=parent;
            parent=(parent-1)/2;
        }
        else{
            break;
        }
    }
}

void Myheap::verify_heap_array(vector<int>&test_heap_array, int test_size)
{
    cout<<"heap_array is: "<<endl;
    
    for(int i=0;i<test_size;i++){
        cout<<heap_array[i]<<" ";
        fflush(stdout);
        if(test_heap_array[i]!=heap_array[i]){
            throw runtime_error("heap array is not as expected, test_heap_array != heap_array");
        }
    }

    cout<<endl;
}

void Myheap::verify_indx_to_node_array(vector<int>&test_indx_to_node_array, int test_size)
{
    cout<<"indx_to_node_array is: "<<endl;
    
    for(int i=0;i<test_size;i++){
        cout<<indx_to_node[i]<<" ";
        fflush(stdout);
        if(test_indx_to_node_array[i]!=indx_to_node[i]){
            throw runtime_error(" indx array is not as expected, test_indx_array != heap_array");
        }
    }

    cout<<endl;
}

void Myheap::verify_node_to_indx_array(vector<int>&test_node_to_indx_array, int test_size){
    cout<<"node_to_indx is: "<<endl;
    
    for(int i=0;i<test_size;i++){
        cout<<node_to_indx[i]<<" ";
        fflush(stdout);
        if(test_node_to_indx_array[i]!=node_to_indx[i]){
            throw runtime_error(" node_to_indx array is not as expected");
        }
    }

    cout<<endl;

}
void Myheap::remove(int node){
    int pos = node_to_indx[node];
    int node1 = indx_to_node[size-1];

    swap(heap_array, pos, size-1);

    node_to_indx[node]=-1;
    indx_to_node[size-1]=-1;

    heap_array[size-1]=-1;

    node_to_indx[node1]=pos;
    indx_to_node[pos]=node1;

    size--;

    fix_heap_down(pos);
}

void Myheap::fix_heap_down(int pos){
    int left=2*pos+1, right=2*pos+2;
    while((left<size)||(right<size)){
        int max_val_child=-1,max_child;
        if(left<size && heap_array[left]>max_val_child){
            max_child=left;
            max_val_child=heap_array[left];
        }
        if(right<size && heap_array[right]>max_val_child){
            max_child=right;
            max_val_child=heap_array[right];
        }

        if(max_val_child==-1){
            throw runtime_error("unable to find max_child!!");
        }

        if(max_val_child>heap_array[pos]){
            swap(heap_array, pos, max_child);
            int node1 = indx_to_node[pos];
            int node2 = indx_to_node[max_child];

            indx_to_node[pos]=node2;
            indx_to_node[max_child]=node1;

            node_to_indx[node1]=max_child;
            node_to_indx[node2]=pos;

            left=2*max_child+1;
            right=2*max_child+2;
            pos=max_child;
        }
        else{
            break;
        }
    }
}

int Myheap::get_max_bandwidth_node(){
    if(size==0){
        throw runtime_error("heap is empty, nothing to return!");
    }

    return indx_to_node[0];
}


