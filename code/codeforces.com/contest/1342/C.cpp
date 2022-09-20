//https://1342/problem/C
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
	long long a,b,q;
	cin>>a>>b>>q;

	ll l,r;
	ll got = 0;
	while(q--){
		cin>>l>>r;
		while(l<=r){
			if(((l%a)%b)==((l%b)%a)){
				got = l;
				break;
			}
			l++;
		}

		
	}
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
