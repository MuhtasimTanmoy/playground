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
	string s;
	int numOfRows;
	cin>>numOfRows;
	cin>>s;

	vector<vector<char>> rows(numOfRows);
	bool flip=false;
	int index=0;

	numOfRows--;
	for(int i=0;s[i];i++){
		index=i%(numOfRows);
		index=flip?numOfRows-index:index;	
		// cout<<index<<endl;
		if(index==numOfRows-1){
			flip=!flip;
		}

		rows[index].push_back(s[i]);
	}

	for(int i=0;i<rows.size();i++){
		for(int j=0;rows[i][j];j++){
			cout<< rows[i][j] << " ";
		}
		cout<<"\n";
	}
}

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tt = clock();
#endif

	int no_of_test_cases;
	cin >> no_of_test_cases;
	// no_of_test_cases=1;

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
