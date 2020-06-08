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
	int n,m;
	cin>>n>>m;

	int li[n];
	for (int i = 0; i < n; i++){
		cin>>li[i];
	}

	// Naive Approach
	// for (int i = 0; i < (1<<n); i++){
	// 	int sum = 0;
	// 	for (int j = 0; j < n; j++){
	// 		if((1<<j)&i){
	// 			sum+=li[j];
	// 		}
	// 	}
	// 	if(sum%m==0 && sum!=0){
	// 		cout<<"Yes"<<endl;
	// 		return;
	// 	}
	// }
	// cout<<"No"<<endl;

	// DP Approach
	
	
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
