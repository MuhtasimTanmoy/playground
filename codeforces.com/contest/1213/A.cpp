//https://codeforces.com/contest/1213/problem/A
#include <bits/stdc++.h>
#define _DEBUG
#define ll long long
#define pb push_back
#define REP(i, n) for (int i = 0; i < (int)n; i++)
#define q(tag, i) cout << endl \
					   << tag << "...." << i << "...." << endl;
using namespace std;

void solve()
{
	int n;
	cin>>n;
	int holder;
	int evenCount=0;
	int oddCount=0;
	REP(i,n){
		cin>>holder;
		if(holder&1){
			oddCount++;
		}
		else{
			evenCount++;
		}
	}

	int res=0;

	if(oddCount>evenCount){
		res=evenCount;
	}
	else{
		res=oddCount;
	}

	cout<<res<<endl;

}

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int tt = clock();
#endif

	int no_of_test_cases;
	// cin >> no_of_test_cases;
	no_of_test_cases = 1;

	while (no_of_test_cases--)
	{
		solve();
	}

#ifdef _DEBUG
	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();
#endif

	return 0;
}