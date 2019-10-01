//https://practise/problem/J
#include <bits/stdc++.h>
#define _DEBUG
#define ll long long
#define ull unsigned long long
#define pb push_back
#define REP(i, n) for (int i = 0; i < (int)n; i++)
#define REPI(i, a, b) for (int i = (a); (i <= (b)); ++i)
#define x first
#define y second
using namespace std;

ull solve()
{
    ull n;
    cin >> n;
    ull holder;

    ull max_res = 1;
    ull min_res = INT64_MAX;


    if (n == 1)
    {
        cin >> holder;
        return holder * holder;
    }
    else
    {

        REP(i, n)
        {
            cin >> holder;
            max_res = max(max_res, holder);
            min_res = min(min_res, holder);
        }
        return max_res*min_res;
    }
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
    for (int i = 1; i <= no_of_test_cases; i++)
    {
        cout << "Case " << i << ": " << solve()<<endl;
    }

#ifdef _DEBUG
    cerr << "TIME = " << clock() - tt << endl;
    tt = clock();
#endif

    return 0;
}
