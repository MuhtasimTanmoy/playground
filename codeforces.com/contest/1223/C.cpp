//https://codeforces.com/contest/1223/problem/C
#include <bits/stdc++.h>
#define _DEBUG
#define ll long long
#define pb push_back
#define x first
#define y second
using namespace std;
typedef pair<int, int> pii;

ll n;
ll elem[200001], x, a, y, b, k;

bool check(int checkTill)
{
	vector<ll> li;
	for (int i = 1; i <= checkTill; i++)
	{
		int product = 0;
		if (i % a == 0)
		{
			product += x;
		}
		if (i % b == 0)
		{
			product += y;
		}
		li.push_back(product);
	}
	sort(li.rbegin(), li.rend());
	ll sum = 0;
	for (int i = 1; i <= checkTill; i++)
	{
		sum += li[i - 1] * elem[i];
	}
	return sum >= k;
}

void solve()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> elem[i];
		elem[i] /= 100;
	}
	cin >> x >> a >> y >> b >> k;
	sort(elem + 1, elem + n + 1);
	reverse(elem + 1, elem + n + 1);

	if (!check(n))
	{
		cout << "-1
";
		return;
	}

	int high = n;
	int low = 1;

	while (high - low > 0)
	{
		int mid = (low + high) >> 1;
		if (check(mid))
		{
			high = mid;
		}
		else
		{
			low = mid+1;
		}
	}

	cout << high << endl;
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
