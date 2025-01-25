class Solution {
public:

    //ABORDAGEM PARA UMA ESTRUTURA DE DADOS DINAMICA

    int lengthOfLongestSubstringA(string s) {
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

    //ABORDAGEM PARA UM ARRAY FIXO 
    int lengthOfLongestSubstring(string s) {
        vector<int> pastLettersIndex(256, -1); 
        int maxString = 0;             
        int windowStart = 0;                  

        for (int currentPos = 0; currentPos < s.size(); currentPos++) {
            if (pastLettersIndex[s[currentPos]] >= windowStart) 
                windowStart = pastLettersIndex[s[currentPos]] + 1;
            
            pastLettersIndex[s[currentPos]] = currentPos;
            maxString = max(maxString, currentPos - windowStart + 1);
        }

        return maxString;
    }
};