/*
Prim's Algorithm

Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Prim's algorithm.
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
0 1 3
1 2 1
0 3 5
*/
#include <iostream>
#include <climits>
//#include <bits/stdc++.h>
using namespace std;
int findMinVertex(bool* visited, int* weight, int V){
    int minWeight = INT_MAX;
    int minVertex = 0;
    for(int i = 0; i < V; i++){
        if(visited[i] == false && minWeight > weight[i]){
            minWeight = weight[i];
            minVertex = i;
        }
    }
    return minVertex;
}


void prims(int **mat, int V){
    
    int *parent = new int[V];
    bool *visited = new bool[V];
    int *weight = new int[V];
    
    for(int i = 0; i < V; i++){
		weight[i] = INT_MAX;
        visited[i] = false;
    }
    
    parent[0] = -1;
    weight[0] = 0;
    
    for(int i = 0; i < V; i++){
        int minVertex= findMinVertex(visited, weight, V);
        visited[minVertex] = true;
        for(int j = 0; j < V; j++){
            if(mat[minVertex][j] > 0 && visited[j] != true){
                if(weight[j] > mat[minVertex][j]){
                    weight[j] = mat[minVertex][j];
                    parent[j] = minVertex;
                }
            }
        }
    }
    
    for(int i = 1; i < V; i++){
        if(i < parent[i]){
            cout << i << " " << parent[i] << " " << weight[i] << endl;
        }
        else{
            cout << parent[i] << " " << i << " " << weight[i] << endl;
        }
    }
}


int main()
{      
    int V, E, x, y, z;
	cin >> V >> E;
	
    int **mat = new int*[V];
    for(int i = 0; i < V; i++){
        mat[i] = new int[V];
        for(int j = 0; j < V; j++){
            mat[i][j] = 0;
        }
    }
    
    for(int i = 0; i < E; i++){
        cin >> x >> y >> z;
        mat[x][y] = z;
        mat[y][x] = z;
    }
    
    prims(mat, V);
    
  return 0;
}
