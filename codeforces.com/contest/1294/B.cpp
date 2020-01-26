//https://codeforces.com/contest/1294/problem/B
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

typedef struct point
{
	int x;
	int y;
} point;

bool compare(point x, point y)
{
	return (x.x == y.x ? x.y < y.y : x.x < y.x);
}

void solve()
{
	int num_of_packages;
	cin >> num_of_packages;

	point points[num_of_packages];

	string result_path = "";

	for (int i = 0; i < num_of_packages; i++)
	{
		cin >> points[i].x >> points[i].y;
	}

	sort(points, points + num_of_packages, compare);

	point curr;
	curr.x = 0;
	curr.y = 0;

	int left_to_go;
	int right_to_go;

	for (int i = 0; i < num_of_packages; i++)
	{
		left_to_go = points[i].x - curr.x;
		right_to_go = points[i].y - curr.y;

		if (left_to_go < 0 || right_to_go < 0)
		{
			cout << "NO" << endl;
			return;
		}

		curr.x += left_to_go;
		curr.y += right_to_go;

		while (left_to_go--)
		{
			result_path += 'R';
		}

		while (right_to_go--)
		{
			result_path += 'U';
		}
	}
	cout<<"YES"<<endl;
	cout << result_path << endl;
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
