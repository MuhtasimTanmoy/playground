//https://1343/problem/A
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

bool between(int val_l,int val_r, int l, int r){

	int _max =  max(val_l,l);
	int _min = min(val_r,r);

	if(_min<_max){
		return false;
	}

	return true;
}

void solve()
{
	int n,a,b,c,d;
	cin>>n>>a>>b>>c>>d;

	int grain_l = a-b;
	int grain_r = a+b;

	int package_l = c-d;
	int package_r = c+d;

	if(between(grain_l*n,grain_r*n,package_l,package_r)){
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
	cin >> no_of_test_cases;
	if (!no_of_test_cases)
		no_of_test_cases = 1;
	while (no_of_test_cases--)
	{
		solve();    
	}

	return 0;
}
