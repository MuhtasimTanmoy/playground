class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        function<int(char)> traverse = [&](char key) -> int {
            int maxOccur = 0;
            int j = 0;
            for (int i = 0 ; i < answerKey.size(); i++) {
                maxOccur += answerKey[i] == key;
                if (maxOccur > k) maxOccur -= answerKey[j++] == key;
            }
            return answerKey.size() - j;
        };
        return max(traverse('T'), traverse('F'));
    }
};