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

	bool diffGot = false;

	int curr = s[0];
	int count = 0;

	for (int i = 1; i < s.size(); i++){
		if(!diffGot){
		if(s[i]!=curr){
			diffGot = true;
			curr = s[i];
		}
		}

		if(diffGot){
			if(curr!=s[i]){
				count++;
			}
		}

	}
	cout<<count<<endl;
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
