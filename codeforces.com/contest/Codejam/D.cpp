//https://Codejam/problem/D
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
	cout << "Case #" << case_count << ": ";
	case_count++;

	int n, k;
	cin >> n >> k;

	if (k % n != 0)
	{
		cout << "IMPOSSIBLE" << endl;
		return;
	}

	cout << "POSSIBLE" << endl;
	int trace_num = k / n;
	int alter = 0;

	vector<int> list;
	for (int i = 1; i <= n; i++){
		if(i!=trace_num){
			list.push_back(i);
		}
	}

	int iterator = 0;
	for (int i = 0; i < n; i++)
	{
		iterator = 0;
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				cout << trace_num << " ";
				continue;
			}
			else
			{	
				cout<<list[(iterator+i)%(n-1)]<<" ";
				iterator++;
			}
		}
		alter = 1 - alter;
		cout << endl;
	}
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
