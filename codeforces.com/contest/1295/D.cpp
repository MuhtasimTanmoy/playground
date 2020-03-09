//https://1295/problem/D
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

int gcd(int a, int b)
{
	if(b==0) return a;
	else return gcd(b, a % b);
}

void solve()
{
	int a, m;
	cin >> a >> m;

	int x = 1;

	int gcd_res = gcd(a,m);

	for (int i = 1; i < m; i++)
	{
		if(gcd_res == gcd(a+i,m)){
			x++;
		}
	}

	cout<<x<<endl;
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
