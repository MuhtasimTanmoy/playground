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
	int n;
	cin>>n;

	if(n>=0){
		cout<<n<<endl;
		return;
	}

	n = abs(n);

	if(n<=10){
		cout<<0<<endl;
		return;
	}

	int one = n%10;
	int two = (n/10)%10;

	if(one>two){
		n = n/10;
	}
	else{
		n = n/100;
		n*=10;
		n+=one;
	}

	cout<<-n<<endl;



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
