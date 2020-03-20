//https://1395/problem/D
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

	if(s.size()==1){
		cout<<s<<endl;
		return;
	}

	int start = 0;
	int end = s.size()-1;

	int offset = 0;

	while(s[start+offset]==s[end-offset]){
		offset++;
	}

	cout<<offset<<endl;
	
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
