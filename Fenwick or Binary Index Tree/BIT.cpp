//Range sum queries
//remember index are always from 1 to N.
/*
input:
8
1
2
3
4
5
6
7
8
output:
Sum of first 5 elements 15
Sum of elements form 2 index to 6 index 20
*/
#include <iostream>
using namespace std;
void update(int i, int x, int *FT, int n){
    while(i <= n){
        FT[i] = FT[i] + x;
        i = i + (i & -i);    //note: not ~i : this is not operation
        // -i : this is 2's complement of i
    }
}
int query(int i, int *FT){
    int sum = 0;
    while(i != 0){
        sum = sum + FT[i];
        i = i - (i & -i);
    }
    return sum;
}
int main(){
    int n;
    cin >> n;

    int *arr = new int[n + 1]();
    int *FT = new int[n + 1]();

    for(int i = 1; i <= n; i++){/*this Fenwick tree construction is O(nlogn) since for every n we are doing O(logn) operation, you can do better in just O(n)*/
        cin >> arr[i];
        update(i, arr[i], FT, n);//O(logn)
    }
    cout << "Sum of first 5 elements " << query(5, FT) << endl;
    cout << "Sum of elements form 2 index to 6 index " << query(6, FT) - query(1, FT) << endl; 
    delete[] arr;
    delete[] FT;
    return 0;
}
