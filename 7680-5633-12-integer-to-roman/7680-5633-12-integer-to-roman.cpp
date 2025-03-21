class Solution {
public:
    string intToRoman(int num) {

        vector<string> char_base0 = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        vector<string> char_base1 = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        vector<string> char_base2 = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        vector<string> char_base3 = {"", "M", "MM", "MMM"};
        
        vector<vector<string>> decimal = {char_base0, char_base1, char_base2, char_base3};
        
        int base = 3;
        string result = "";
        
        while(base >= 0){
            int digit = num / static_cast<int>(pow(10, base));
            result += decimal[base][digit];

            num %= static_cast<int>(pow(10, base));
            base -= 1;
        }

        return result;
    }
};