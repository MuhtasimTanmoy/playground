//https://codeforces.com/contest/1216/problem/B
#include <bits/stdc++.h>
#define _DEBUG
#define ll long long
#define pb push_back
#define REP(i, n) for (int i = 0; i < (int)n; i++)
#define REP1(i, n) for (int i = 1; i < (int)n; i++)

using namespace std;

bool sortbysec(const pair<int, int> &a, const pair<int, int> &b)
{
	return (a.second > b.second);
}

void solve()
{
	int n;
	cin >> n;


	int holder;

	vector<pair<int, int>> li;

	REP(i, n)
	{
		cin >> holder;
		li.push_back(make_pair(i + 1, holder));
	}

	sort(li.begin(), li.end(), sortbysec);

	int sum=0;
	REP(i,n){
		sum+=li[i].second*i+1;
	}

	cout<<sum<<endl;

	REP(i, n)
	{
		cout << li[i].first << " ";
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
