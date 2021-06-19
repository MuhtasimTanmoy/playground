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


// faster solution
class Solution {
public:
    int jump(vector<int> &nums) {

    if ( nums.size() == 1 ) { return 0; }
    int stepsNeeded = 1;
    int currentIndexToCheck = 1;
    
    int nextMostIndex = nums[0];
    int window = nums[0];
        
    while(currentIndexToCheck < nums.size() -1) {
        
        if ( currentIndexToCheck + nums[currentIndexToCheck] > nextMostIndex) {
            nextMostIndex = currentIndexToCheck + nums[currentIndexToCheck];
        }
        
        if( currentIndexToCheck == window ) {
            window = nextMostIndex;
            stepsNeeded++;
        }
        
        currentIndexToCheck++;
    }

    return stepsNeeded;
}
};
