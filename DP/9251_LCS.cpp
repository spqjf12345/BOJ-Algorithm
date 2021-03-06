//
//  9251_LCS.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/03/01.
//

#include <cstdio>
#include <cstring>
#include <algorithm>

char X[1010];
char Y[1010];
int C[1010][1010];

using namespace std;

int main()
{
    scanf("%s", &X);
    scanf("%s", &Y);
    
    int lenX = (int)strlen(X);
    int lenY = (int)strlen(Y);
 
    for (int i = 1; i <= lenX; i++) {
        for (int j = 1; j <= lenY; j++) {
            if (X[i - 1] == Y[j - 1])
                C[i][j] = C[i - 1][j - 1] + 1;
            else
                C[i][j] = max(C[i - 1][j], C[i][j - 1]);
        }
    }
    printf("%d\n", C[lenX][lenY]);
    
    return 0;
}



