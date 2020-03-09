//https://1295/problem/A
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

	int count = 0;
	bool odd = n%2;

	if(odd){
		count = n- 3;
		count = count>>1;
	}
	else{
		count = n>>1;
	}

	if(odd){
		cout<<7;
	}

	for (int i = 0; i < count; i++){
		cout<<1;
	}
	cout<<endl;
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
