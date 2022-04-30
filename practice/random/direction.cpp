#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;
int mat[N][N];

void solve() {
	
	string s;
	cin>>s;

	int cur_x = N/2;
	int cur_y = N/2;

	int point = 0;

	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			mat[i][j] = 0;

	for (int i = 0; i < s.size(); i++) {

		if ( s[i]=='N' ) 
			cur_y++;
		else if ( s[i]=='S' )
			cur_y--;
		else if ( s[i]=='W' )
			cur_x--;
		else
			cur_x++;

		if ( mat[cur_x][cur_y] ) point += 1;
		else point += 5;
		
		mat[cur_x][cur_y] = 1;
	}

	cout<<point<<endl;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	freopen("input.txt", "r", stdin);
    int no_of_test_cases = 1;
	cin >> no_of_test_cases;
    while (no_of_test_cases--) execute(); 
	return 0;
}