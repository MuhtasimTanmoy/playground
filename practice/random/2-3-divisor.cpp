#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 11;

void solve() {
	int n;
	cin >> n;

	bool once = true;
	vector <int> v;
	int holder;

	for (int i = 0; i < n; i++) {
		cin >> holder;
		while ( holder % 2 == 0 ) holder /= 2;
		while ( holder % 3 == 0 ) holder /= 3;
		v.push_back(holder);
	}

	for (int i = 1; i < n; i++) {
		if ( v[i] != v[i-1] ) {
			once = false;
			break;
		}
	}
	cout<< ( once ? "Yes" : "No" ) << endl;
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