class Solution {
public:
    int maximum69Number (int num) {
        int maximum = num;
        vector<int> permutation = intToVector(num);
        for(int i = 0; i < permutation.size(); i++){
            int original = permutation[i];

            if(permutation[i] == 6)
                permutation[i] = 9;
            else if(permutation[i] == 9)
                permutation[i] = 6;
            
            int newPermutation = vectorToInt(permutation);
            if(newPermutation > maximum)
                maximum = newPermutation;
            
            permutation[i] = original;
        }

        return maximum;
    }

    vector<int> intToVector(int num){
        vector<int> digits;
        while(num != 0){
            int digit = num % 10;
            num /= 10;
            digits.push_back(digit); //armazena ao contrario           
        }

        reverse(digits.begin(), digits.end());

        return digits;
    }

    int vectorToInt(vector<int> digits){
        int num = 0;
        for(int i = 0; i < digits.size(); i++){
            num = num + digits[i] * pow(10, digits.size() - i - 1);
        }

        return num;
    }
};