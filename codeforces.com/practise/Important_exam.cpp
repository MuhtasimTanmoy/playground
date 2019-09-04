#include <bits/stdc++.h>
#define _DEBUG
#define ll long long
#define pb push_back
#define REP(i, n) for (int i = 0; i < (int)n; i++)
#define pr(i) cout << endl \
				   << "...." << i << "...." << endl;
using namespace std;

void solve()
{
	ll n,m;
	cin>>n>>m;

	vector<int> points(m);
	vector<int> count(4);
	vector<string> li(n);
	map<char,int> answers;

	REP(i,n){
		cin>>li[i];
	}

	REP(i,m){
		cin>>points[i];
	}

	
	int countIndex=0;
	int sum=0;
	REP(i,m){
		countIndex=1;
		answers.clear();
		REP(j,n){
			if(answers.find(li[j][i])==answers.end()){
				answers[li[j][i]]=1;
			}
			else{
				answers[li[j][i]]++;
				countIndex = max(answers[li[j][i]],countIndex);
			}
		}

		sum+= points[i]*countIndex;
	}

	cout<<sum<<"\n";








}

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tt = clock();
#endif

	int no_of_test_cases;
	// cin >> no_of_test_cases;
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
