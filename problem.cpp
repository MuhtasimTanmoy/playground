// Find K-Length Substrings With No Repeated Characters

#include <bits/stdc++.h>
using namespace std;

#define log(x) cout << #x << " = " << x << endl;

void execute() {

	string s;
	cin >> s;

	int k;
	cin >> k;

	int characterMap[26];

	int left = 0;
	int right = 0;
	
	while ( right < size(s) ) {
		
		while(characterMap[s[right]]) {
			characterMap[left]--;
			left++;
		}

		right
	}
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