//https://codeforces.com/contest/1230/problem/D
#include <bits/stdc++.h>
#define _DEBUG
#define ll long long
#define ull unsigned long long int
#define pb push_back
#define REP(i, n) for (int i = 0; i < (int)n; i++)
#define REPI(i,j, n) for (int i = j; i < (int)n; i++)
#define x first
#define y second
using namespace std;

///REFll

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int INF = 2e9;
const ll INF64 = 1e18;
const int M = 2 * 1000 * 1000;
const int N = 300 * 1000 + 100;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double PI = 3.14159265359;

template <typename T>
T gcd(T x, T y)
{
	if (y == 0)
	{
		return x;
	}
	return gcd(y, x % y);
}

bool sortbysec(const pair<ll, ll> &a, const pair<ll, ll> &b)
{
	return (a.first > b.first);
}

void solve()
{
	int n;
	cin >> n;

	vector<pll> li;

	REP(i, n)
	{
		li.push_back(make_pair(0, 0));
	}

	REP(i, n)
	{
		cin >> li[i].x;
	}

	REP(i, n)
	{
		cin >> li[i].y;
	}

	sort(li.begin(), li.end(), sortbysec);

	REP(i, n)
	{
		cout << li[i].first << " " << li[i].second << endl;
	}

	bool found = false;

	ull sum=0;

	for(int i=0;i<n-1;i++)
	{
		sum = li[i].y;
		for(int j=i+1;j<n;j++)
		{
			if ((li[i].x ^ li[j].x)==0){
				found = true;
			}
			sum+=li[j].y;
		}
		if(found){
			cout<<sum<<endl;
			return;
		}
	}

	cout<<0<<endl;
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
