//https://codeforces.com/contest/2041//problem/A
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;

const int N = 2e5 + 11;

void solve()
{
	int n;
	cin>>n;


	string s;
	cin>>s;

	int lCount = 0;

	for (int i = 0; i < s.size(); i++){
		if(s[i] == 'L'){
			lCount++;
		}
	}

	cout<< lCount + s.size()-lCount + 1<<endl;
	
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
