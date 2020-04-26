#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

// int a[200009],peak[200009];

void solve()
{
	int n;
	cin>>n;
	int a[n];
	for (int i = 0; i < n; i++){
		cin>>a[i];
	}

	do{
		for (auto x: a){
			cout<<x<<" ";
		}
		cout<<endl;
	}
	while(next_permutation(a,a+n));
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
