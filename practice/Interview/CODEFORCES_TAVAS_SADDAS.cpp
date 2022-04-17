// https://codeforces.com/problemset/problem/535/B

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

void solve()
{
	string num;
	cin >> num;

	int len = num.size();
	int add_all = len;

	ll offset = 0;
	while (add_all--)
	{
		offset += (1 << add_all);
	}

	for (int i = 0; i < len; i++)
	{
		if (num[i] == '7')
		{
			offset += (1 << (len - i - 1));
		}
	}

	cout << offset << endl;
}

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int no_of_test_cases;
	// cin >> no_of_test_cases;
	no_of_test_cases = 1;
	while (no_of_test_cases--)
	{
		solve();
	}

	return 0;
}
