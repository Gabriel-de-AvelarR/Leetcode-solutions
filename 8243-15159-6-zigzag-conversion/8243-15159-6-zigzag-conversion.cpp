class Solution {
public:
    //solução com saltos
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        string result;
        int n = s.size();

        for (int i = 0; i < numRows; ++i) {
            int step1 = 2 * (numRows - 1 - i); // Salto principal
            int step2 = 2 * i;                // Salto secundário

            int pos = i;
            bool useStep1 = true;

            while (pos < n) {
                result += s[pos];
                // Alterna entre step1 e step2 se ambos forem válidos
                if (step1 > 0 && step2 > 0) {
                    pos += useStep1 ? step1 : step2;
                    useStep1 = !useStep1;
                } else { // Apenas um salto válido (topo ou base)
                    pos += max(step1, step2);
                }
            }
        }

        return result;
    }

    //expansão direta
    string convertA(string s, int numRows){

        if (numRows == 1 || s.size() <= numRows) return s;

        vector<string> rows(min(numRows, int(s.size())));
        int currRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[currRow] += c;
            if (currRow == 0 || currRow == numRows - 1) {
                goingDown = !goingDown;
            }
            currRow += goingDown ? 1 : -1;
        }

        string result;
        for (string row : rows) {
            result += row;
        }

        return result;
        }
};