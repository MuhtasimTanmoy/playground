//https://1312/problem/E
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;
int li[1002];

void solve()
{
	int n;  
    cin>>n;

    int holder;
    int _min = INT32_MAX;

    for (int i = 0; i < n; i++){
        cin>>holder;
        _min = min(holder, _min);
        li[holder]++;
    }

    int unique_count = 0;

    for (int i = _min; i < 50; i++){

        if(li[i]%2)unique_count++;

        li[i+1]+=(li[i]>>1);
    }

    cout<<unique_count<<endl;
	
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
