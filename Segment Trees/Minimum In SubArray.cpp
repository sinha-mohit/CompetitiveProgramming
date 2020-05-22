/*
Range Minimum Query
Given an array A of size N, there are two types of queries on this array.
1) q l r: In this query you need to print the minimum in the sub-array A[l:r].
2) u x y: In this query you need to update A[x]=y.
Input:
First line of the test case contains two integers, N and Q, size of array A and number of queries.
Second line contains N space separated integers, elements of A.
Next Q lines contain one of the two queries.
Output:
For each type 1 query, print the minimum element in the sub-array A[l:r].
Contraints:
1≤N,Q,y≤10^5
1≤l,r,x≤N
Sample Input :
5 5
1 5 2 4 3
q 1 5
q 1 3
q 3 5
u 3 6
q 1 5
Sample Output :
1
1
2
1
*/

#include <iostream>
#include <algorithm>
#include <climits>
#include <string>
using namespace std;

void buildTree(int* arr, int* tree, int start, int end, int treeNode) {
    if (start == end) {
        tree[treeNode] = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    buildTree(arr, tree, start, mid, 2 * treeNode);
    buildTree(arr, tree, mid + 1, end, 2 * treeNode + 1);
    tree[treeNode] = min(tree[2 * treeNode], tree[2 * treeNode + 1]);
    return;
}

void update(int* tree, int treeNode, int indx, int value, int start, int end) {
    if (start == end) {
        tree[treeNode] = value;
        return;
    }
    int mid = (start + end) / 2;
    if (indx <= mid) {
        update(tree, 2 * treeNode, indx, value, start, mid);
    }
    else {
        update(tree, 2 * treeNode + 1, indx, value, mid + 1, end);
    }
    tree[treeNode] = min(tree[2 * treeNode], tree[2 * treeNode + 1]);
}

int query(int* tree, int left, int right, int start, int end, int treeNode) {
    int mid = (start + end) / 2;

    //completely outside of range
    if (end < left || start > right) {
        return INT_MAX;
    }
    //completely inside the range
    else if (start >= left && right >= end) {//////////important step   left start end right
        return tree[treeNode];
    }
    else {//partially left and right present 
        int ans1 = query(tree, left, right, start, mid, 2*treeNode);
        int ans2 = query(tree, left, right, mid + 1, end, 2*treeNode + 1);
        return min(ans1, ans2);
    }
}
int main() {
    int n, queries;
    cin >> n >> queries;
    int* tree = new int[4 * n]; //treeNode ka array tree
    int* arr = new int[n + 1]; //given innput array
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    buildTree(arr, tree, 1, n, 1);
    while (queries--) {
        char c;
        cin >> c;
        int x, y;
        cin >> x >> y;
        if ((char)c == 'q') {
            cout << query(tree, x, y, 1, n, 1) << endl;
        }
        else {
            update(tree, 1, x, y, 1, n);
        }
    }
    delete[] arr;
    delete[] tree;
    return 0;
}