/*You are given n activities with their start and finish times. Select the maximum number of activities that can be performed by a single person, 
assuming that a person can only work on a single activity at a time.
Input
The first line of input contains one integer denoting N.
Next N lines contains two space separated integers denoting the start time and finish time for the ith activity.

Output
Output one integer, the maximum number of activities that can be performed
Constraints
1 ≤ N ≤ 10^6
1 ≤ ai, di ≤ 10^9
Sample Input
6
1 2
3 4
0 6
5 7
8 9
5 9
Sample Output
4
*/

#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
bool fun(pair <int, int>& a, pair <int, int>& b){
    return a.second < b.second ? true : false; 
}
int solver(vector <pair <int, int>>& v, int n){
    int count = 1;
    sort(v.begin(), v.end(), fun);
    
    auto it = v.begin();
    int value = it->second;
    for(; it != v.end() - 2; it++){
        if((it + 1)->first >= value){
            count++;
            value = (it + 1)->second;
        }
    }
    return count;
}
int main(){
    int n;
    cin >> n;
    vector <pair <int,int>> v(n);
    int start, end;
    for(int i = 0; i < n; i++){
        cin >> start >> end;
        v[i] = make_pair(start, end);
    }
    cout << solver(v, n);
    return 0;
}

