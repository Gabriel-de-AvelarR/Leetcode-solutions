class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> pastLetters;
        auto windowStart = s.begin();
        int maxString = 0;

        for(auto currentPos = s.begin(); currentPos != s.end(); currentPos++){
            while(pastLetters.find(*currentPos) != pastLetters.end()){
                pastLetters.erase(*windowStart);
                windowStart++;
            }

            pastLetters.insert(*currentPos);
            maxString = max(maxString, static_cast<int>(currentPos - windowStart + 1));
        }

        return maxString;
    }
};