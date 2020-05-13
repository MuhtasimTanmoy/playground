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
	int n_a,n_b;
	cin>>n_a>>n_b;

	int k,m;
	cin>>k>>m;

	vector<int> a,b;
	int holder;
	for (int i = 0; i < n_a; i++){
		cin>>holder;
		a.push_back(holder);
	}
	for (int i = 0; i < n_b; i++){
		cin>>holder;
		b.push_back(holder);
	}

	if(a[k-1]<b[n_b-m]){
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
	// cin >> no_of_test_cases;
	if (!no_of_test_cases)
		no_of_test_cases = 1;
	while (no_of_test_cases--)
	{
		solve();    
	}

	return 0;
}
