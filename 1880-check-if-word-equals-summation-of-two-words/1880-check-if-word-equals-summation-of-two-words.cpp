class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        auto convert = [](string& word) -> int {
            for (int i = 0; i < word.size(); i++) 
                word[i] = (char)(word[i] - 'a' + '0');
            return stoi(word);
        };
        auto first = convert(firstWord);
        auto second = convert(secondWord);
        auto third = convert(targetWord);
        return first + second == third;
    }
};