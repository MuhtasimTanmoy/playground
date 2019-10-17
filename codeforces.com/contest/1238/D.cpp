//https://codeforces.com/contest/1238/problem/D
#include <bits/stdc++.h>
#define _DEBUG
#define ll long long
#define pb push_back
#define REP(i, n) for (int i = 0; i < (int)n; i++)
#define REPI(i, a, b) for (int i = (a); (i <= (b)); ++i)
#define x first
#define y second
using namespace std;

const int N = 3e5 + 5;

///REF PII

typedef pair<int, int> pii;

const int INF = 2e9;
const ll INF64 = 1e18;
const int M = 2 * 1000 * 1000;
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

bool sortbysec(const pair<int, int> &a, const pair<int, int> &b)
{
	return (a.second < b.second);
}

string s;

bool checkPalindrome(int start, int end)
{
	while (start < end)
	{
		if (s[start] != s[end])
		{
			return false;
		}
		start++;
		end--;
	}
	return true;
}

void solve()
{
	ll n;
	cin >> n;

	cin >> s;
	n = s.length();

	ll count = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (checkPalindrome(i, j))
			{
				cout << s.substr(i, j) << endl;
				count++;
			}
		}
	}
}

ll ans;
char c[N];
int n, now;

int main()
{
	freopen("input.txt", "r", stdin);

	ll n;
	cin >> n;

	cin >> s;
	n = s.length();
	ans = 1ll * n * (n + 1) / 2 - n;
	now = 1;
	for (register int i = 2; i <= n; i++)
	{
		if (s[i] == s[i - 1])
			++now;
		else
			ans -= now, now = 1;
	}
	now = 1;
	for (register int i = n - 1; i >= 1; i--)
	{
		if (s[i] == s[i + 1])
			++now;
		else
			ans -= now, now = 1;
	}
	for (register int i = 1; i < n; i++)
		if (s[i] != s[i + 1])
			++ans;
	cout << ans << endl;
	return 0;
}
