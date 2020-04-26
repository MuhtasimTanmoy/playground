//https://1343/problem/B
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

int a[200009],peak[200009];

void solve()
{
	int n,k;
	cin>>n>>k;

	for (int i = 0; i < n; i++){
		cin>>a[i];
		peak[i] = 0;
	}

	for (int i = 1; i < n-1; i++){
		peak[i]=peak[i-1];
		if(a[i]>a[i-1] && a[i]>a[i+1]){
			peak[i]++;
		}
	}

	int left = 1;
	int _max = 0;
	int ans;

	for (int i = k-2; i < n-1; i++){
		ans = peak[i] - peak[i-k+2];
		if(ans>_max){
			_max = ans;
			left = i-k+2;
		}
	}
	cout<<_max+1<<" "<<left+1<<endl;
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
