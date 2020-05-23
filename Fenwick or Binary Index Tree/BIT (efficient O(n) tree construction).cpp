//remember index are always from 1 to N.
/*
input:

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

    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        FT[i] = arr[i];
        //update(i, arr[i], FT, n);//O(logn)
    }
    for(int i = 1; i <= n; i++){/*this Fenwick tree construction is O(n)*/
        int j = i + (i & -i);
        if(j <= n){
            FT[j] = FT[j] + FT[i];
        }
    }
    cout << "Sum of first 5 elements " << query(5, FT) << endl;
    cout << "Sum of elements form 2 index to 6 index " << query(6, FT) - query(1, FT) << endl; 
    delete[] arr;
    delete[] FT;
    return 0;
}
