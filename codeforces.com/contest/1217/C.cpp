//https://codeforces.com/contest/1217/problem/C
#include <bits/stdc++.h>
#define _DEBUG
#define ll long long
#define pb push_back
#define REP(i, n) for (int i = 0; i < (int)n; i++)
using namespace std;

bool sortbysec(const pair<int, int> &a, const pair<int, int> &b)
{
	return (a.second < b.second);
}

const int N = int(3e5) + 99;
string s;
int nxt[N];

void solve()
{

	cin >> s;

	bitset<18> bi(s);
	
	// cout << bi.to_ulong() <<endl; 
	// return;


	for (int i = 0; i < s.size(); ++i)
		if (s[i] == '1')
			nxt[i] = i;
		else
			nxt[i] = (i == 0 ? -1 : nxt[i - 1]);
		
	int res = 0;
	for (int r = 0; r < s.size(); ++r)
	{
		int sum = 0;
		for (int l = r; l >= 0 && r - l < 20; --l)
		{
			if (s[l] == '0')
				continue;
			sum += 1 << (r - l);
			if (sum <= r - (l == 0 ? -1 : nxt[l - 1]))
				++res;
		}
	}
	cout << res << endl;
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
	cin >> no_of_test_cases;
	// no_of_test_cases=1;
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
