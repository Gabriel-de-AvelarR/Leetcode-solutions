class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int len = flowerbed.size();

        //para o caso de so ter um espaço
        if(len == 1){
            if( (flowerbed[0] == 0 && (n <= 1) ) || (flowerbed[0] == 1 && n == 0) )
                return true;
            
            return false;
        }
        //checa se pode plantar na primeira casinha
        if(flowerbed[0] == 0 && flowerbed[1] == 0){
            flowerbed[0] = 1;
            n--;
        }
        
        //em sequencia verifica-se ate o penultimo
        for(int pos = 1; pos + 1 < len; pos++){
            if(flowerbed[pos] == 0 && flowerbed[pos - 1] == 0 && flowerbed[pos + 1] == 0){
                flowerbed[pos] = 1;
                n--;
            }
        }

        //checa se pode plantar na ultima casinha
        if(flowerbed[len - 1] == 0 && flowerbed[len - 2] == 0){
            flowerbed[len - 1] = 1;
            n--;
        }

        if(n <= 0){
            return true;
        }

        return false;

    }
};