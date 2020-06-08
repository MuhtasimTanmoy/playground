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
	string first[9] = {"one","two","three","four","five","six","seven","eight","nine"};
	string second[9] = {"inv","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};


	int n;
	cin>>n;

	vector<string> v;

	int cur;
	bool _first = true;
	while(n){
		cur = n%10;
		v.push_back(_first?first[cur-1]:second[cur-1]);
		_first = false;
		n=n/10;
	}

	_first = false;
	for (int i =v.size()-1; i >= 0; i--){
		if(_first && v[i]!="inv"){
			cout<<"-";
		}
		cout<<v[i];
		_first = true;
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
