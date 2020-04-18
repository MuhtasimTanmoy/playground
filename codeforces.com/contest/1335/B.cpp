//https://1335/problem/B
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

char li[26];
int counter=-1;



void solve()
{
	int n,a,b;
	cin>>n>>a>>b;

	for (int i = 0; i < 26; i++){
		li[i] = 'a'+i; 
	}
	
	string s = "";
	int disLeft = b;
	char current;

	int counter = 0;

	for (int i = 0; i < a; i++){
		if(disLeft){
			current = li[counter];
			s+=current;
			disLeft--;
			counter++;
		}
		else{
			s+=current;
		}
	}

	int iteration = n - a; 

	for (int i = 0; i < iteration; i++){
		s+=s[i];
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
