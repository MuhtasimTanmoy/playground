#include <bits/stdc++.h>
using namespace std;
// https://codeforces.com/contest/490/problem/A
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

	vector< vector<int> > li(4); 
	int holder;
	for (int i = 0; i < n; i++){
		cin>>holder;
		li[holder].push_back(i+1);
	}

	int possible_number_of_teams = min(li[1].size(), min(li[2].size(),li[3].size()));

	cout<<possible_number_of_teams<<endl;

	for (int i = 0; i < possible_number_of_teams; i++){
		cout<< li[1][i]<< " "<< li[2][i] << " "<<li[3][i]<<endl;
	}
	
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
