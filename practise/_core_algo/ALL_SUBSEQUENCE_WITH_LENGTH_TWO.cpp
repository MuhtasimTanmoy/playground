#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

int n;
int li[10];

void subs(vector<int> v, int k)
{
	if (k > n)
	{
		return;
	}
	else if (v.size() == 2)
	{
		for (auto x : v)
		{
			cout << x << " ";
		}
		cout << endl;
	}
	else
	{
		subs(v, k + 1);
		v.push_back(li[k]);
		subs(v, k + 1);
		v.pop_back();
	}
}

void solve()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> li[i];
	}

	vector<int> sub;
	subs(sub, 0);
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
