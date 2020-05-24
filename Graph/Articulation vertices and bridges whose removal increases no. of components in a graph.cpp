/*
Articulation Points and Bridges SOLVED
Given an undirected graph containing N vertices and M edges, find all the articulation points and all the bridges in the graph.

Input:
First line consists of two space separated integers denoting N and M. M lines follow, each containing two space separated integers X and Y denoting there is an edge between X and Y.

Output:
If the number of articulation points in the graph is p and that of bridges is q , then print as shown below:
p
p space separated integers, the articulation points, sorted in increasing order
q
q lines, each containing two space separated integers, the bridges in the graph. 
For a bridge u-v, print u first if u < v, otherwise print v first. Print all the bridges in increasing order of first vertex, 
and if first vertex is same, then in increasing order of second vertex.

Constraints:
1 ≤ N, M ≤ 10
0 ≤ X, Y ≤ N-1

SAMPLE INPUT 
3 2
0 1
1 2
SAMPLE OUTPUT 
1
1
2
0 1
1 2
*/

//AC Code

#include <iostream>
#include <stack>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <climits>
#include <string>
#include <unordered_map>
#include <map>
#include <set>
#include <ctime>
#include <algorithm>
#include <cstring>
using namespace std;

#define mod 1000000007

void dfs(int u, vector<vector<int> >& adjList, vector<int>& disc, vector<int>& low, vector<bool>& visited, vector<bool>& ap, vector<pair<int, int> >& bridges, int parent){
    static int time=1;
    disc[u] = low[u] = time++;
    int child=0;
    visited[u] = true;
    for (auto& ele: adjList[u]){
        if (!visited[ele]){
            child++;
            dfs(ele, adjList, disc, low, visited, ap, bridges, u);
            low[u] = min(low[u], low[ele]);
            if (parent==-1 && child>1) ap[u] = true;
            else if (parent!=-1 && low[ele]>=disc[u]) ap[u] = true;
            if (low[ele]>disc[u]) bridges.push_back({u, ele});
            }
        else if (ele != parent){
            low[u] = min(low[u], disc[ele]);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > adjList(n);
    for (int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    vector<bool> visited(n, false);
    vector<bool> ap(n, false);
    vector<pair<int, int> > bridges;
    vector<int> disc(n, INT_MAX);
    vector<int> low(n, INT_MAX);
    int count=0;
    for (int i=0;i<n;i++){
        if (!visited[i])   dfs(i, adjList, disc, low, visited, ap, bridges, -1);
    }
    for (int i=0;i<n;i++){
        if (ap[i]) count++;
    }
    cout << "No. of Articulation Points:" << endl;
    cout << count << endl;
    cout << "Articulation Vertices:" << endl;
    for (int i=0;i<n;i++){
        if (ap[i]) cout << i << " ";
    }
    cout << endl;

    auto compare = [&](auto a, auto b){
    return a.first<b.first || (a.first==b.first && a.second<b.second);
    };

    sort(bridges.begin(), bridges.end(), compare);
    cout << "No. of Bridges:" << endl;
    cout << bridges.size() << endl;
    cout << "Bridges" << endl;
    for (auto& ele: bridges){
    cout << ele.first << " " << ele.second << endl;
    }
    return 0;
}