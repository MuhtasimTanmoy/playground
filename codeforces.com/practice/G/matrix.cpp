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
    int n =5;
    int curr;
    int dist = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin>>curr;
            if(curr == 1){
                dist += abs(2-i)+abs(2-j);
            }
        }
    }
    cout<<dist<<endl;
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
