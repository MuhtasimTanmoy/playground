#include <bits/stdc++.h>
using namespace std;
// https://codeforces.com/contest/581/problem/B
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

	vector<int> li(n);
	vector<int> greater_on_right(n);
	for (int i = 0; i < n; i++)
		cin>>li[i];

	int max_so_far = 0;
	for (int i = n-1; i >= 0; i--) {
		greater_on_right[i] = max_so_far;
		max_so_far = max(max_so_far,li[i]);
	}

	for (int i = 0; i < n; i++)
		li[i] = max(greater_on_right[i]-li[i]+1,0);

	for (int i = 0; i < n; i++)
		cout<<li[i]<<" ";
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