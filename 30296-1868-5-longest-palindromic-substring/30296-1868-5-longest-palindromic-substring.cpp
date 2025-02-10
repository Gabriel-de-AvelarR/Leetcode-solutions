class Solution {
public:

    //para esse problema podemos utilizar a abordagem de expansão pelo centro O(n^2)
    string longestPalindromeA(string s) {
        if (s.empty()) return "";
        int start = 0, maxLen = 0;

        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                left--;
                right++;
            }
            return make_pair(left + 1, right - 1);
        };

        for (int i = 0; i < s.size(); ++i) {
            // Palíndromo ímpar
            auto [left1, right1] = expandAroundCenter(i, i);
            if (right1 - left1 > maxLen) {
                start = left1;
                maxLen = right1 - left1;
            }

            // Palíndromo par
            auto [left2, right2] = expandAroundCenter(i, i + 1);
            if (right2 - left2 > maxLen) {
                start = left2;
                maxLen = right2 - left2;
            }
        }

        return s.substr(start, maxLen + 1);
    }  

    //pode-se ainda utilizar uma abordagem de programação dinamica O(n^2) 
    string longestPalindromeB(string s) {
        int n = s.size();
        if (n == 0) return "";

        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int maxLen = 1, start = 0;

        // Substrings de comprimento 1 são palíndromas
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        // Verifica substrings de comprimento 2
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                start = i;
                maxLen = 2;
            }
        }

        // Verifica substrings maiores
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;

                // Verifica se s[i:j] é palíndromo
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    start = i;
                    maxLen = len;
                }
            }
        }

        return s.substr(start, maxLen);
    }

    //lembrando q a programacao dinamica eh uma técnica de otimização usada em algoritmos
    //para resolver problemas complexos ao dividi-los em subproblemas menores 
    //e resolver cada um apenas uma vez, armazenando os resultados para evitar cálculos repetidos


    //ela pode ser usada por exemplo com uma abordagem
    //top-down (memoization) ou bottom-up (tabulacao)

    //utilizando o algoritmo de fibonecci como exemplo de recursao ruim:

    /*int fib(int n) {
        if (n <= 1) return n;
        return fib(n - 1) + fib(n - 2);
    }*/

    //Fibonacci DP bottom-up

    /*int fib(int n) {
        if (n <= 1) return n;

        int dp[n + 1];
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];

    }

    int main() {
    int n = 10;
    cout << "Fibonacci(" << n << ") = " << fib(n) << endl;
    return 0;
    }*/

    //Fibonacci DP top-down

    /*int fibMemo(int n, vector<int>& memo) {
        if (n <= 1) return n;

        if (memo[n] != -1) return memo[n];  // Resultado já calculado
        memo[n] = fibMemo(n - 1, memo) + fibMemo(n - 2, memo);

        return memo[n];
    }

    int main() {
        int n = 10;
        vector<int> memo(n + 1, -1);
        cout << "Fibonacci(" << n << ") = " << fibMemo(n, memo) << endl;
        return 0;
    }*/


    //além disso temos a abordagem O(n) utilizando o chamado Manacher's Algorithm
    string longestPalindrome(string s) {
        if (s.empty()) return "";

        // Pré-processamento
        string t = preprocess(s);
        int n = t.size();
        vector<int> P(n, 0);

        int center = 0, right = 0;
        int maxLen = 0, start = 0;

        for (int i = 0; i < n; ++i) {
            int mirror = 2 * center - i;

            // Otimização: evita expandir desnecessariamente
            if (i < right) {
                P[i] = min(right - i, P[mirror]);
            }

            // Expansão ao redor do centro
            while (i + P[i] + 1 < n && i - P[i] - 1 >= 0 &&
                   t[i + P[i] + 1] == t[i - P[i] - 1]) {
                P[i]++;
            }

            // Atualiza centro e borda se expandimos mais à direita
            if (i + P[i] > right) {
                center = i;
                right = i + P[i];
            }

            // Atualiza o palíndromo mais longo encontrado
            if (P[i] > maxLen) {
                maxLen = P[i];
                start = (i - maxLen) / 2;
            }
        }

        return s.substr(start, maxLen);
    }

private:
    // Pré-processamento para lidar com palíndromos pares e ímpares
    string preprocess(const string& s) {
        string t = "#";
        for (char c : s) {
            t += c;
            t += "#";
        }
        return t;
    }
};