//https://codeforces.com/contest/1150/problem/C
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

int li[200000];

vector<int> primeNums;

void sieve(int n)
{
	bool isPrime[n + 1];
	memset(isPrime, true, sizeof(isPrime));

	isPrime[0] = false;
	isPrime[1] = false;

	for (int i = 2; i * i < n; i++)
	{
		if (isPrime[i])
		{
			for (int j = i * i; j < n; j += i)
			{
				isPrime[j] = false;
			}
		}
	}

	for (int i = 2; i <= n; i++)
	{
		if (isPrime[i])
		{
			primeNums.push_back(i);
		}
	}
}

void solveEfficient(){
		int n;
	cin >> n;

	int one = 0;
	int two = 0;
	int holder;
	int result[n];
	REP(i, n)
	{
		cin >> holder;
		holder == 1 ? one++ : two++;
	}

	if (two)
	{
		cout << 2 << " ";
		two--;
	}

	if (one)
	{
		cout << 1 << " ";
		one--;
	}

	while (two)
	{
		cout << 2 << " ";
		two--;
	}

	while (one)
	{
		cout << 1 << " ";
		one--;
	}

	return;
}

void solve()
{
	int n;
	cin >> n;

	int one = 0;
	int two = 0;
	int holder;
	int result[n];
	REP(i, n)
	{
		cin >> holder;
		holder == 1 ? one++ : two++;
	}


	if (n == 1)
	{
		cout << holder << endl;
		return;
	}

	int limit = one + two * 2;
	sieve(limit);

	int target = 0;
	int next = 0;

	int sum = 0;
	int resIndex = 0;

	while (sum < limit)
	{
		next = primeNums[target];
		if ((next - sum == 1 && one) || !two)
		{
			result[resIndex] = 1;
			one--;
			target++;
			sum++;
		}
		else
		{
			result[resIndex] = 2;
			two--;
			sum += 2;
			if (sum == next)
			{
				target++;
			}
		}
		resIndex++;
	}

	for (int i : result)
		cout << i << " ";
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
