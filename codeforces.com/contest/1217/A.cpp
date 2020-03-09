//https://1217/problem/A
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

	int holder;
	int odd_count = 0;
	for (int i = 0; i < n; i++){
		cin>>holder;
		if(holder&1){
			odd_count++;
		}
	}

	if((odd_count & 1) || (odd_count!=n && odd_count!=0)){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
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
