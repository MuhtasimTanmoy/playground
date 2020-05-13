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
	n=6;

	map<int,int> _map;
	int li[n];
	for (int i = 0; i < n; i++){
		cin>>li[i];
	}

	sort(li,li+n);

	int diff = 0;
	for (int i = 1; i < n; i++){
		if(li[i]!=li[i-1]){
			diff++;
		}
	}

	if(diff>=3){
		cout<<"Alien"<<endl;
	}
	else if(diff==0 || diff == 1){
		cout<<"Elephant"<<endl;
	}
	else{
		cout<<"Bear"<<endl;
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	int no_of_test_cases = 0;
	cin >> no_of_test_cases;
	if (!no_of_test_cases)
		no_of_test_cases = 1;
	while (no_of_test_cases--)
	{
		solve();    
	}

	return 0;
}
