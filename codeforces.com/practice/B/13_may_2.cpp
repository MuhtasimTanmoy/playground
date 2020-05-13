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
	int n , x;
	cin>>n>>x;
	string s;
	cin>>s;

	int distance = 0;
	int count = 0;

	int projected = 0;

	for (int i = s.size()-1; i >= 0; i--){
		distance = s.size()-1-i - count;
		if(s[i]=='B'){
			projected = i+ min(distance,x);
			if(s[projected]!='B'){
				s[i]='G';
				s[projected]='B';
				count++;
			}
		}
	}

	cout<<s<<endl;
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
