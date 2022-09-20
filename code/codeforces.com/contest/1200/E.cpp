//https://codeforces.com/contest/1200/problem/E
#include <bits/stdc++.h>
#define _DEBUG
#define ll long long
#define pb push_back
#define REP(i, n) for (int i = 0; i < (int)n; i++)
using namespace std;

bool sortbysec(const pair<int, int> &a, const pair<int, int> &b)
{
	return (a.second < b.second);
}

int overlap(string s, string t)
{
	int next = 0;
	int prev = 0;

	int len = 0;

	while (prev < s.length() && next < t.length())
	{
		if (t[next] == s[prev])
		{
			len++;
			next++;
			prev++;
		}
		else
		{
			len = 0;
			next=0;
			prev++;
		}
	}

	return len;
}

void solve()
{
	int n;
	cin >> n;

	string li[n];

	REP(i, n)
	{
		cin >> li[i];
	}

	string result=li[0];

	int del;

	REP(i,n-1){
		del = overlap(li[i],li[i+1]);
		result+=li[i+1].substr(del,li[i+1].length());
	}

	cout<<result;

}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int tt = clock();
#endif

	ios_base::sync_with_stdio(false);
	int no_of_test_cases;
	//cin >> no_of_test_cases;
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
