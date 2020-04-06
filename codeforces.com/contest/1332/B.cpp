//https://1332/problem/B
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 26;
int char_count[N];

void solve()
{
	int n, k;
	cin >> n >> k;

	string s;
	cin >> s;

	int count = 0;

	for (int i = 0; i < n; i++)
	{
		char_count[s[i] - 'a']++;
	}

	int segments = n / k;
	int first_index = 0;
	int second_index = 0;

	for (int i = 0; i < segments-1; i++)
	{
		for (int j = 0; j < k/2 + 1; j++)
		{
			first_index = j;
			second_index = (i+1) * k - j + k;

			if (s[first_index] != s[second_index])
			{
				if (char_count[s[first_index]-'a'] > char_count[s[second_index]-'a'])
				{
					s[second_index] = s[first_index];
				}
				else
				{
					s[first_index] = s[second_index];
				}
				count++;
			}
		}
	}
	cout<<s<<endl;

	cout << count << endl;
}

int main()
{
	freopen("input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	int no_of_test_cases = 0;
	cin >> no_of_test_cases;
	if (!no_of_test_cases)
		no_of_test_cases = 1;
	while (no_of_test_cases--)
	{
		solve();
	}

	return 0;
}
