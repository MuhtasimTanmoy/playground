#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

void solve()
{
	int n;
	cin>>n;

	int _max = 0;
	set<int> _set;
	map<int,int> _map;
	int len_decrease = 0;
	int holder;
	for (int i = 0; i < n; i++){
		cin>>holder;
		if(_set.count(holder)){
			len_decrease;
			_map[holder] = _map[holder]+1;
			_max = max(_max, _map[holder]);
		}
		else{
			_set.insert(holder);
		}
	}

	cout<<_max<<" "<<n-len_decrease<<endl;
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
