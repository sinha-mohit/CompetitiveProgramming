/*
Weighted Job Scheduling
Send Feedback
You are given N jobs where every job is represented as:
1.Start Time
2.Finish Time
3.Profit Associated
Find the maximum profit subset of jobs such that no two jobs in the subset overlap.
Input
The first line of input contains one integer denoting N.
Next N lines contains three space separated integers denoting the start time, finish time and the profit associated with the ith job. 
Output
Output one integer, the maximum profit that can be achieved.
Constraints
1 ≤ N ≤ 10^6
1 ≤ ai, di, p ≤ 10^6
Sample Input
4
3 10 20
1 2 50
6 19 100
2 100 200
Sample Output
250
*/

//#include<bits/stdc++.h>
#include <iostream> 
#include <algorithm>
using namespace std;
struct job{
    int start,finish,profit;
};


bool compare(struct job a, struct job b){
    return a.finish<b.finish;
}

int BS(struct job arr[],int a,int b ,int i){
    int start=a;
    int end=b;
    int ans = -1;
    while(end >=start){
        int mid=(start+end)/2;
        if((arr[mid].finish<=arr[i].start)){
            ans = mid;
            start=mid+1;
        }
        else{
            end=mid-1;
        }

    }
    return ans;

}

int fMprofit(struct job arr[],int n){


    sort(arr,arr+n,compare);
    int *dp=new int[n+1];
    dp[0]=arr[0].profit;
    // for(int i=0;i<n;i++){
    //     cout<<arr[i].start<<" "<<arr[i].finish<<" "<<arr[i].profit<<endl;
    // }
    for(int i=1;i<n;i++){
        int including=arr[i].profit;
        int a=BS(arr,0,i-1,i);
        // cout<<i<<" "<<a<<endl;
        if(a!= -1)
            including+=dp[a];


        dp[i]=max(including,dp[i-1]);
    }
    int ans= dp[n-1];
    // for(int i=0;i<n;i++){
    //     cout<<dp[i]<<endl;
    // }
    delete []dp;
    return ans;

}
int main()
{
    int n;
    cin>>n;
    //job arr[n];
	struct job *arr = new struct job[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].start;
        cin>>arr[i].finish;
        cin>>arr[i].profit;
    }
    cout<<fMprofit(arr,n)<<endl;
	delete[] arr;
    return 0;
}







