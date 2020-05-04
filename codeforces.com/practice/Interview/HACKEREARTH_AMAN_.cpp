#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;
int choclate = 0;

void solve()
{
	int rad, horlics;
	cin >> rad >> horlics;

	if ((2 * 22 * rad) / 7 <= 100 * horlics)
		choclate++;
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

	cout << choclate << endl;

	return 0;
}
