#include <bits/stdc++.h>
using namespace std;

void process_input() {
	int n; cin>>n;

	set<int> A, B;
	for (auto i = 0; i < n; i++) {
		char c; cin>>c;
		if (c == 'A') A.insert(i + 1); else B.insert(i + 1);
	}

	while (A.size() && B.size()) {
		auto alice = *A.rbegin();
		if (alice == n) {
			if (*B.begin() != 1) B.erase(*B.begin());
			else A.erase(alice);
		} else {
			auto i = B.upper_bound(alice);
			if (i == B.end()) B.erase(*B.begin());
			else {
				if (alice == 1 && *i == n) B.erase(*i), A.insert(*i);
				else A.erase(*A.rbegin());
			}
		}
	}
	auto res = A.size() ? "Alice" : "Bob";
	cout<<res<<endl;
} 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	// freopen("input.txt", "r", stdin);
	int r; cin>>r;
	while (r--) process_input();
	return 0;
}

// https://codeforces.com/contest/2104