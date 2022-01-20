//
//  2225_sumDecomposition.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/05/08.
//

#include <iostream>
#define MOD 1000000000

using namespace std;

int N, K, dp[201][201];

int main() {
   //dp[N][K]
   cin >> N >> K;

   for (int i = 1; i <= K; i++) {
      dp[0][i] = 1;
   }
   for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= K; j++) {
         dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % MOD;
      }
   }
   cout << dp[N][K] << "\n";

   return 0;
}
