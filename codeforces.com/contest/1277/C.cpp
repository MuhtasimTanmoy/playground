//https://codeforces.com/contest/1277/problem/C
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

string s;
vector<int> v;
bool lastIndex = false;

int *pre_kmp(string pattern)
{

	// k means the pattern length
	int size = pattern.size();
	int *pie = new int[size];
	pie[0] = 0;
	int k = 0;

	for (int i = 1; i < size; i++)
	{
		while (k > 0 && pattern[k] != pattern[i])
		{
			k = pie[k - 1];
		}
		if (pattern[k] == pattern[i])
		{
			k = k + 1;
		}
		pie[i] = k;
	}

	return pie;
}

void kmp(string text, string pattern)
{
	int *pie = pre_kmp(pattern);
	int matched_pos = 0;
	int matched_first_index = 0;
	for (int current = 0; current < text.length(); current++)
	{
		while (matched_pos > 0 && pattern[matched_pos] != text[current])
			matched_pos = pie[matched_pos - 1];

		if (pattern[matched_pos] == text[current])
			matched_pos = matched_pos + 1;

		if (matched_pos == (pattern.length()))
		{
			if (!lastIndex)
			{
				matched_first_index = current - (pattern.length() - 1);
			}
			else
			{
				matched_first_index = current;
			}
			s[matched_first_index] = ' ';
			v.push_back(matched_first_index + 1);
			matched_pos = pie[matched_pos - 1];
		}
	}
}

void solve()
{
	cin >> s;
	v.clear();

	string match = "one";
	string match2 = "two";

	kmp(s, match);
	lastIndex = true;
	kmp(s, match2);

	cout << v.size() << endl;

	for (auto x : v)
	{
		cout << x << " ";
	}

	cout << endl;
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
