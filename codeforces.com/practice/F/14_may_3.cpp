#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

bool greater(const pair<int,int> a, const pair<int,int> b)
{
	return a.first<a.second;	
}
void solve()
{
	int s,n;
	cin>>s>>n;

	vector< pair<int,int> > li;
	int curr,bonus;

	bool possible=true;
	for (int i = 0; i < n; i++){
		cin>>curr>>bonus;
		li.push_back(make_pair(curr,bonus));
	}

	sort(li.begin(),li.end());

	for (int i = 0; i < n; i++){
		if(s>li[i].first){
			s+=li[i].second;
		}
		else{
			possible=false;
		}
	}

	cout<<(possible?"YES":"NO")<<endl;
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
