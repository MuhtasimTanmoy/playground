// https://codeforces.com/contest/1220/problem/A
#include <bits/stdc++.h>
#define _DEBUG
#define ll long long
#define pb push_back
#define REP(i, n) for (int i = 0; i < (int)n; i++)
using namespace std;

bool sortbysec(const pair<int,int> &a,const pair<int,int> &b)
{
    return (a.second < b.second);
}

void solve()
{
	int n;
	cin>>n;
	

	string s;
	cin>>s;

	int count=0;

	for(char ch:s){
		if(ch=='z'){
			count++;
		}
	}

	int remain= (n - 4*count)/3;

	while(remain--){
		cout<<'1'<<' ';
	}

	while(count--){
		cout<<'0'<<' ';
	}

}	

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int tt = clock();
#endif

	ios_base::sync_with_stdio(false);
	int no_of_test_cases;
	//cin >> no_of_test_cases;
	no_of_test_cases=1;
	while (no_of_test_cases--)
	{
		solve();
	}

#ifdef _DEBUG
	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();
#endif

	return 0;
}

