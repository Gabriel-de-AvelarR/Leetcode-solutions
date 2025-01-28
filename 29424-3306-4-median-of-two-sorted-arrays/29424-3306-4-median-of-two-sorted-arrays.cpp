class Solution {
public:
    //This solution has O(m + n) complexity as it goes thorugh the entire merged vector
    double findMedianSortedArraysA(vector<int>& nums1, vector<int>& nums2) {
        vector<int> mergedArray;
        int nums1Index = 0;
        int nums2Index = 0;

        while(nums1Index < nums1.size() && nums2Index < nums2.size()){
            if(nums1[nums1Index] < nums2[nums2Index]){
                mergedArray.push_back(nums1[nums1Index]);
                nums1Index++;
            }
            else{
                mergedArray.push_back(nums2[nums2Index]);
                nums2Index++;
            }
        }

        //checks if both indexes reached the end of their arrays 
        while(nums1Index < nums1.size()){
            mergedArray.push_back(nums1[nums1Index]);
            nums1Index++;
        }

        while(nums2Index < nums2.size()){
            mergedArray.push_back(nums2[nums2Index]);
            nums2Index++;
        }

        int mid = mergedArray.size() / 2;
        if(mergedArray.size() % 2 == 0)
            return ((mergedArray[mid - 1] + mergedArray[mid]) / 2.0);
        else
            return (mergedArray[mid]);

        return -1;
    }

    //this solution has a O(log(n+m)) solution as it doesnt run across the entire vector
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
        // Garantir que nums1 seja o menor array
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int x = nums1.size(); // Tamanho do primeiro array (menor)
        int y = nums2.size(); // Tamanho do segundo array (maior)
        int low = 0, high = x; // Limites da busca binária no array menor

        while (low <= high) {
            int partitionX = (low + high) / 2; // Ponto de corte em nums1
            int partitionY = ((x + y + 1) / 2) - partitionX; // Complemento em nums2

            // Definir os valores ao redor das particoes
            int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            int minRightX = (partitionX == x) ? INT_MAX : nums1[partitionX];

            int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
            int minRightY = (partitionY == y) ? INT_MAX : nums2[partitionY];

            // Verificar se encontramos a particao correta
            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                // Caso em que o total de elementos é par
                if ((x + y) % 2 == 0) {
                    return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
                } 
                // Caso em que o total de elementos é ímpar
                else {
                    return max(maxLeftX, maxLeftY);
                }
            }
            // Se maxLeftX > minRightY, mova a busca para a esquerda
            else if (maxLeftX > minRightY) {
                high = partitionX - 1;
            }
            // Caso contrário, mova a busca para a direita
            else {
                low = partitionX + 1;
            }
        }

        // Caso de erro (não deveria ocorrer para arrays ordenados)
        throw invalid_argument("Input arrays are not sorted!");
    }
    
};