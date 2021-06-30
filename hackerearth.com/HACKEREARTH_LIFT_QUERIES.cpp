#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 7;

int current_ground = 0;
int current_top = 7;

void solve()
{
	int called_from;
	cin >> called_from;

	if (abs(called_from - current_ground) <= abs(current_top - called_from))
	{
		current_ground = called_from;
		cout << "A" << endl;
	}
	else
	{
		current_top = called_from;
		cout << "B" << endl;
	}
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
