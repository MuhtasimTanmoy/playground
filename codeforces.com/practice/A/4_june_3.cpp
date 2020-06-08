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
	int n,x;
	cin>>n>>x;

	int odd_count=0;
	int even_count = 0;
	int holder;

	for (int i = 0; i < n; i++){
		cin>>holder;
		if(holder%2){
			odd_count++;
		}
		else{
			even_count++;
		}
	}

	if(odd_count%2==0 && (even_count==0|| x==n)){
		cout<<"No"<<endl;
	}
	else{
		cout<<"Yes"<<endl;
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
