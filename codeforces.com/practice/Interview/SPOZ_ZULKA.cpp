#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

vector<int> add_res(vector<int> a, vector<int> b)
{
	vector<int> result;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	int len = max(a.size(), b.size());
	int carry = 0;
	int s = 0;

	for (int i = 0; i < len; i++)
	{
		if ((a[i] + b[i]) % 10)
		{
			s = (a[i] + b[i]) / 10;
		}
		else
		{
			s = (a[i] + b[i]);
		}

		result.push_back(s + carry);

		if ((a[i] + b[i]) % 10)
		{
			carry = 1;
		}
		else
		{
			carry = 0;
		}
	}

	reverse(result.begin(), result.end());
}

vector<int> add(vector<int> x, vector<int> y)
{
	// Reverse the numbers so that we can add them from units place
	reverse(x.begin(), x.end());
	reverse(y.begin(), y.end());

	vector<int> ans; // Our final answer
	int len = min(x.size(), y.size()), carry = 0;
	for (int i = 0; i < len; i++)
	{
		// Add the digits at the i_th pos from x and y and add the prev carry
		int val = x[i] + y[i] + carry;
		carry = val / 10;
		ans.push_back(val % 10); // Push the sum of digits to ans
	}

	if (x.size() > len)
	{ // If any digits remain in x, add them to ans
		for (int i = len; i < x.size(); i++)
		{
			int val = x[i] + carry;
			carry = val / 10;
			ans.push_back(val % 10);
		}
	}

	if (y.size() > len)
	{ // If any digits remain in y, add them to ans
		for (int i = len; i < y.size(); i++)
		{
			int val = y[i] + carry;
			carry = val / 10;
			ans.push_back(val % 10);
		}
	}

	// While there is still some carry left-over, add new digits to ans
	while (carry)
	{
		ans.push_back(carry % 10);
		carry /= 10;
	}

	// Reverse ans to get back actual answer and return.
	reverse(ans.begin(), ans.end());
	return ans;
}

vector<int> divBy2(vector<int> x)
{
	vector<int> ans;

	int val = 0; // val stores any previous remainders from division
	for (int i = 0; i < x.size(); i++)
	{
		if (val)
		{
			// If there are remainders, then add them in current division
			// eg : 38/2 ==> 3/2 = 1, rem = 1 ==> val = 1*10 + 8 = 18 ==> 18/2
			val = val * 10 + x[i];
			ans.push_back(val / 2);
			val = val % 2;
		}
		else
		{ // No remainders from prev division
			if (x[i] < 2)
			{ // If digit < 2, add 0 to result and put the digit as rem
				val += x[i];
				ans.push_back(0);
			}
			else
			{ // Just divide!
				val = x[i] % 2;
				ans.push_back(x[i] / 2);
			}
		}
	}

	vector<int> arr;
	int i = 0;
	while (ans[i] == 0)
		i++; // Omit leading zeros and return ans
	for (; i < ans.size(); i++)
		arr.push_back(ans[i]);
	return arr;
}

vector<int> sub(vector<int> x, vector<int> y)
{
	// Assuming x >= y
	reverse(x.begin(), x.end());
	reverse(y.begin(), y.end());

	int len = max(x.size(), y.size());

	vector<int> ans;
	for (int i = 0; i < y.size(); i++)
	{
		if (x[i] < y[i])
		{				// If we have 1 - 2 ==> 10 + 1 - 2
			x[i + 1]--; // Borrow from next 10's place
			ans.push_back(10 + x[i] - y[i]);
		}
		else
			ans.push_back(x[i] - y[i]); // Simply subtract and push the result
	}

	if (x.size() > len)
	{ // If there are any digits left in x, just add them to ans
		for (int i = len; i < x.size(); i++)
			ans.pb(x[i]);
	}

	reverse(ans.begin(), ans.end());

	vector<int> arr;
	int i = 0;
	while (ans[i] == 0)
		i++; // Omit the leading zeros and return result
	for (; i < ans.size(); i++)
		arr.pb(ans[i]);
	return arr;
}

void solve()
{
	string total;
	string has_more;

	cin >> total >> has_more;

	int length = max(total.length(), has_more.length());

	vector<int> _total(length);
	vector<int> _has_more(length);
	vector<int> _result(length);
	vector<int> _div(length);
	vector<int> _diff(length);

	for (int i = 0; i < total.size(); i++)
	{
		_total[i] = total[i] - '0';
	}

	for (int i = 0; i < has_more.size(); i++)
	{
		_has_more[i] = has_more[i] - '0';
	}

	_result = add(_total, _has_more);
	for (int i = 0; i < _result.size(); i++)
		cout<<_result[i];
	cout<<endl;	

	_div = divBy2(_result);			  

	for (int i = 0; i < _div.size(); i++)
		cout << _div[i];
	cout << endl;

	_diff = sub(_total, _div); // num2 = S - num1
	for(int i = 0; i < _diff.size(); i++) cout << _diff[i];
	cout << endl;
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
