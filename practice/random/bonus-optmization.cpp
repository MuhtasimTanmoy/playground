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
	int s,n;
	cin>>s>>n;
	vector< pair<int,int> > li;

	bool possible = true;
	for (int i = 0; i < n; i++) {
		int curr, bonus;
		cin >> curr >> bonus;
		li.push_back(make_pair(curr,bonus));
	}

	sort(li.begin(),li.end());

	for (int i = 0; i < n; i++) {
		if( s > li[i].first ) s += li[i].second;
		else possible=false;
	}

	cout<<(possible?"YES":"NO")<<endl;
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int no_of_test_cases = 1;
	// cin >> no_of_test_cases;
	while (no_of_test_cases--)solve();
	return 0;
}