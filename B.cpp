#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

bool _greater(const pair<int,int>& a, const pair<int,int>& b){
	return a.first>b.first;
}

bool _lesser(const pair<int,int>& a, const pair<int,int>& b){
	return a.second<b.second;
}

void solve()
{
	int n;
	cin>>n;

	int holder;
	vector< pair<int,int> > li;
	for (int i = 0; i < n; i++){
		cin>>holder;
		li.push_back(make_pair(holder,i));
	}

	sort(li.begin(),li.end(),_greater);

	int rank = 1;
	int prev = li[0].first;
	li[0].first = rank;

	int lag = 1;
	for (int i = 1; i < n; i++){

		if(li[i].first == prev){lag++;}
		else{rank+=lag;lag=1;}

		prev = li[i].first ;
		li[i].first = rank;
	}

	sort(li.begin(),li.end(),_lesser);

	for (int i = 0; i < n; i++){
		cout<<li[i].first<<" ";
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
