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
	int n, target;
	cin>>n>>target;

	vector<int> res_list;

	int number_of_items;
	int item;
	bool done = false;

	for (int i = 1; i <= n; i++) {
		cin>>number_of_items;

		for (int j = 0; j < number_of_items; j++) {
			cin>>item;

			if(item<target && !done){
				res_list.push_back(i);
				done = true;
			}
		}
		done = false;
	}

	cout<<res_list.size()<<endl;
	for(int a : res_list) cout<<a<<" ";
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
