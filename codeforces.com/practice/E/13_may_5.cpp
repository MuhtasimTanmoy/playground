#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

void solve()
{
	double n,m,a,b;
	cin>>n>>m>>a>>b;

	int count = n/m;
	int res = 0;

	if(b/m<=a){
		res+=b*count;
		n-=m*count;
		res+= min(a * n, b * n);
	}
	else{
		res+= a * n;
	}

	
	cout<<res<<endl;
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
