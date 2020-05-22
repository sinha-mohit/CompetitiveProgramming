//#include<bits/stdc++.h>
#include <iostream>
#include <set>
#include <vector>
#include <stack>
using namespace std;

void dfs1(int start, vector <set <int>>& edges, vector <bool>& visited, stack <int>& finishedStack){
    visited[start] = true;
    for(auto it = edges[start].begin(); it != edges[start].end(); it++){
        if(visited[*it] == false){
            dfs1(*it, edges, visited, finishedStack);
        }
    }
    finishedStack.push(start);//end me stack me store karo
}

void dfs2(int start, vector <set <int>>& edgesT, vector <bool>& visited, set <int>& components){
    visited[start] = true;
    components.insert(start);
    for(auto it = edgesT[start].begin(); it != edgesT[start].end(); it++){
        if(visited[*it] == false){
            dfs2(*it, edgesT, visited, components);
        }
    }
}

vector <set<int>> getSCC(vector <set <int>>& edges, vector <set <int>>& edgesT, int V){
    vector <bool> visited(V, false);
    stack <int> finishedStack;
    for(int i = 0; i < V; i++){
        if(visited[i] == false){
            dfs1(i, edges, visited, finishedStack);
        }
    }

    vector <bool> visited2(V, false); // again make new visited array 
    vector <set<int>> output;
    while(!finishedStack.empty()){
        set <int> components;
        int topElement = finishedStack.top();
        finishedStack.pop();
        if(visited2[topElement] == false){
            dfs2(topElement, edgesT, visited2, components); //here dfs2 is implemented on transpose of edges i.e all original direction of edges are changed i.e use edgesT adjacency list
            output.push_back(components);
        }
    }

    return output;
}

int main(){
    while(true){
        // int n, m;
        // cin >> n >> m;
        int n;
        cin >> n;
        if(n == 0){
            break;
        }
        int m;
        cin >> m;
        vector <set <int>> edges(n), edgesT(n);
        for(int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            edges[u - 1].insert(v - 1); //though my index are from 1 to N, but i am storing from 0 to N - 1. while outputing i will add + 1.
            edgesT[v - 1].insert(u - 1);//transpose of edges
        }
        vector <set<int>> output = getSCC(edges, edgesT, n);   //<<1, 3, 5>, <2, 4, 6>, <....>> vector of set i.e, output is vector of components stored as sets

        cout << endl;
        for(int i = 0; i < output.size(); i++){
            for(auto it = output[i].begin(); it != output[i].end(); it++){
                cout << *it + 1 << " ";
            }
            cout << endl;
        }
        
        
    return 0;
}