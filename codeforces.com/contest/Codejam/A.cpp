//https://Codejam/problem/A
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 101;

int mat[N][N];

int case_count = 1;

void solve()
{
	int n;
	cin>>n;

	int holder;
	int trace = 0;

	int dup_row_count = 0;
	int dup_column_count = 0;

	bitset<N> dup_track;

	// Trace count

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin>>holder;
			
			mat[i][j] = holder;
			if(i==j){
				trace+=holder;
			}
		}
	}

	// Duplicate row count

	for (int i = 0; i < n; i++){

		dup_track.reset();

		for (int j = 0; j < n; j++){
			holder = mat[i][j];
			
			if(dup_track.test(holder)){
				dup_row_count++;
				break;
			}
			else{
				dup_track.set(holder);
			}

		}
	}

	// Duplicate column count

	for (int i = 0; i < n; i++){

		dup_track.reset();

		for (int j = 0; j < n; j++){
			holder = mat[j][i];

			if(dup_track.test(holder)){
				dup_column_count++;
				break;
			}
			else{
				dup_track.set(holder);
			}
			
		}
	}


	cout<< "Case #"<<case_count<< ": ";
	case_count++;
	
	cout<< trace<<" "<< dup_row_count<<" "<<dup_column_count<<endl;
	
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
