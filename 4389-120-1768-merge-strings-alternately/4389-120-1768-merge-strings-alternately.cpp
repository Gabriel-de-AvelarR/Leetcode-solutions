class Solution {
public:
    string mergeAlternately(string word1, string word2) {
    int indexFirst = 0;
    int indexSecond = 0;
    string result;
    while(indexFirst < word1.size() || indexSecond < word2.size()){
        if(indexFirst < word1.size())
            result.push_back(word1[indexFirst]);
        
        if(indexSecond < word2.size())
            result.push_back(word2[indexSecond]);

        indexFirst++;
        indexSecond++;
        
    }

    return result;
    }
};