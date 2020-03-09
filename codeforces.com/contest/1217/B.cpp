//https://1217/problem/B
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

void solve()
{
	ll num;
	cin >> num;

	ll cache_num = num;

	ll result = 0;
	ll redundent = 0;

	int toAdd = 0;

	while (true)
	{
		toAdd = num /10;
		result += toAdd;
		redundent = num % 10;
		num = toAdd + redundent;
		if(num<10)break;
	}

	cout << result + cache_num << endl;
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
