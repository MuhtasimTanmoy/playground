//https://1342/problem/B
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

	char start = s[0];
	bool alternate = false;
	for (int i = 1; i < s.size(); i++){
		if(start != s[i]){
			alternate = true;
		}
	}

	if(alternate){
		for (int i = 0; i < 2*s.size()-1; i++){
			cout<<start;
			start = (start == '0')?'1':'0';
		}
		cout<<endl;
	}
	else{
		cout<<s<<endl;
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
