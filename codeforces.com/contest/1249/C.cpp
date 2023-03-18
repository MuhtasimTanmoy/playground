//https://codeforces.com/contest/1249//problem/C
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

#define debug(x) cout << x << endl;

const int N = 2e5 + 11;
void solve()
{
	ll n;
	cin >> n;

	ll sum = 1;

	ll power = 0;

	while (sum < n)
	{
		sum = (1 - pow(3, power)) / -2;
		power++;
	}

	ll toSubstract = 0;

	while (power!=-1)
	{

		toSubstract = pow(3, power);
		if (sum - toSubstract >= n)
		{
			sum -= toSubstract;
		}
		power--;
	}

	cout<<sum<<endl;
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
