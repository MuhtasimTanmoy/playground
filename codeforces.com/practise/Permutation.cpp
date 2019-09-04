

#include <bits/stdc++.h>
#define _DEBUG
#define ll long long
#define pb push_back
#define REP(i, n) for (int i = 0; i < (int)n; i++)
#define q(tag, i) cout << endl \
					   << tag << "...." << i << "...." << endl;
using namespace std;

vector<pair<int, int>> li(3);

void heapPermutation(vector<pair<int, int>> a, int size)
{

	if (size == 1)
	{
		for (pair<int, int> x : li)
		{
			cout << x.first << " " << x.second << endl;
		}

		cout << endl<< "ds "<< "...." << 34 << "...." << endl;
		return;
	}

	for (int i = 0; i < size; i++)
	{
		heapPermutation(a, size - 1);

		if (size % 2 == 1)
		{
			swap(a[0], a[size - 1]);
		}

		else
			swap(a[i], a[size - 1]);
	}
}

void solve()
{
	ll n;
	cin >> n;


	REP(i, n)
	{
		cin >> li[i].first >> li[i].second;
	}

	// for (pair<int, int> x : li)
	// {
	// 	cout << x.first << " " << x.second << endl;
	// }

	heapPermutation(li,li.size());
	// do {
	//     for(pair<int,int> x: li){
	// 		cout<< x.first << " " << x.second <<endl;
	// 	}

	// 	cout << endl<< "ds "<< "...." << 4444 << "...." << endl;

	// } while(next_permutation(li.begin(), li.end()));
}

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int tt = clock();
#endif

	int no_of_test_cases;
	// cin >> no_of_test_cases;
	no_of_test_cases = 1;
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
