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
	int n;
	cin>>n;

	vector<int> li;
	int holder;
	for (int i = 0; i < n; i++){
		cin>>holder;
		li.push_back(holder);
	}

	int _max_non_decrease=1;
	int count = 1;
	for (int i = 1; i < n; i++){
		if(li[i-1]<=li[i]){
			count++;
			_max_non_decrease = max(_max_non_decrease,count);
		}
		else{
			count = 1;
		}
	}
	cout<<_max_non_decrease<<endl;
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
