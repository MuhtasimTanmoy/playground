//https://1312/problem/B
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;
int a[N];

void solve()
{
	int n;
	cin>>n;
	for (int i = 0; i < n; i++){
		cin>>a[i];
	}

	sort(a, a+n, greater<int>());

	for (int i = 0; i < n; i++){
		cout<<a[i]<<" ";
	}

	cout<<endl;
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
