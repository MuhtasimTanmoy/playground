//https://1295/problem/C
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
	string s, t;
	cin >> s >> t;

	bool arr[26] = {0};

	for (int i = 0; i < s.size(); i++)
	{
		arr[s[i] - 'a'] = 1;
	}

	for (int i = 0; i < t.size(); i++)
	{
		if (!arr[t[i] - 'a'])
		{
			cout << -1 << endl;
			return;
		}
	}

	int result = 0;

	int fast = 0;
	int slow = 0;

	while (slow < t.size())
	{
		fast = 0;
		while(fast<s.size()){
			if(s[fast]==t[slow]){
				fast++;
				slow++;
			}
			else{
				fast++;
			}
		}
		result++;
	}

	cout<<result<<endl;
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
