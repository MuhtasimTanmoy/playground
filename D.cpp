#include <bits/stdc++.h>
using namespace std;

int jump(vector<int> &nums)
{

    int stepsNeeded = 0;

    int initialTargetIndex = nums.size() - 1;

    function<int(int)> canBeReachedFromAtMost = [&](int targetIndex) -> int
    {
        int canBeReachedFromAtMostIndex = targetIndex - 1;

        int checkIndex = targetIndex - 1;

        while (checkIndex >= 0)
        {
            int distance = targetIndex - checkIndex;
            if (distance <= nums[checkIndex])
            {
                canBeReachedFromAtMostIndex = checkIndex;
            }
        }
        return canBeReachedFromAtMostIndex;
    };

    while (canBeReachedFromAtMost(initialTargetIndex) != 0)
    {
        cout<<"Steps"<<endl;
        stepsNeeded++;
    }

    return stepsNeeded;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);

    vector<int> list { 2,3,1,1,4 };
    // jump(list);
    return 0;
}
