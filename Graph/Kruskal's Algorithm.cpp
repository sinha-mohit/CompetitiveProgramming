/*
Kruskal's Algorithm

Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.
For printing MST follow the steps -
1. In one line, print an edge which is part of MST in the format -
v1 v2 w
where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1 <= v2 i.e. print the smaller vertex first while printing an edge.
2. Print V-1 edges in above format in different lines.
Note : Order of different edges doesn't matter.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
Output Format :
MST
Constraints :
2 <= V, E <= 10^5
Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
1 2 1
0 1 3
0 3 5
*/
#include <iostream>
#include <algorithm>
using namespace std;
struct node{
  	int u;
    int v;
    int w;
};
bool comp(node a, node b){
    return a.w < b.w ? true : false;
}
int findParent(int x, int *set){
    while(set[x] >= 0){
        x = set[x];
    }
    return x;
}
void Union(int u, int v, int *set){
    int p1 = findParent(u, set);
    int p2 = findParent(v, set);
    
    if(p1 <= p2){
        set[p1] = set[p1] + set[p2];
        set[p2] = p1;
    }
    else{
        set[p2] += set[p1];
        set[p1] = p2;
    }
}


int main(){
    int V, E, u, v, w;
    cin >> V >> E;
	node *edges = new node[E];
    
    for(int i = 0; i < E; i++){
        cin >> u >> v >> w;
        if(u < v){
            (edges + i)->u = u;
            (edges + i)->v = v;
            (edges + i)->w = w;
        }
        else{
            (edges + i)->u = v;
            (edges + i)->v = u;
            (edges + i)->w = w;
        }
    }
    sort(edges, edges + E, comp);
    
	int *set = new int[V];
    for(int i = 0; i < V; i++){
        set[i] = -1;
    }
    
    int count = 0;
    int edgeIdx = 0;
    int mstIdx = 0;
    node *MST = new node[V - 1];
    
    while(count != V - 1){
        if(findParent((edges + edgeIdx)->u, set) != findParent((edges + edgeIdx)->v, set)){
            (MST + mstIdx)->u = (edges + edgeIdx)->u;            
            (MST + mstIdx)->v = (edges + edgeIdx)->v;
            (MST + mstIdx)->w = (edges + edgeIdx)->w;
			mstIdx++;
            Union((edges + edgeIdx)->u, (edges + edgeIdx)->v, set);
            count++;
        }
        edgeIdx++;
    }
    //cout << "MST: " << endl;
    for(int i = 0; i < V - 1; i++){
        cout << (MST + i)->u << " " << (MST + i)->v << " " << (MST + i)->w << endl;  
    }
    delete[] MST;
    delete[] edges;
  	return 0;
}