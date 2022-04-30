#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 11;

void solve() {
	char c;
	int li[26] = {0};

	while( cin >> c ) {
		if(c==' ' || c==',') continue;
		li[c-'a']=1;
	}

	int count = 0;
	for (int i = 0; i < 26; i++)
		if( li[i]==1 ) count++;

	cout<<count<<endl;
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