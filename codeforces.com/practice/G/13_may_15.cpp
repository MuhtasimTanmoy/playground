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

	int li[n];
	for (int i = 0; i < n; i++){
		cin>>li[i];
	}

	int even = 0;
	int uneven = 0;

	int searchEven = 1;
	for (int i = 0; i < 3; i++){
		if(li[i]%2==0){even++;}
		else{uneven++;}
	}

	if(even>=2){	
	}else{
		searchEven = 0;
	}

	for (int i = 0; i < n; i++){
		if(li[i]%2==searchEven){
			cout<<i+1<<endl;
			return;
		}
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
