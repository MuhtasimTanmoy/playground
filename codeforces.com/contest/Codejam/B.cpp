//https://Codejam/problem/B
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;
int case_count = 1;

void solve()
{
	string s;
	cin >> s;

	string result = "";

	int current_number = 0;

	int offset = 0;

	int prev = 0;

	for (int i = 0; i < s.size(); i++)
	{

		current_number = s[i] - '0';
		offset = current_number - prev;

		if (offset > 0)
		{
			for (int j = 0; j < offset; j++)
			{
				result += "(";
			}
		}

		if (offset < 0)
		{
			offset = abs(offset);

			for (int j = 0; j < offset; j++)
			{
				result += ")";
			}
		}

		result += s[i];

		prev = current_number;
	}

	// End calculate
	for (int j = 0; j < prev; j++)
	{
		result += ")";
	}

	cout<< "Case #"<<case_count<< ": ";
	case_count++;
	cout << result << endl;
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
