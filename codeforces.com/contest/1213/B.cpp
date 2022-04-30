//https://codeforces.com/contest/1213/problem/B
#include <bits/stdc++.h>
#define _DEBUG
#define ll long long
#define pb push_back
#define REP(i, n) for (int i = 0; i < (int)n; i++)
#define q(tag, i) cout << endl \
					   << tag << "...." << i << "...." << endl;
using namespace std;

int li[150000];
void solve() {
	int n;
	cin>>n;
	REP(i,n) 
		cin>>li[i];

	int curMin=li[n-1];
	int count=0;

	for(int i = n-2; i >= 0; i-- ) {
		if( li[i] > curMin ) count++;
		else curMin=li[i];
	}

	cout<<count<<endl;
}

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int tt = clock();
#endif
	int no_of_test_cases;
	cin >> no_of_test_cases;
	// no_of_test_cases = 1;
	while (no_of_test_cases--)
	{
		solve();
		// pr("");
	}
#ifdef _DEBUG
	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();
#endif
	return 0;
}