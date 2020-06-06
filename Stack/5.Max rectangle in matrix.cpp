/*
Given a binary matrix, Your task is to complete the function maxArea which the maximum size rectangle area in a binary-sub-matrix with all 1’s. The function takes 3 arguments the first argument is the Matrix M[ ] [ ] and the next two are two  integers n and m which denotes the size of the matrix M. Your function should return an integer denoting the area of the maximum rectangle .

Input:
The first line of input is an integer T denoting the no of test cases . Then T test cases follow. The first line of each test case are 2 integers n and m denoting the size of the matrix M . Then in the next line are n*m space separated values of the matrix M.

Output:
For each test case output will be the area of the maximum rectangle .

Constraints:
1<=T<=100
1<=n,m<=1000
0<=M[][]<=1

Expected Time Complexity : O(n*m)
Expected Auixilliary Space : O(m)

Example:
Input
1
4 4
0 1 1 0 1 1 1 1 1 1 1 1 1 1 0 0

Output
8

Explanation
For the above test case the matrix will look like
0 1 1 0
1 1 1 1
1 1 1 1
1 1 0 0
the max size rectangle is
1 1 1 1
1 1 1 1
and area is 4 *2 = 8
*/
#include <bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <stack>
// #include <utility>
// #include <algorithm>
using namespace std;
#define MAX 1000

int maxArea(int M[MAX][MAX], int n, int m);
// void solverLeft(int* ans, int n, vector<int>& arr);
// void solverRight(int* ans, int n, vector<int>& arr);
// int maxAreaHistogram(vector<int>& arr, int n);

int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        cout << maxArea(M, n, m) << endl;
    }
}


void solverLeft(int* ans, int n, vector<int>& arr) {
    stack<pair<int, int>> s;
    for (int i = 0; i < n; i++) {
        if (s.size() == 0) {
            ans[i] = 1;
            s.push({ arr[i], 1 });
        }
        else {
            if (arr[i] > s.top().first) {
                ans[i] = 1;
                s.push({ arr[i], 1 });
            }
            else {
                int count = 0;
                while (s.size() != 0 && arr[i] <= s.top().first) {
                    count = count + s.top().second;
                    s.pop();
                }
                ans[i] = count + 1;
                s.push({ arr[i], count + 1 });

            }
        }
    }
}
void solverRight(int* ans, int n, vector<int>& arr) {
    stack<pair<int, int>> s;
    for (int i = n - 1; i >= 0; i--) {
        if (s.size() == 0) {
            ans[i] = 1;
            s.push({ arr[i], 1 });
        }
        else {
            if (arr[i] > s.top().first) {
                ans[i] = 1;
                s.push({ arr[i], 1 });
            }
            else {
                int count = 0;
                while (s.size() != 0 && arr[i] <= s.top().first) {
                    count = count + s.top().second;
                    s.pop();
                }
                ans[i] = count + 1;
                s.push({ arr[i], count + 1 });

            }
        }
    }
}
int maxAreaHistogram(vector<int>& arr, int n) {
    int* countGreaterElementsToLeft = new int[n];
    int* countGreaterElementsToRight = new int[n];
    solverLeft(countGreaterElementsToLeft, n, arr);
    solverRight(countGreaterElementsToRight, n, arr);
    int area = 0;
    for (int i = 0; i < n; i++) {
        area = max(area, (countGreaterElementsToLeft[i] + countGreaterElementsToRight[i] - 1) * arr[i]);
    }
    delete[] countGreaterElementsToLeft;
    delete[] countGreaterElementsToRight;
    return area;
}
int maxArea(int mat[MAX][MAX], int n, int m) {
    int row = n;
    int col = m;
    vector<int> temp(col, 0);
    int ans = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (mat[i][j] == 1) {
                temp[j]++;
            }
            else {
                temp[j] = 0;
            }
        }
        ans = max(ans, maxAreaHistogram(temp, col));
    }
    return ans;
}
