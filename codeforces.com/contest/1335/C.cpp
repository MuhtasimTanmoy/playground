//https://1335/problem/C
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

int cache[10000];
int recur(int n)
{	
	if(cache[n]!=-1){
		return cache[n];
	}

	if (n == 4)
	{
		return 523;
	}
	else if (n == 3)
	{
		return 420;
	}
	else if (n == 2)
	{
		return 375;
	}
	else if (n == 1)
	{
		return 211;
	}

	int res = (recur(n - 1) - recur(n-2) + recur(n-3) - recur(n-4));

	if(cache[n]==-1){
		cache[n]=res;
	}

	return res;
}
void solve()
{
	for (int i = 0; i < 10000; i++)
	{
		cache[i] = -1;
	}

	cout << recur(531)+recur(753)+recur(975) << endl;
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
