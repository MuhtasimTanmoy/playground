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
	int n,diff;
	cin>>n>>diff;

	vector<bool> sign; 
	vector<int> index;
	vector<int> val;

	int li[n];
	for (int i = 0; i < n; i++){
		cin>>li[i];
	}
	int target = 0;
	for (int i = 1; i < n; i++){
		target = li[i-1]+diff;
		if(target==li[i])continue;
		sign.push_back(target>li[i]);
		index.push_back(i+1);
		val.push_back(abs(target-li[i]));
		li[i]=target;
	}

	cout<<sign.size()<<endl;

	for (int i = 0; i < sign.size(); i++){
		cout<<(sign[i]?'+':'-')<<" ";
		cout<<index[i]<<" ";
		cout<<val[i]<<endl;
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
