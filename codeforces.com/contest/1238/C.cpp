//https://codeforces.com/contest/1238/problem/C
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
	ll h, n;
	ll moved_out_platform_height[N] = {0};

	cin >> h >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> moved_out_platform_height[i];
	}

	ll height = moved_out_platform_height[0];
	ll height_index = 0;

	ll magic = 0;

	if (n == 1)
	{
		cout << 0 << endl;
		return;
	}
	else if (n == 2)
	{
		if (height - moved_out_platform_height[height_index + 1] >= 1)
		{
			if (moved_out_platform_height[height_index + 1] > 1)
			{
				magic++;
			}
		}
		cout << magic << endl;
	}
	else
	{
		while (height != 1 && height != 2)
		{
			if (height - moved_out_platform_height[height_index + 1] == 1)
			{
				if (height - moved_out_platform_height[height_index + 2] == 2)
				{
					height -= 2;
					height_index += 2;
				}
				else
				{
					height -= 2;
					height_index++;
					magic++;
				}
			}
			else
			{
				height = moved_out_platform_height[height_index + 1] + 1;
			}
		}

		cout << magic << endl;
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
