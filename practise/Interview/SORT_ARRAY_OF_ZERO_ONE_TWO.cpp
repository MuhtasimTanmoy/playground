#include <bits/stdc++.h>
#define _DEBUG
#define ll long long
using namespace std;

const int INF = 2e9;
const ll INF64 = 1e18;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double PI = 3.14159265359;
const int MAX = 1e6 + 1;

int list[MAX];

void solve()
{
    int n;
    cin >> n;
    int holder = 0;

    int count[3] = {0, 0, 0};

    for (int i = 0; i < n; i++)
    {
        cin >> holder;
        count[holder]++;
    }

    for (int i = 0; i < 3; i++)
    {

        while (count[i])
        {
            cout << i << " ";
            count[i]--;
        }
    }
    cout<<endl;
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
    cin >> no_of_test_cases;
    // no_of_test_cases=1;
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
