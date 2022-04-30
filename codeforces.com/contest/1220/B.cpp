// https://codeforces.com/contest/1220/problem/B
#include <bits/stdc++.h>
#define _DEBUG
#define ll long long
#define pb push_back
#define REP(i, n) for (int i = 0; i < (int)n; i++)
#define REP1(i, n) for (int i = 1; i < (int)n; i++)

using namespace std;

bool sortbysec(const pair<int, int> &a, const pair<int, int> &b)
{
	return (a.second < b.second);
}

ll arr[1010][1010	];

void solve()
{
	int n;
	cin >> n;

	vector<int> res;
	ll singleRowResult;
	ll holder;

	REP(i, n)
	{
		REP(j, n)
		{
			cin >> arr[i][j];
		}
	}


	ll j = sqrt((arr[1][2] *arr[0][1])/arr[0][2]);

	ll first = round(arr[0][1]/j);

	res.push_back(first);

	REP1(i,n){
		res.push_back((arr[0][i]/first));
	}

	REP(i,n){
		cout<<res[i]<<" ";
	}
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
