#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

bool isPrime(int n){
	int root = sqrt(n);
	for (int i = 2; i <= root; i++)
		if(n%i==0) return false;
	return true;
}

void solve() {
	int n;
	cin>>n;

	int l = n>>1;
	int r = n>>1;
	if(n%2) r++;

	while((isPrime(l) || isPrime(r))) {
		l--;
		r++;
	}

	cout<<l<< " "<<r<<endl;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	freopen("input.txt", "r", stdin);
    int no_of_test_cases = 1;
	// cin >> no_of_test_cases;
    while (no_of_test_cases--) execute(); 
	return 0;
}
