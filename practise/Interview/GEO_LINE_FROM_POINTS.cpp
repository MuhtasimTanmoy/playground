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
	pair<int, int> p;
	pair<int, int> q;

	cin >> p.first >> p.second >> q.first >> q.second;

	// y = mx + c

	int m_up = (p.second - q.second);
	int m_down = (p.first - q.first);

	cout << endl
		 << "p "
		 << "...." << m_up << "...." << endl;
	cout << endl	
		 << "q "
		 << "...." << m_down << "...." << endl;

	int c = m_down * q.second - m_up * q.first;

	cout << m_down << "y + " << (-1)* m_up << "x =" << c << endl;
}

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
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
