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
	int n;
	cin>>n;

	int holder;
	int unrated = 0;
	int total = 0;
	
	for (int i = 0; i < n; i++) {
		cin >> holder;
		if( total == 0 && holder == -1 ) {
			unrated++;
			continue;
		}
		total += holder;
	}
	cout<<unrated<<endl;
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
