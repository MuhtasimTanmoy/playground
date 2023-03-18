#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

typedef struct A
{
	int val;
	int index;
} val_with_index;

void solve()
{
	int n;
	cin >> n;

	val_with_index holder;
	val_with_index _max;
	val_with_index _min;

	_max.val = -1;
	_min.val = 110;

	for (int i = 0; i < n; i++)
	{
		cin >> holder.val;
		holder.index = i + 1;
		if (holder.val > _max.val)
		{
			_max = holder;
		}
		if (holder.val < _min.val)
		{
			_min = holder;
		}
	}

	cout << (_max.index < _min.index ? _max.val : _min.val);
	cout << " ";
	cout << (_max.index < _min.index ? _min.val : _max.val);
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
