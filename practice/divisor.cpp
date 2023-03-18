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
	int n, div;
	cin >> n >> div;
	int count = 0;

	for (int i = 1; i <= min(n,div); i++) {
		if( div % i == 0 ) {
			int num = div/i;
			if( num <= n) count++;
		}
	}
	
	cout<<count<<endl;
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