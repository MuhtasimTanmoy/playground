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
	int n, k;
	cin >> n >> k;

	int l, r;

	vector<int> li(n);

	for (int i = 0; i < k; i++)
	{
		cin >> l >> r;
		li[l]++;
		li[r + 1]--;
	}
	int sum = li[0];
	int max = INT32_MIN;
	vector<int> index;
	for (int i = 1; i < n; i++)
	{
		sum += li[i];
		if (sum >= max)
		{
			if (max == sum)
			{
				index.push_back(i);
			}
			else
			{
				index.clear();
				index.push_back(i);
			}
			max = sum;
		}
	}
	cout << max << endl;
	for (int i = 0; i < index.size(); i++)
	{
		cout << index[i] << " ";
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
