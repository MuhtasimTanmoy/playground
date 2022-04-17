#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

int gcd(int a,int b){
	if(b==0) return a;
	return gcd(b,a%b);
}

void solve()
{
	int a,b,n;
	cin>>a>>b>>n;

	int take = 0;
	int turn = 0;

	bool simonPass = 1;

	while(n!=0){
		turn = (simonPass? a:b);
		take = gcd(turn,n);
		if(take<=n){
			n-=take;
			simonPass = 1 - simonPass;
		}
		else{
			break;
		}
	}

	cout<<simonPass<<endl;
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
