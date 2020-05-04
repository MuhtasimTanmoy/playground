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
	string li[] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
	cin>>n;

	int window = 5;

	while(n>window){
		n-=window;
		window=window<<1;
	}

	window = window/5;

	cout<<li[(n-1)/window]<<endl;

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
