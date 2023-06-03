// #include <bits/stdc++.h>
#include<iostream>
using namespace std;

void execute() {
	int n; cin >> n;
	vector<pair<int, int>> edges;
	for (int i = 0, from = 0, to = 0; i < n; i++) {
		cin>>from>>to;
		edges.emplace_back(from, to);
	}
	// cout<<res<<endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("input.txt", "r", stdin);
	int no_of_test_cases = 1;
	cin >> no_of_test_cases;
	while (no_of_test_cases--) execute();
	return 0;
}