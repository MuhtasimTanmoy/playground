//https://codeforces.com/contest/1217/problem/A
#include <bits/stdc++.h>
#define _DEBUG
#define ll long long
#define pb push_back
#define REP(i, n) for (int i = 0; i < (int)n; i++)
using namespace std;

bool sortbysec(const pair<int,int> &a,const pair<int,int> &b)
{
    return (a.second < b.second);
}

void solve()
{
	ll strength, intelligence, free_points;
	ll diff;
	ll limit;

	cin >> strength >> intelligence >> free_points;

	if (strength <= intelligence)
	{
		diff = intelligence - strength + 1;
		if (diff > free_points)
		{
			cout << 0 << endl;
			return;
		}
		free_points -= diff;
		strength += diff;
	}
	else if (free_points == 0)
	{
		cout << 1 << endl;
		return;
	}

	limit = (intelligence + free_points - strength+2)/2 ;
	cout << free_points - limit + 1 <<endl;
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
	no_of_test_cases=1;
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
