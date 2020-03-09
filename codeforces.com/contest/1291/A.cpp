//https://1291/problem/A
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

bool check_if_ebne(string s)
{
	bool sumEven = 1;
	for (char c : s)
	{
		if ((c - '0') % 2 == 1)
		{
			sumEven = 1 - sumEven;
		}
	}
	return sumEven && (s[s.size() - 1] - '0') % 2;
}

void solve()
{
	int n;
	cin >> n;

	string s;
	cin >> s;

	int index_to_delete_from_back = s.size();
	int foundOddAt = 0;

	if (check_if_ebne(s))
	{
		cout << s << endl;
		return;
	}
	else if (s.size() <= 2)
	{
		cout << -1 << endl;
		return;
	}
	else
	{
		while (index_to_delete_from_back--)
		{
			if ((s[index_to_delete_from_back] - '0') % 2)
			{
				break;
			}
		}

		if (index_to_delete_from_back < 1)
		{
			cout << -1 << endl;
			return;
		}	
		else
		{
			foundOddAt = index_to_delete_from_back;
			while (foundOddAt--)
			{
				if ((s[foundOddAt] - '0') % 2)
				{
					break;
				}
			}
		}
	}


	for(int i=foundOddAt;i<=index_to_delete_from_back;i++){
		cout<<s[i];
	}
	cout<<endl;
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
