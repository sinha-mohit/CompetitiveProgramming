/*
KQUERY
Send Feedback
Given a sequence of n numbers a1, a2, ..., an and a number of k- queries. A k-query is a triple (i, j, k) (1 ≤ i ≤ j ≤ n). For each k-query (i, j, k), you have to return the number of elements greater than k in the subsequence ai, ai+1, ..., aj.
Input Format
Line 1: n (1 ≤ n ≤ 30000).

Line 2: n numbers a1, a2, ..., an (1 ≤ ai ≤ 10^9).

Line 3: q (1 ≤ q ≤ 200000), the number of k- queries.

In the next q lines, each line contains 3 numbers i, j, k representing a k-query (1 ≤ i ≤ j ≤ n, 1 ≤ k ≤ 10^9).
Output Format
For each k-query (i, j, k), print the number of elements greater than k in the subsequence ai, ai+1, ..., aj in a single line.
Sample Input
5
5 1 2 3 4
3
2 4 1
4 4 4
1 5 2 
Sample Output
2
0
3 
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <ctype.h>
#include <stack>
#include <iostream>
#include <queue>
#include <set>
#include <map>
#include <iterator>
 
 
using namespace std;
 
struct node{
    int v;
    int i;
    int j;
    int q;
};
 
typedef node node;
 
int tree[30001];
node inp[230000];
int n;
int maxVal;
 
bool operator <( node a, node b ) {
    if ( a.v == b.v ) {
        return a.j > b.j;
    }
    return a.v > b.v;
}
 
 
 
int read(int idx){
    int sum = 0;
    while(idx > 0){
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}
 
void update(int idx, int val){
    while(idx <= maxVal){
        tree[idx] += val;
        idx += (idx & -idx);
    }
}
 
int main()
{
    int m;
    scanf("%d", &n);
    maxVal = n;
    for(int i = 0 ; i < n ; i++){
        scanf("%d", &inp[i].v);
        inp[i].i = i + 1;
        inp[i].j = -1;
        tree[i] = 0;
    }
    scanf("%d", &m);
    int *res = new int[m];
    //int res[m];
 
    for(int i = 0 ; i < m ; i++){
        scanf("%d %d %d", &inp[i + n].i , &inp[i + n].j, &inp[i + n].v);
        inp[i + n].q = i;
    }
 
    sort( inp, inp + n + m );
 
 
    for(int i = 0 ; i < n + m ; i++){
        if(inp[i].j == -1){
            update(inp[i].i, 1);
        }else{
            int result = read(inp[i].j) - read(inp[i].i - 1);
            res[inp[i].q] = result;
        }
    }
 
    for(int i = 0 ; i < m ; i++)
        printf("%d\n", res[i]);
    delete[] res;    
    return 0;
}