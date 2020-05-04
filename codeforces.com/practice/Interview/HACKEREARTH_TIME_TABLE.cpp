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
	int start_hour, start_min, end_hour, end_min;
	cin >> start_hour >> start_min >> end_hour >> end_min;

	bool hour_adjust = false;

	int duration_min = abs(end_min - start_min);
	if (start_min > end_min)
	{
		hour_adjust = true;
		duration_min = 60 - duration_min;
	}

	int duration_hour = abs(end_hour - start_hour);
	if (hour_adjust)
	{
		if (start_hour > end_hour)
			duration_hour++;
		else
		{
			duration_hour--;
		}
	}
	if (start_hour > end_hour)
		duration_hour = 12 - duration_hour;

	cout << duration_hour << " " << duration_min << endl;
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
