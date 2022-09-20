#include <bits/stdc++.h>
#define _DEBUG
#define ll long long
#define pb push_back
#define REP(i, n) for (int i = 0; i < (int)n; i++)
#define REPI(i, a, b) for (int i = (a); (i <= (b)); ++i)
#define x first
#define y second
using namespace std;

///REF PII

typedef pair<int, int> pii;

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

bool sortbysec(const pair<int, int> &a, const pair<int, int> &b)
{
	return (a.second < b.second);
}

int n;

void pritnALlParenthesis(string res, int open, int close)
{

	// cout << res << " " << open << " " << close << endl;

	if (close == n)
	{
		cout << res << endl;
	}
	else
	{
		if (close < open)
		{
			while (close < open)
			{
				res += ')';
				close++;
			}
			pritnALlParenthesis(res, open, open);
		}
		else
		{
			for (int i = open + 1; i <= n; i++)
			{
				res += '(';
				pritnALlParenthesis(res, i, close);
			}
		}
	}
}

void generateParenthesis(string s, int open, int close)
{

	if (open == 0 && close == 0)
	{
		cout << s << endl;
	}

	if (open > close)
		return;

	if (open > 0)
	{
		generateParenthesis(s + '(', open - 1, close);
	}

	if (close > 0)
	{
		if (open < close)
		{
			generateParenthesis(s + ')', open, close - 1);
		}
	}
}

void solve()
{
	cin >> n;

	// pritnALlParenthesis("", 0, 0);

	generateParenthesis("", n, n);
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
