/*
You are given a sequence A[1], A[2], ..., A[N], ( 0 ≤ A[i] ≤ 10^8 , 2 ≤ N ≤ 10^5 ). 
There are two types of operations and they are defined as follows:
Update:
This will be indicated in the input by a 'U' followed by space and then two integers i and x.
U i x, 1 ≤ i ≤ N, and x, 0 ≤ x ≤ 10^8.
This operation sets the value of A[i] to x.
Query:
This will be indicated in the input by a 'Q' followed by a single space and then two integers i and j.
Q x y, 1 ≤ x < y ≤ N.
You must find i and j such that x ≤ i, j ≤ y and i != j, such that the sum A[i]+A[j] is maximized. Print the sum A[i]+A[j].
Input
The first line of input consists of an integer N representing the length of the sequence. 
Next line consists of N space separated integers A[i]. Next line contains an integer Q, Q ≤ 10^5, representing the number of operations. 
Next Q lines contain the operations.
Output
Output the maximum sum mentioned above, in a separate line, for each Query.
Input:
5
1 2 3 4 5
6
Q 2 4
Q 2 5
U 1 6
Q 1 5
U 1 7
Q 1 5
Output:
7
9
11
12
*/
#include <iostream>
#include <algorithm>
using namespace std;
struct node{
    int fMax; //first max
    int sMax; //second max
    int sum; //sum of first max and second max
};
void buildTree(int *arr, node *tree, int start, int end, int nodeIdx){
    if(start == end){
        tree[nodeIdx].fMax = arr[start];
        tree[nodeIdx].sMax = 0;
        tree[nodeIdx].sum = tree[nodeIdx].fMax + tree[nodeIdx].sMax;
        return;
    }
    int mid = (start + end) / 2;
    buildTree(arr, tree, start, mid, 2 * nodeIdx);
    buildTree(arr, tree, mid + 1, end, 2 * nodeIdx + 1);
    int* tempArr = new int[4];
    tempArr[0] = tree[2 * nodeIdx].fMax;
    tempArr[1] = tree[2 * nodeIdx].sMax;
    tempArr[2] = tree[2 * nodeIdx + 1].fMax;
    tempArr[3] = tree[2 * nodeIdx + 1].sMax;
    sort(tempArr, tempArr + 4);
    // for(int i = 0; i < 4; i++)
    //     cout << tempArr[i] <<", ";
    // cout << endl;
    tree[nodeIdx].fMax = tempArr[3];
    tree[nodeIdx].sMax = tempArr[2];
    tree[nodeIdx].sum = tree[nodeIdx].fMax + tree[nodeIdx].sMax;
    delete[] tempArr;
    return;
}

void update(node *tree, int nodeIdx, int arrIdx, int value,  int start, int end){
    int mid = (start + end) / 2;
    if(start == end){
        tree[nodeIdx].fMax = value;
        tree[nodeIdx].sMax = 0;
        tree[nodeIdx].sum = tree[nodeIdx].fMax + tree[nodeIdx].sMax;
        return;
    }
    if(arrIdx > mid){
        update(tree, 2 * nodeIdx + 1, arrIdx, value, mid + 1, end);
    }
    else{
        update(tree, 2 * nodeIdx, arrIdx, value, start, mid);
    }
    int* tempArr = new int[4];
    tempArr[0] = tree[2 * nodeIdx].fMax;
    tempArr[1] = tree[2 * nodeIdx].sMax;
    tempArr[2] = tree[2 * nodeIdx + 1].fMax;
    tempArr[3] = tree[2 * nodeIdx + 1].sMax;
    sort(tempArr, tempArr + 4);
    tree[nodeIdx].fMax = tempArr[3];
    tree[nodeIdx].sMax = tempArr[2];
    tree[nodeIdx].sum = tree[nodeIdx].fMax + tree[nodeIdx].sMax;
    delete[] tempArr;
}

node query(node *tree, int left, int right, int start, int end, int treeNode){
    int mid = (start + end) / 2;
    if(right < start || left > end){ //completely outside the (start, end)
        node z;
        z.fMax = 0;
        z.sMax = 0;
        z.sum = 0;
        return z;
    }
    //completely inside the range
    if(start >= left && end <= right){
        return tree[treeNode];
    }
    else{// partially present
        node ans1 = query(tree, left, right, start, mid, treeNode * 2);
        node ans2 = query(tree, left, right, mid + 1, end, treeNode * 2 + 1);
        int* tempArr = new int[4];
        tempArr[0] = ans1.fMax;
        tempArr[1] = ans1.sMax;
        tempArr[2] = ans2.fMax;
        tempArr[3] = ans2.sMax;
        sort(tempArr, tempArr + 4);
        node z;
        z.fMax = tempArr[3];
        z.sMax = tempArr[2];
        z.sum = z.fMax + z.sMax;
        return z;
    }
}
int main() {
    int n, queries;;
    cin >> n;
    node *tree = new node[4 * n]; //treeNode ka array tree
    int* arr = new int[n + 1]; //given innput array
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    cin >> queries;
    buildTree(arr, tree, 1, n, 1);
    while (queries--) {
        char c;
        cin >> c;
        int x, y;
        cin >> x >> y;
        if ((char)c == 'Q') {
            node z = query(tree, x, y, 1, n, 1);
            cout << z.sum << endl;
        }
        else {
            update(tree, 1, x, y, 1, n);
        }
    }
    delete[] arr;
    delete[] tree;
    return 0;
}