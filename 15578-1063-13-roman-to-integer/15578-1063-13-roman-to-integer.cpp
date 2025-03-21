class Solution {
public:

    //utilizando um mapa (semelhante a uma tabela hash)
    int romanToInt(string s){
        unordered_map<char, int> conversao = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int soma = 0;
        
        for(auto it = s.begin(); it != s.end(); ++it){
            if(next(it) != s.end() && conversao[*it] < conversao[*next(it)])
                soma -= conversao[*it];
            else
                soma += conversao[*it];
        }

        return soma;
    }


    int romanToIntSWITCHCASE(string s) {
        int soma = 0;
        for(int i =0; i < s.size(); i++){
            switch(s[i]){
                case 'I':
                    if(i + 1 < s.size() && s[i + 1] == 'V'){
                        soma+= 4;
                        i++; 
                    }
                    else if(i + 1 < s.size() && s[i + 1] == 'X'){
                        soma+= 9;
                        i++; 
                    }
                    else
                        soma+= 1;
                    
                break;

                case 'V':
                    soma+= 5;
                
                break;
                
                case 'X':
                    if(i + 1 < s.size() && s[i + 1] == 'L'){
                        soma+= 40;
                        i++; 
                    }
                    else if(i + 1 < s.size() && s[i + 1] == 'C'){
                        soma+= 90;
                        i++; 
                    }
                    else
                        soma+= 10;

                break;

                case 'L':
                    soma+= 50;

                break;
                
                case 'C':
                    if(i + 1 < s.size() && s[i + 1] == 'D'){
                        soma+= 400;
                        i++; 
                    }
                    else if(i + 1 < s.size() && s[i + 1] == 'M'){
                        soma+= 900;
                        i++; 
                    }
                    else
                        soma+= 100;

                break;
                
                case 'D':
                    soma+= 500;

                break;
                
                case 'M':
                    soma+= 1000;

                break;
            }
        }

        return soma;    
    }
};