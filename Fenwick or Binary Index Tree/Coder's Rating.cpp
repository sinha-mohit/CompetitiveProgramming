/*
Coder's Rating

Some of the more elite (and not-so-elite) coders around take part in a certain unnamed programming contest. 
In said contest, there are multiple types of competitions. Here, we consider the Open and High School competition types. 
For each type, each competitor receives a rating, an integer between 1 and 100000, inclusive. 
A coder's rating is based upon his or her level of performance in matches and is calculated using a complicated formula which, 
thankfully, you will not be asked to implement.
Although the Open and High School ratings for a coder who has participated in both competition types lately are usually close, 
this is not always the case. In particular, High School matches are more about speed, since many coders are able to solve all the problems, 
whereas Open matches require more thinking and there is a steeper curve in terms of problem difficulty.

Problem Statement
You are given N coders (1 ≤ N ≤ 300000), conveniently numbered from 1 to N. Each of these coders participates in both High School and Open matches. 
For each coder, you are also given an Open rating Ai and a High School rating Hi. 
Coder i is said to be better than coder j if and only if both of coder i's ratings are greater than or equal to coder j's corresponding ratings, 
with at least one being greater. For each coder i, determine how many coders coder i is better than.

Input Format
On the first line of input is a single integer N, as described above. N lines then follow. Line i+1 contains two space-separated integers, Ai and Hi.

Output Format
Line i should contain the number of coders that coder i is better than.

Sample Input
8
1798 1832
862 700
1075 1089
1568 1557
2575 1984
1033 950
1656 1649
1014 1473

Sample Output
6
0
2
4
7
1
5
1
*/

#include <iostream>
#include <algorithm>
using namespace std;
struct node{
    int x;
    int y;
    int index;
};
bool cmp(node& A, node& B){
    if(A.x == B.x){
        return A.y < B.y;
    }
    return A.x < B.x;
}
int query(int y, int *FT){
    int count = 0;
    while(y > 0){
        count = count + FT[y];
        y = y - (y & (-y));
    }
    return count;
}
void update(int y, int *FT){
    while(y < 100001){
        FT[y]++;
        y = y + (y & (-y));
    }
}
int main(){
    int n;
    cin >> n;
    node *arr = new node[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i].x >> arr[i].y;
        arr[i].index = i;
    }
    sort(arr, arr + n, cmp);
    int *FT = new int[100001];
    int *ans = new int[n];
    for(int i = 0; i < n;){ //Do not put i++ here.
        int endIndex = i; // to count same entries and to prevent same updates on same entiries.

        /* dry run this 
        eg: intput:
            6
            1 2
            2 3
            2 3
            2 3
            3 5
            6 7

            output:
            0
            1
            1
            1
            4
            5
        */ 
        while(arr[i].x == arr[endIndex].x && arr[i].y == arr[endIndex].y && endIndex < n){
            endIndex++;
        }
        for(int j = i; j < endIndex; j++){
            //query
            ans[arr[j].index] = query(arr[j].y, FT);
        }
        
        for(int j = i; j < endIndex; j++){
            //insert
            update(arr[j].y, FT);
        }

        i = endIndex; 
    }

    for(int i = 0; i < n; i++){
        cout << ans[i] << endl;
    }
    delete[] ans;
    delete[] FT;
    delete[] arr;
    return 0;
}
