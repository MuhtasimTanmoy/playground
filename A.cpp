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
	int num, target;
	cin>>num>>target;

	vector< pair<int,int> > li;
	int holder;
	for (int i = 0; i < num; i++){
		cin>>holder;
		li.push_back(make_pair(holder,i+1));
	}

	sort(li.begin(),li.end());

	// for (auto x: li){
	// 	cout<<x.first<<" "<<x.second<<endl;
	// }

	int count = 0;
	vector<int> result;

	int current = li[0].first;
	while(current<=target){
		target-=current;
		result.push_back(li[count].second);
		count++;
		if(count==num)break;
		current = li[count].first;
	}

	cout<<count<<endl;
	for (auto x: result){
		cout<<x<<" ";
	}

	
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
