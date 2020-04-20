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
	int p,q;

	int p_so_far,q_so_far;
	p_so_far = 0;
	q_so_far = 0;


	int n;
	cin>>n;

	bool possible = true;

	for (int i = 0; i < n; i++){
		cin>>p>>q;
		if(possible){

			if((p-p_so_far)<(q-q_so_far)){
				possible = false;
			}

			if(p<p_so_far){
				possible = false;
			}

			if(q<q_so_far){
				possible = false;
			}

			p_so_far = p;
			q_so_far = q;
		}
	}

	cout<<(possible?"YES":"NO")<<endl;
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
