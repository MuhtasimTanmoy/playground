//https://codeforces.com/contest/1249//problem/A
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 101;

void solve()
{
	int n;
	cin >> n;

	int holder;

	bool li[101]={false};

	for (int i = 0; i < n; i++)
	{
		cin>>holder;
		li[holder]=true;
	}

	bool oneNeeded = true;

	for(int i=1;i<101;i++){
		if(li[i-1]==li[i] && li[i]){
			oneNeeded=false;
			break;
		}
	}

	cout<<(oneNeeded?1:2)<<endl;
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
