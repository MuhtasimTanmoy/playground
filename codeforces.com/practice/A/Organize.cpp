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
	string s;
	cin>>s;

	int li[3]={0,0,0};

	for (int i = 0; i < s.size(); i++){
		if(s[i]=='+')continue;
		li[s[i]-'1']++;
	}

	int itr =0;
	bool putPlus = false;

	for (int i = 0; i < s.size(); i++){
		if(putPlus){
			cout<<"+";
			putPlus = false;
			continue;
		}
		while(li[itr]==0){
			itr++;
		}
		li[itr]--;
		cout<<itr+1;
		putPlus = true;
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	int no_of_test_cases = 0;
	// cin >> no_of_test_cases;
	if (!no_of_test_cases)
		no_of_test_cases = 1;
	while (no_of_test_cases--)
	{
		solve();    
	}

	return 0;
}
