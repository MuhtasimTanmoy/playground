#include <bits/stdc++.h>
using namespace std;

int main()
{
	int r, c;
	cin >> r >> c;
	int a[r][c];
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < r; i++)
	{

		sort(a[i], a[i] + c);
	}
	int lowest = abs(a[0][0] - a[1][0]); //let it is the lowest
	for (int i = 0; i < r - 1; i++)
	{
		int *tmp;
		int tmp2;
		if (lowest == 0)
			break;
		for (int j = 0; j < c; j++)
		{
			if (lowest == 0)
				break;
			tmp = lower_bound(a[i + 1], a[i + 1] + c, a[i][j]);
			if (tmp == a[i + 1] + c)
			{
				tmp--;
				if (lowest > abs(a[i][j] - *tmp))
					lowest = abs(a[i][j] - *tmp);
				continue;
			}
			else if (tmp == (a[i + 1]))
			{
				tmp2 = *tmp;
			}

			else
			{
				tmp2 = *(tmp - 1);
			}

			if (abs(tmp2 - a[i][j]) < lowest)
			{
				lowest = abs(tmp2 - a[i][j]);
			}
			else if (abs(*tmp - a[i][j]) < lowest)
			{
				lowest = abs(*tmp - a[i][j]);
			}
		}
	}
	cout << lowest << endl;

	return 0;
}