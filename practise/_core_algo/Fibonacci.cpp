#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e9 + 7;

int fib(int n)
{
	int li[n + 1];
	li[0] = 0;
	li[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		li[i] = li[i - 1] + li[i - 2];
	}

	return li[n];
}

int fib_formula(int n)
{
	float five = sqrt(5);
	return (pow((1 + five), n) + pow((1 - five), n)) / (pow(2, n) * five);
}

void solve()
{
	cout << fib(6) << endl;
	cout << fib_formula(6) << endl;
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
