//https://codeforces.com/contest/1150/problem/A
#include <bits/stdc++.h>
#define _DEBUG
#define ll long long
#define pb push_back
#define REP(i, n) for (int i = 0; i < (int)n; i++)
using namespace std;

bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
	return (a.second < b.second);
}

void solve() {
	int n, m, r;
	cin >> n >> m >> r;

	if(r==0) cout<<0<<endl;

	int holder_n;
	int holder_m;

	int min_n = INT32_MAX;
	int max_m = INT32_MIN;

	REP(i, n)
	{
		cin >> holder_n;
		min_n = min(min_n, holder_n);
	}

	REP(i, m)
	{
		cin >> holder_m;
		max_m = max(max_m, holder_m);
	}

	int count = r / min_n;

	cout << r + count * ((max_m - min_n)>0?(max_m - min_n):0) << endl;
}

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int tt = clock();
#endif

	ios_base::sync_with_stdio(false);
	int no_of_test_cases;
	//cin >> no_of_test_cases;
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
