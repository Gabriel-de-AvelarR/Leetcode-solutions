class Solution {
public:
    int reverse(int x) {
        //lembrando que o valor de 2**31 eh 2147483647 
        //enquanto que o valor (complemento de 2) de -2**31 eh 2147483648
        
        int reversedInt = 0;
        int digit = 0;
        while(x!=0){
            digit = x % 10;
            //tira o ultimo digito do mumero
            x/=10;

            if(reversedInt > INT_MAX / 10 || reversedInt == INT_MAX / 10 && digit > 7)
                return 0;
            if(reversedInt < INT_MIN / 10 || reversedInt == INT_MIN / 10 && digit < -8)
                return 0;

            //coloca o ultimo digito do numero no comeco
            //so adiciona depois da verificacao para nao dar overflow
            reversedInt = reversedInt * 10 + digit;
        }

        return reversedInt;
    }
};