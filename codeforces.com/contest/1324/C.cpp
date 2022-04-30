//https://1324/problem/C
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

	vector<int> li;
	int holder;

	for (int i = 0; i < n; i++){
		cin>>holder;
		li.push_back(holder);
	}

	bool once = false;
	int index = 0;
	bool check = false;
	bool check2 = false;
	bool cache = true;

	for (int i = n-1; i > 0; i--) {
		check = (li[i-1]<=li[i]);
		check2 = (li[i-1]>li[i]);

		if(check) 
			once = true;

		if(check2 && once && cache){
			index = i;
			cache = false;
		}
	}
	cout<<index<<endl;
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