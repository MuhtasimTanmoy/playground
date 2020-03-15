//https://1325/problem/D
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
	ll n,s;
	cin>>n>>s;

	if(n==0 && s==0){
		cout<<0<<endl;
		return;
	}
	else if(n==s){
		cout<< 1<<endl;
		cout<<n;
		return;
	}
	else if(n>s || (s-n)%2){
		cout<<-1<<endl;
		return;
	}
	else{
		ll p = (s-n)>>1;
		ll q = n^p;
		if(p+q==s){
			cout<<2<<endl;
			cout<<p<<" "<<q;
			return;
		}
	}

	cout<<3<<endl;
	cout<<n<<" "<< (s-n)/2 <<" "<< (s-n)/2 <<endl;

	
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
