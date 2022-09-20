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
	string first[9] = {"one","two","three","four","five","six","seven","eight","nine"};
	string second[9] = {"inv","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
	int n;
	cin>>n;

	vector<string> v;

	int cur;
	bool _first = true;
	while (n) {
		cur = n%10;
		v.push_back(_first?first[cur-1]:second[cur-1]);
		_first = false;
		n=n/10;
	}

	_first = false;
	for (int i =v.size()-1; i >= 0; i--){
		if(_first && v[i]!="inv") cout<<"-";
		cout<<v[i];
		_first = true;
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
