#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 310;

string li[N];
int lin[N];

void solve()
{
	// int n;
	// cin >> n;

	// for (int i = 0; i < n; i++)
	// {
	// 	cin >> li[i];
	// }

	// for (int i = 0; i < n; i++)
	// {
	// 	for (char s : li[i])
	// 	{
	// 		lin[i] += s - '0';
	// 	}
	// }

	// for (int i = 0; i < n; i++)
	// {
	// 	cout<<lin[i]<<" ";
	// }

	int digit_count, digit_sum;
	cin >> digit_count >> digit_sum;

	if (digit_count > 1 && (!digit_sum))
	{
		cout << -1 << " " << -1;
		return;
	}

	if (digit_sum > digit_count * 9)
	{
		cout << -1 << " " << -1;
		return;
	}

	string _max = "";
	int iter = digit_sum;
	int chosen;
	for (int i = 0; i < digit_count; i++)
	{
		chosen = iter >= 9 ? 9 : max(iter, 0);
		iter -= chosen;
		_max += '0' + chosen;
	}

	bool decrease_one = false;

	if (_max[digit_count - 1] == '0' && digit_sum > 0)
	{
		cout << 1;
		decrease_one = true;
	}
	else
	{
		cout << _max[digit_count - 1];
	}

	for (int i = digit_count - 2; i >= 0; i--)
	{
		if (decrease_one && _max[i] != '0')
		{
			decrease_one = false;
			cout << (char)(_max[i] - 1);
		}
		else
		{
			cout << _max[i];
		}
	}

	cout << " ";

	cout << _max;
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
