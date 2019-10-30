#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

void solve()
{
	int min_dimen;
	cin >> min_dimen;

	int test_cases;
	cin >> test_cases;

	int W, H;

	while (test_cases--)
	{
		cin >> W >> H;
		if (W < min_dimen || H < min_dimen)
		{
			cout << "UPLOAD ANOTHER" << endl;
		}
		else if (W >= min_dimen && H >= min_dimen)
		{
			if (W == H)
			{
				cout << "ACCEPTED" << endl;
			}
			else
			{
				cout << "CROP IT" << endl;
			}
		}
	}
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
