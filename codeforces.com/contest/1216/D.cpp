//https://codeforces.com/contest/1216/problem/D
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


// inline int gcd(int a, int b) {
// 	while (a != 0 && b != 0) {
// 		if (a > b) {
// 			a %= b;
// 		} else {
// 			b %= a;
// 		}
// 	}
// 	return max(a, b);
// }

template <typename T>
T gcd(T x, T y)
{
	if (y == 0)
	{
		return x;
	}
	return gcd(y, x % y);
}

void solve()
{
	ll n;
	ll holder;
	vector<ll> li;
	vector<ll> diff;
	cin >> n;
	REP(i, n)
	{
		cin >> holder;
		li.push_back(holder);
	}

	ll max_elem = *max_element(li.begin(), li.end());

	ll limit = n * max_elem;

	ll deficit = 0;
	REP(i, n)
	{
		if (li[i] != max_elem)
		{
			diff.push_back(max_elem - li[i]);
			deficit += (max_elem - li[i]);
		}
	}

	ll gcd_of_list = diff[0];

	REP(i, diff.size())
	{
		gcd_of_list = gcd<ll>(gcd_of_list, diff[i]);
	}

	ll y;
	y = deficit / gcd_of_list;
	while (deficit % gcd_of_list != 0)
	{
		gcd_of_list/=2;
		y = deficit / gcd_of_list;
	}

	cout << y << " " << gcd_of_list << endl;
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
