#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
    cin.tie(0);
	freopen("input.txt", "r", stdin);

	long long n = 2147483648;
	bool* isPrime;
        
    auto generateSieve = [&](long long n) -> void {
        for (long long i = 0 ; i < n; i++) {
			isPrime[i] = 1;
		}
        for ( long long i = 2; i * i <= n; i++ ) {
            if ( isPrime[i] ) {
                for(long long p = i * i; p <= n; p += i) {
                    isPrime[p] = false;
                }
            } 
         }
     };
    
    auto getPrimeFactors = [&](long long n) -> vector<long long> {
        vector<long long> primeFactors;
        for(long long i = 2; i * i <= n; i+=1 ) {
            if ( n % i == 0 ) {
                if ( isPrime[i] ) { primeFactors.push_back(i); }
                if ( isPrime[n / i] ) { primeFactors.push_back(n / i); }
            }
        }
	    return primeFactors;
    };
        
	isPrime = new bool[n];
    generateSieve(n);
    auto primeFactors = getPrimeFactors(n);

	for(long long i: primeFactors) {
        if ( i != 2 && i != 3 && i!=5 ) {
			return 0;
        } 
    }
    cout<<"Ugly";
	return 0;
}