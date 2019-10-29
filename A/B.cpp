//https://A/problem/B
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

int count_one_function(string s)
{
	int count = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i]=='1')
		{
			count++;
		}
	}
	return count;
}

void solve()
{
	int n;
	cin >> n;

	string li[n];
	bool possible = true;
	for (int i = 0; i < n; i++)
	{
		cin >> li[i];
	}

	int size = 0;
	int count_one = 0;

	for (int i = 0; i < n; i++)
	{
		size = li[i].size();
		count_one = count_one_function(li[i]);

		if (size % 2==0)
		{
			if (count_one % 2)
			{
				possible = !possible;
			}
		}
		else{
			possible = true;
			break;
		}
	}

	cout << (possible ? n : n - 1) << endl;
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
