class Solution {
public:
    int jump(vector<int> &nums) {

    int stepsNeeded = 0;
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
            checkIndex--;
        }
        return canBeReachedFromAtMostIndex;
    };

    int _targetIndex = nums.size() - 1;
    if (_targetIndex == 0 ) { return 0; }
    while (true)
    {
        _targetIndex = canBeReachedFromAtMost(_targetIndex);
        stepsNeeded++;
        if (_targetIndex == 0) { break; }
    }

    return stepsNeeded;
}
};