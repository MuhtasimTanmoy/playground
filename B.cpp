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
	double n,min_burl;
	cin>>n>>min_burl;

	vector<int> li;
	double holder;
	for (int i = 0; i < n; i++){
		cin>>holder;
		li.push_back(holder);
	}

	sort(li.rbegin(),li.rend());

	double avg = 0;
	int counter = 0; 

	for (int i = 0; i < n; i++){

		avg = ( avg * i + li[i])/(i+1);

		if(avg<min_burl){
			break;
		}

		counter++;
	}
	
	cout<<counter<<endl;
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
