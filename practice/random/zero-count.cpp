#include <bits/stdc++.h>
using namespace std;

void printZero(int n){
	for (int i = 0; i < n; i++)
		cout<<"0";
	cout<<" ";
}

void solve() {
	string s;
	cin>>s;

	vector<char> p;
	vector<int> zero_count;
	int counter=0;

	for (int i = 0; i < s.size(); i++) {
		if( s[i] != '0' ) {
			p.push_back(s[i]);
			zero_count.push_back(s.size() - i - 1);
			counter++;
		}
	}

	cout<<counter<<endl;

	for (int i = 0; i < p.size(); i++) {
		cout<<p[i];
		printZero(zero_count[i]);
	}

	cout<<endl;
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