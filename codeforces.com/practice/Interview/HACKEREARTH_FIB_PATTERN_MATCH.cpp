#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

long long fib[80];
string fib_s;
bool valid[700];
void generate_fib()
{
	fib[0] = 0;
	fib[1] = 1;
	fib_s = "01";
	valid[0] = valid[1] = true;
	for (int i = 2; i < 80; i++)
	{
		fib[i] = fib[i - 1] + fib[i - 2];
		fib_s += to_string(fib[i]);
		valid[fib_s.length() - 1] = true;
	}
	//cout << fib_s.length() << endl;
}

void solve()
{
	generate_fib();
	cout << fib_s << endl;
}

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int no_of_test_cases = 0;
	// cin >> no_of_test_cases;
	if (!no_of_test_cases)
		no_of_test_cases = 1;
	while (no_of_test_cases--)
	{
		solve();
	}

	return 0;
}
