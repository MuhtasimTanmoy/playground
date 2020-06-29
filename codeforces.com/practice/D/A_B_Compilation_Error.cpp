#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/contest/519/problem/B

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

void solve()
{
	int n;
	cin>>n;

	int calculator =0;
	int holder;

	for (int i = 0; i < n; i++){
		cin>>holder;
		calculator^=holder;
	}

	int cache = calculator;
	for (int i = 0; i < n-1; i++){
		cin>>holder;
		calculator^=holder;
	}
	cout<<calculator<<endl;


	calculator = cache ^ calculator;
	for (int i = 0; i < n-2; i++){
		cin>>holder;
		calculator^=holder;
	}
	cout<<calculator<<endl;
}

int main()
{
	freopen("input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	int no_of_test_cases = 0;
	// cin >> no_of_test_cases;
	if (!no_of_test_cases)
		no_of_test_cases = 1;
	while (no_of_test_cases--)
	{
		solve();    
	}

	return 0;
}
