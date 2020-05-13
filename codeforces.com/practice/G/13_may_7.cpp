#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

int gcd(int a, int b) { 
   if (b == 0) 
      return a; 
   return gcd(b, a % b);  
}

void solve()
{
	int n;
	cin>>n;

	bool once = true;

	vector<int> v;
	int holder;

	for (int i = 0; i < n; i++){
		cin>>holder;
		while(holder%2==0){
			holder/=2;
		}
		while(holder%3==0){
			holder/=3;
		}
		v.push_back(holder);
	}

	for (int i = 1; i < n; i++){
		if(v[i]!=v[i-1]){
			once = false;
			break;
		}
	}
	cout<<(once?"Yes":"No")<<endl;
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
