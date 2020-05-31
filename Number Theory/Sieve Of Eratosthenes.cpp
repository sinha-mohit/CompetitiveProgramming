#include <iostream>
#include <vector>
using namespace std;

int makeSieve(int n){

    vector<bool> isPrime(n + 1, true);
	isPrime[0] = false;
	isPrime[1] = false;

	for(int i=2;i*i<=n;i++){
		if(isPrime[i] == true){
			for(int j=i*i;j<=n;j+=i){
				isPrime[j] = false;
			}
		}
	}

	int count = 0;
	for(int i=0;i<=n;i++){
		if(isPrime[i] == true){
            cout << i << ", ";
			count++;
		}
	}
	return count;

}
int main(){
	int n;
	cin >> n;

	int nPrimes = makeSieve(n);
    cout << endl << "Total count: ";
	cout<<nPrimes <<endl;
	return 0;
}