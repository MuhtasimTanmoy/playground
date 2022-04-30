#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

void solve() {
	int n,m;
	cin >> n >> m;

	if( n==1 && m==1 ) { 
		cout<<2<<endl;
		return;
	}

	int b = 0;
	int a = 0;

	while( b >= 0 ) {
		b = n - a*a;

		if( a + b * b == m && b >= 0 ) {
			cout<<1<<endl;
			return;
		}
		a += 1;
	}
	cout<<0<<endl;
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int no_of_test_cases = 1;
	cin >> no_of_test_cases;
	while (no_of_test_cases--)solve();
	return 0;
}