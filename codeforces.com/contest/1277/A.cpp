//https://codeforces.com/contest/1277/problem/A
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e5 + 10;

ll li[N];

void solve()
{
	string s;
	cin >> s;

	ll num = stoll(s);

	long long builder = 1;
	long long offset = 0;

	int base = (s.size() - 1) * 9;

	if (base == 0)
	{
		cout << num << endl;
		return;
	}

	for (int i = 0; i < s.size()-1; i++)
	{
		builder = builder * 10 + 1;
	}

	offset = builder;

	while (builder <= num)
	{
		base++;
		builder += offset;
	}

	cout << base << endl;
}

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int no_of_test_cases;
	cin >> no_of_test_cases;
	// no_of_test_cases = 1;
	while (no_of_test_cases--)
	{
		solve();
	}

	return 0;
}
