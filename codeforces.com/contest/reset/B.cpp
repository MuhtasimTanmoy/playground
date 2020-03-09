//https://reset/problem/B
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

int li[N];

void solve()
{
	int n;
	cin >> n;

	int sum = 0;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> li[i];
		if (li[i] != -1)
		{
			sum += li[i];
			count++;
		}
	}

	if (count == 0)
	{
		cout << 0 << " " << 0 << endl;
		return;
	}

	int one = ((sum + count - 1) / count);
	int two = (sum / count);

	int _maxOne = 0;
	int _maxTwo = 0;

	int num = 0;

	int toBe = 0;

	for (int i = 0; i < n - 1; i++)
	{
		_maxOne = max(_maxOne, abs((li[i] == -1 ? one : li[i]) - (li[i + 1] == -1 ? one : li[i + 1])));
	}
	if (one != two)
	{
		for (int i = 0; i < n - 1; i++)
		{
			_maxTwo = max(_maxTwo, abs((li[i] == -1 ? two : li[i]) - (li[i + 1] == -1 ? two : li[i + 1])));
		}
	}

	if (one != two)
	{
		if(_maxOne>_maxTwo){
			_maxOne = _maxTwo;
			one=two;
		}

		cout << _maxOne << " " << one << endl;
		return;
	}

	cout << _maxOne << " " << one << endl;
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
