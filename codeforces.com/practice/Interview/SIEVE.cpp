#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

vector<int> sieve(int n)
{
    bool is_prime[n + 1] = {false};
    vector<int> res;

    for (int i = 2; i * i <= n; i++)
    {
        if (!is_prime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {

                is_prime[j] = true;
            }
        }
    }

    for (int i = 2; i <= n; i++)
    {
        if (!is_prime[i])
        {
            res.push_back(i);
        }
    }

    return res;
}

void solve()
{
    int n;
    cin >> n;

    vector<int> result;

    result = sieve(n);

    for (auto i : result)
    {
        cout << i << " ";
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int no_of_test_cases;
    cin >> no_of_test_cases;
    // no_of_test_cases = 1;
    while (no_of_test_cases--)
    {
        solve();
    }

    return 0;
}
