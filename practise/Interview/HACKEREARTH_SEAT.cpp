#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

// https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/seating-arrangement-1/

const int N = 2e5 + 11;

void solve()
{
	int number;
	cin >> number;

	int segmented = ((number % 12) ? number % 12 : 12);
	int padded = 13 - segmented;

	unordered_map<int, string> seat;
	seat[1] = seat[6] = seat[7] = seat[12] = "WS";
	seat[2] = seat[5] = seat[8] = seat[11] = "MS";
	seat[3] = seat[4] = seat[9] = seat[10] = "AS";

	cout << number + padded - segmented << " " << seat[segmented] << endl;
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
