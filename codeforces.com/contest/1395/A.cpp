//https://1395/problem/A
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back


// A number is divisible by 3 if sum of its digits is divisible by 3.

const int N = 2e5 + 11;

void solve()
{
	char chosen_no = '4';

	int n;
	cin>>n;
	if(n==1){
		cout<<-1<<endl;
		return;
	}

	string s;
	int sum = 3;
	for (int i = 0; i < n-1; i++){
		sum+=7;
		s += chosen_no;
	}

	s += '3';
	if(sum%3==0){
		s[n-2] = '5';
	}
	cout<<s<<endl;
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
