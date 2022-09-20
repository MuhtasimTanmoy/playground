#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 11;

void solve() {
	string s;
	cin >> s;
	bool diffGot = false;
	int curr = s[0];
	int count = 0;

	for (int i = 1; i < s.size(); i++) {

		if (!diffGot)
			if ( s[i] != curr ) {
				diffGot = true;
				curr = s[i];
			}

		if(diffGot) if(curr!=s[i]) count++;
	}
	cout<<count<<endl;
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