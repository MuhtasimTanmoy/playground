//https://1342/problem/A
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

int sign(long long a){
	if(a<0) return -1;
	else if(a>=0) return 1;
}

void solve()
{
	long long x,y;
	cin>>x>>y;

	long long a,b;
	cin>>a>>b;

	if(x==0 && y==0){
		cout<<0<<endl;
		return;
	}

	long long dist = 0;
	if(sign(x)!=sign(y)){
		dist = abs(x)+abs(y);
		cout<<dist*a<<endl;
	}
	else{
		dist = abs(x-y);
		cout<< a*dist + min(abs(x),abs(y))* min(2*a,b)<<endl;
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
