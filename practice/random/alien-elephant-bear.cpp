#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	n = 6;

	map<int,int> _map;
	int li[n];
	for (int i = 0; i < n; i++) cin>>li[i];
	sort(li,li+n);

	int diff = 0;
	for (int i = 1; i < n; i++) if( li[i] != li[i-1] ) diff++;

	if ( diff>=3 )
		cout<<"Alien"<<endl;
	else if ( diff==0 || diff == 1 )
		cout<<"Elephant"<<endl;
	else
		cout<<"Bear"<<endl;
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