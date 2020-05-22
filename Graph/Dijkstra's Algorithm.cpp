#include <iostream>
//#include <bits/stdc++.h>
#include <vector>
using namespace std;
// ye toh ditto Prims ka hi modified version nikla....yaad rakhna Prims Dijkstra and Kruskals(findSet and Union).
int findMinVertex(bool* visited, int* dist, int V){
    int minDist = INT_MAX;
    int minVertex = 0;
    for(int i = 0; i < V; i++){
        if(visited[i] == false && minDist > dist[i]){
            minDist = dist[i];
            minVertex = i;
        }
    }
    return minVertex;
}


void Dij(vector <vector <int>>& mat, int V){
    bool *visited = new bool[V];
    int *dist = new int[V];
    
    for(int i = 0; i < V; i++){
		dist[i] = INT_MAX;
        visited[i] = false;
    }
    
    dist[0] = 0;
    
    for(int i = 0; i < V; i++){
        int minVertex= findMinVertex(visited, dist, V);
        visited[minVertex] = true;
        for(int j = 0; j < V; j++){
            if(mat[minVertex][j] > 0 && visited[j] != true){
                if(dist[j] > mat[minVertex][j] + dist[minVertex]){
                    dist[j] = mat[minVertex][j] + dist[minVertex];
                }
            }
        }
    }
    
    for(int i = 0; i < V; i++){
        cout << i << " " << dist[i] << endl;
    }
    cout << endl;
}

int main()
{
    int V, E, u, v, w;
    cin >> V >> E;
    vector <vector <int>> mat(V, vector <int>(V, -1));
    for(int i = 0; i < E; i++){
        cin >> u >> v >> w;
        mat[u][v] = w;
        mat[v][u] = w;
    }
    
    Dij(mat, V);


  return 0;
}







//another solution.....after thinking deeply lol

// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;

// void Dij(vector <vector <int>>& mat, int V){
//     vector <int> dist(V, INT_MAX - 9999);
//     dist[0] = 0;
//     bool flag = true;
//     while(flag){
//         flag = false;
//         for(int i = 0; i < V; i++){
//             for(int j = 0; j < V; j++){
//                 if(mat[i][j] > 0){
//                     if(dist[i] + mat[i][j] < dist[j]){
//                         dist[j] = dist[i] + mat[i][j];
//                         flag = true;
//                     }
//                 }
//             }
//         }
//     }
   
    
    
    
//     for(int i = 0; i < V; i++){
//         cout << i << " " << dist[i] << endl;
//     }
//     cout << endl;
// }

// int main()
// {
//     int V, E, u, v, w;
//     cin >> V >> E;
//     vector <vector <int>> mat(V, vector <int>(V, -1));
//     for(int i = 0; i < E; i++){
//         cin >> u >> v >> w;
//         mat[u][v] = w;
//         mat[v][u] = w;
//     }
    
//     Dij(mat, V);


//   return 0;
// }

