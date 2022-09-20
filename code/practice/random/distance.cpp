#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 11;

void solve() {
	int n, x;
	cin >> n >> x;

	string s;
	cin>>s;

	int distance = 0;
	int count = 0;
	int projected = 0;

	for (int i = s.size()-1; i >= 0; i--) {
		distance = s.size()-1-i - count;
		
		if( s[i]=='B' ) {
			projected = i + min(distance,x);

			if(s[projected] != 'B') {
				s[i]='G';
				s[projected]='B';
				count++;
			}
		}
	}

	cout<<s<<endl;
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
