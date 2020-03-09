//https://1300/problem/A
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

// void solve()
// {
// 	int n;
// 	cin >> n;

// 	int zero_counter = 0;
// 	int sum = 0;

// 	int holder;
// 	int result = 0;

// 	for (int i = 0; i < n; i++)
// 	{
// 		cin >> holder;
// 		sum += holder;
// 		if (holder == 0)
// 			zero_counter++;
// 	}

// 	result += zero_counter;
// 	if (sum + zero_counter == 0)
// 	{
// 		result++;
// 	}

// 	cout << result << endl;
// }

int li[N], p[N], s[N];

void solve()
{
	int n;
	cin >> n;

	p[0] = INT_MAX;
	s[n - 1] = INT_MAX;

	for (int i = 0; i < n; i++)
	{
		cin >> li[i];
	}

	for (int i = 1; i < n; i++)
	{
		p[i] = p[i - 1] & (~li[i - 1]);
	}

	for (int i = n - 2; i >= 0; i--)
	{
		s[i] = s[i + 1] & (~li[i + 1]);
	}

	int ans = INT_MIN;
	int index = -1;
	int temp;

	for (int i = 0; i < n; i++)
	{
		temp = li[i]&p[i]&s[i];
		if (temp>ans){
			ans = temp;
			index = i;
		}
	}

	cout<<li[index]<<" ";
	for (int i = 0; i < n; i++){
		if(i==index)continue;
		cout<<li[i]<<" ";
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
