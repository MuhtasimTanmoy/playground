#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

https://codeforces.com/contest/1494/problem/A

void solve()
{
	string s;
	cin>>s;
	stack<char> stack;

	for (int i = 0; i < s.size(); i++){
		char current = s[i];
		if (stack.empty()) {
			stack.push(current);
		} else {
			if (stack.top() != current){
				stack.pop();
			} else {
				stack.push(current);
			}
		}
	}

	if (stack.empty()) {
		cout<<"YES"<<endl;
	} else {
		cout<<"NO"<<endl;
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
