//https://codeforces.com/contest/1041//problem/D
// #include <bits/stdc++.h>
// using namespace std;

// #define ll long long
// #define ff first
// #define ss second
// #define mp make_pair
// #define pb push_back

// const int N = 2e5 + 11;

// int diffs_in_between[N];
// int diffs_in_between_cumulative[N];

// pair<int, int> hotspot_range[N];
// ll hotspot_range_cumulative[N];

// void solve()
// {
// 	int no_of_hotspot, current_height;
// 	cin >> no_of_hotspot >> current_height;

// 	ll cumulative = 0;

// 	int left, right;

// 	for (int i = 0; i < no_of_hotspot; i++)
// 	{
// 		cin >> left >> right;
// 		hotspot_range[i] = {left, right};
// 		hotspot_range_cumulative[i + 1] += (i == 0 ? 0 : hotspot_range_cumulative[i - 1]) + (right - left);
// 	}

// 	for (int i = 0; i <= no_of_hotspot; i++)
// 	{
// 		cout << hotspot_range_cumulative[i] << " ";
// 	}
// 	cout << endl;

// 	for (int i = 1; i < no_of_hotspot; i++)
// 	{
// 		diffs_in_between[i - 1] = hotspot_range[i].first - hotspot_range[i - 1].second;
// 	}

// 	for (int i = 1; i < no_of_hotspot; i++)
// 	{
// 		cout << diffs_in_between[i - 1];
// 	}

// 	cout << endl;

// 	for (int i = 0; i < no_of_hotspot - 1; i++)
// 	{
// 		diffs_in_between_cumulative[i] = (i == 0 ? 0 : diffs_in_between_cumulative[i - 1]) + diffs_in_between[i];
// 	}

// 	for (int i = 0; i < no_of_hotspot - 1; i++)
// 	{
// 		cout << diffs_in_between_cumulative[i];
// 	}
// }

// int main()
// {
// 	freopen("input.txt", "r", stdin);
// 	ios_base::sync_with_stdio(0);
// 	cin.tie(0);
// 	cout.tie(0);
// 	int no_of_test_cases;
// 	// cin >> no_of_test_cases;
// 	no_of_test_cases = 1;
// 	while (no_of_test_cases--)
// 	{
// 		solve();
// 	}

// 	return 0;
// }

#include <bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for (int i = int(l); i < int(r); i++)

#define x first
#define y second

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9;

const int N = 200 * 1000 + 555;

int n, h;
pt a[N];

inline bool read()
{
	if (!(cin >> n >> h))
		return false;
	fore(i, 0, n)
		assert(scanf("%d%d", &a[i].x, &a[i].y) == 2);
	sort(a, a + n);
	return true;
}

int ps[N];

int getH(int lf, int rg)
{
	int l = int(lower_bound(a, a + n, pt(lf, -1)) - a);
	int r = int(lower_bound(a, a + n, pt(rg, -1)) - a);

	int sum = ps[r] - ps[l];
	if (l > 0)
		sum += max(0, a[l - 1].y - lf);

	assert(rg - lf - sum >= 0);
	return rg - lf - sum;
}

inline void solve()
{
	ps[0] = 0;
	fore(i, 0, n)
		ps[i + 1] = ps[i] + (a[i].y - a[i].x);

	int ans = 0;
	fore(i, 0, n)
	{
		int lx = a[i].y + 1;

		int lf = -(h + 1), rg = lx;
		while (rg - lf > 1)
		{
			int mid = (lf + rg) / 2;
			if (getH(mid, lx) > h)
				lf = mid;
			else
				rg = mid;
		}
		assert(getH(rg, lx) == h);
		ans = max(ans, lx - rg);
	}
	cout << ans << endl;
}

int main()
{
	freopen("input.txt", "r", stdin);

	if (read())
	{
		solve();
	}
	return 0;
}
