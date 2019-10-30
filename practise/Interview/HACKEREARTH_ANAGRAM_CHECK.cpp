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
	string a, b;
	cin >> a >> b;

	int char_map[26];
	for (int i = 0; i < 26; i++)
	{
		char_map[i] = 0;
	}

	for (int i = 0; i < a.size(); i++)
	{
		char_map[a[i] - 'a']++;
	}

	for (int i = 0; i < b.size(); i++)
	{
		char_map[b[i] - 'a']--;
	}

	int count = 0;

	for (int i = 0; i < 26; i++)
	{
		if (char_map[i] != 0)
		{
			count+=abs(char_map[i]);
		}
	}

	cout << count << endl;
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
