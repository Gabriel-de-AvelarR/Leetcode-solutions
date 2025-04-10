class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
    vector<int> ransom(26, 0);
    vector<int> maga(26, 0);

    for(char c : ransomNote)
        ransom[c - 'a']++;

    for(char c : magazine)
        maga[c - 'a']++;

    for(int i = 0 ; i < ransom.size(); i++){
        if(ransom[i] > maga[i])
            return false;
    }
 
    return true;

    }

};