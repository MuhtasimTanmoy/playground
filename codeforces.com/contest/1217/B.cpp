//https://codeforces.com/contest/1217/problem/B
#include <bits/stdc++.h>
#define _DEBUG
#define ll long long
#define pb push_back
#define REP(i, n) for (int i = 0; i < (int)n; i++)
using namespace std;

bool sortbysec(const pair<int,int> &a,const pair<int,int> &b)
{
    return (a.second < b.second);
}

void solve()
{
	int types_of_blow;
	ll init_head;

	ll head_to_cut, head_to_grow; 

	cin>> types_of_blow >> init_head;

	// Needed to figure out the max decrease
	ll head_decrease_by = INT64_MIN;
	//Anytime the max head_cut can take it to zero rather than the max decrease
	ll max_head_cut = INT64_MIN;


	REP(i,types_of_blow){
		cin>> head_to_cut >> head_to_grow;
		max_head_cut = max(max_head_cut, head_to_cut);

		if(head_to_grow>=head_to_cut)continue;

		head_decrease_by = max(head_decrease_by, head_to_cut-head_to_grow);
	}
	
	//Always the head grows
	if(head_decrease_by == INT64_MIN && max_head_cut<init_head) {
		cout<< -1 <<endl;
		return;
	}

	ll res = 1;
	init_head -= max_head_cut;

	// Decreasing head count until it becomes 0 by largest head cut
	if(init_head>0){
		res += (init_head + head_decrease_by -1) / head_decrease_by;
	}

	cout<< res <<endl;

}

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int tt = clock();
#endif

	ios_base::sync_with_stdio(false);
	int no_of_test_cases;
	//cin >> no_of_test_cases;
	no_of_test_cases=1;
	while (no_of_test_cases--)
	{
		solve();
	}

#ifdef _DEBUG
	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();
#endif

	return 0;
}
