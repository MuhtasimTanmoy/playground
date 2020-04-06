//https://1332/problem/A
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
	int a,b,c,d;
	cin>>a>>b>>c>>d;

	int x,y,x1,y1,x2,y2;
	cin>>x>>y>>x1>>y1>>x2>>y2;

	bool possible = false;

	x += -a + b;
	y += -c + d;

	if(x>=x1 && x<=x2 && y>=y1 && y<=y2 && (x1<x2 || a+b == 0) && (y1<y2 || c+d == 0)){
		possible = true;
	}

	cout<<(possible?"Yes":"No")<<endl;
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
