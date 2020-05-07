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
	int a,b;
	int _a,_b;

	cin>>a>>b>>_a>>_b;

	if(a < b){
		a = a + b;
		b = a - b;
		a = a - b;
	}

	if(_a < _b){
		_a = _a + _b;
		_b = _a - _b;
		_a = _a - _b;
	}

	int possible = false;

	if(a == _a){
		if(b+_b==a){
			possible = true;
		}
	}
	else if(b == _b){
		if(a+_a==b){
			possible = true;
		}
	}

	cout<<(possible?"Yes":"No")<<endl;
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
