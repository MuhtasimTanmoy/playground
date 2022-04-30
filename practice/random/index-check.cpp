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
	int n_a, n_b;
	cin>>n_a>>n_b;

	int k,m;
	cin>>k>>m;
	vector<int> a,b;
	
	for (int i = 0; i < n_a; i++) {
		int holder;
		cin>>holder;
		a.push_back(holder);
	}

	for (int i = 0; i < n_b; i++) {
		int holder;
		cin>>holder;
		b.push_back(holder);
	}

	if( a[k-1] < b[n_b-m] ) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
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
