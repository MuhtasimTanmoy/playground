#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

void solve() {
	int n;
	cin>>n;

	int maxElem = 0;
	set<int> bag;
	map<int,int> mapping;
	int len_decrease = 0;
	int holder;

	for (int i = 0; i < n; i++){
		cin>>holder;

		if( bag.count(holder) ) {
			len_decrease;
			mapping[holder]++;
			maxElem = max(maxElem, mapping[holder]);
		} else {
			bag.insert(holder);
		}
	}

	cout<<maxElem<<" "<< n-len_decrease <<endl;
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