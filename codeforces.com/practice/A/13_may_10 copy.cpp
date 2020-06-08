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
	int n;
	cin>>n;

	if(n==1 || n==2){
		cout<<n<<endl;
		return;
	}

	int mat[11][11];
	for (int i = 0; i < 10; i++){
		mat[0][i] = 1;
	}
	for (int i = 0; i < 10; i++){
		mat[i][0] = 1;
	}

	for (int i = 1; i < n; i++){
		mat[i][i] = 2 * mat[i-1][i]; 
		for (int j = i+1; j < n; j++){
			mat[i][j] = mat[i-1][j] + mat[i][j-1];
		}
	}

	mat[n-1][n-1] = 2 * mat[n-2][n-1]; 

	cout<<mat[n-1][n-1]<<endl;
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
