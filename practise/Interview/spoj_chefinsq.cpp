#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

int n, k;

int _min = INT32_MAX;
int res = 0;

void generateSubseqPrint(int li[], vector<int> current_array, int index, int count)
{
	if (count == k)
	{
		int sum = 0;
		for (int i = 0; i < current_array.size(); i++)
		{
			cout << current_array[i] << " ";
		}
		cout << endl;
		return;
	}
	for (int i = index; i < n; i++)
	{
		current_array.push_back(li[i]);
		generateSubseqPrint(li, current_array, index + i + 1, count + 1);
		current_array.pop_back();
	}
}

void generateSubseq(int li[], vector<int> current_array, int index, int count)
{
	if (count == k)
	{
		int sum = 0;
		for (int i = 0; i < current_array.size(); i++)
		{
			sum += current_array[i];
		}
		if (sum <= _min)
		{
			if (sum != _min)
			{
				res = 0;
			}
			_min = sum;
			res++;
		}
		return;
	}
	for (int i = index; i < n; i++)
	{
		current_array.push_back(li[i]);
		generateSubseq(li, current_array, index + i + 1, count + 1);
		current_array.pop_back();
	}
}

void solve()
{
	cin >> n >> k;

	vector<int> arr;

	int li[n];

	for (int i = 0; i < n; i++)
	{
		cin >> li[i];
	}

	_min = INT32_MAX;
	res = 0;
	generateSubseq(li, arr, 0, 0);
	cout << res << endl;
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


//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
// Anand Jaisingh

#include<bits/stdc++.h>

using namespace std;

typedef complex<double> base;
typedef long double ld;
typedef long long ll;

#define pb push_back
#define pii pair<int,int>
#define pll pair< ll , ll >
#define vi vector<int>
#define vvi vector< vi >
const int maxn=(int)(2e5+5);
const ll mod=(ll)(1e9+7);
int a[maxn];
ll dp[55][55];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
	freopen("input.txt", "r", stdin);

    int t;cin>>t;

    dp[0][0]=1;

    for(int i=1;i<51;i++)
    {
        dp[i][0]=1;

        for(int j=1;j<51;j++)
        {
            dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
        }
    }

    while(t>0)
    {
        int n,k;

        cin>>n>>k;map<int,int> m1;

        for(int i=0;i<n;i++)
        {
            cin>>a[i];

            m1[a[i]]++;
        }

        sort(a,a+n);

        int ptr=k-1,val=0;

        while(ptr>=0 && a[ptr]==a[k-1])
        {
            ptr--;val++;
        }

        ll res=dp[m1[a[k-1]]][val];

        cout<<res<<endl;

        t--;
    }

    return 0;
}