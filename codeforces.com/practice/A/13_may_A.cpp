#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

void printZero(int n){
	for (int i = 0; i < n; i++){
		cout<<"0";
	}
	cout<<" ";
}

void solve()
{
	string s;
	cin>>s;

	vector<char> p;
	vector<int> zero_count;
	int counter=0;

	for (int i = 0; i < s.size(); i++){
		if(s[i]!='0'){
			p.push_back(s[i]);
			zero_count.push_back(s.size()-i-1);
			counter++;
		}
	}

	cout<<counter<<endl;

	for (int i = 0; i < p.size(); i++){
		cout<<p[i];
		printZero(zero_count[i]);
	}

	cout<<endl;
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
