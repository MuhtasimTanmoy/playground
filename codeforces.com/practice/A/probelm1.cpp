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
	ll n,a,b,c;
	cin>>n>>a>>b>>c;

	n = n%4;

	if(n==0)n=4;
	ll deficit = abs(4-n);

	ll for_a = INT32_MAX;
	if(deficit ==1){
		for_a =  a;
		for_a = min(for_a, 3*c);
		for_a = min(b+c, for_a);
	}

	ll for_b = INT32_MAX;
	if(deficit==2){
		for_b = b;
		for_b = min(for_b,2*c);
		for_b = min(2*a,for_b);
	}

	ll for_c = INT32_MAX;
	if(deficit==3){
		for_c = c;
		for_c = min(a+b,for_c);
		for_c = min(3*c, for_c);
	}

	cout<<min(for_a,min(for_b,for_c))<<endl;
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
