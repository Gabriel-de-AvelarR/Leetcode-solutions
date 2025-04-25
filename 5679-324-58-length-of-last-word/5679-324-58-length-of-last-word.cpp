class Solution {
public:
    int lengthOfLastWord(string s) {
        //pular espacos em branco
        int end = s.size() - 1;
        while(end >= 0 && s[end] == ' ')
            end--;

        int beggining = end;
        while(beggining >= 0 && s[beggining] != ' ')
            beggining--;

        return end - beggining;
        
    }
};