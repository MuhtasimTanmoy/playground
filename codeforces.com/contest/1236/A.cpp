//https://codeforces.com/contest/1236/problem/A
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
	int a, b, c;
	cin >> a >> b >> c;

	int count = 0;

	int first_half = min(b>>1,a);
	first_half += min(b-(first_half<<1),c>>1);


	int second_half = min(c>>1,b);
	second_half += min((b-second_half)>>1,a);


	count = max(first_half,second_half);

	cout<<count*3<<endl;
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
