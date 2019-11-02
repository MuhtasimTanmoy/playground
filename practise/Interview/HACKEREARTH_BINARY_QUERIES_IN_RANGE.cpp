#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;

void solve()
{
	int n, Q;
	cin >> n >> Q;

	int word[N];

	for (int i = 0; i < n; i++)
	{
		cin >> word[i];
	}

	bool type = 0;

	int index = 0;
	int from, to;

	for (int i = 0; i < Q; i++)
	{
		cin >> type;

		if (type)
		{
			cin >> index;
			word[index - 1] = 1 - word[index - 1];
		}
		else
		{
			cin >> from >> to;
			cout << (word[to - 1] ? "ODD" : "EVEN") << endl;
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
