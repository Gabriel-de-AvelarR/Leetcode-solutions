class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
       //pesquisa pelas colunas
       for(int currentColumn = 0; currentColumn < matrix[0].size(); currentColumn++){
            int currentX = 0;
            int currentY = currentColumn;
            while(currentX + 1 < matrix.size() && currentY + 1< matrix[0].size()){
                if(matrix[currentX][currentY] != matrix[currentX + 1][currentY + 1])
                    return false;
                
                currentX++;
                currentY++;
            }
        }

        //pesquisa pelas linhas
        for(int currentRow = 0; currentRow < matrix.size(); currentRow++){
            int currentX = currentRow;
            int currentY = 0;
            while(currentX + 1 < matrix.size() && currentY + 1< matrix[0].size()){
                if(matrix[currentX][currentY] != matrix[currentX + 1][currentY + 1])
                    return false;
                
                currentX++;
                currentY++;
            }
        }

       return true;
    }
};