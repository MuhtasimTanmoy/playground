//https://codeforces.com/contest/1200/problem/A
#include <bits/stdc++.h>
#define _DEBUG
#define ll long long
#define pb push_back
#define REP(i, n) for (int i = 0; i < (int)n; i++)
using namespace std;

bool sortbysec(const pair<int,int> &a,const pair<int,int> &b) {
    return (a.second < b.second);
}

void solve()
{
	int n;
	cin>>n;

	char ch;


	int leave=0;

	bool rooms[10]={0};

	int itr=0;

	REP(i,n){
		cin>>ch;
		if(ch=='L'){
			itr=0;
			while(rooms[itr]==1){
				itr++;
			}
			rooms[itr]=1;
		}
		else if(ch=='R'){
			itr=9;
			while(rooms[itr]==1){
				itr--;
			}
			rooms[itr]=1;
		}
		else{
			leave = ch-'0';
			rooms[leave]=0;
		}
	}

	REP(i,10){
		cout<<rooms[i];
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
