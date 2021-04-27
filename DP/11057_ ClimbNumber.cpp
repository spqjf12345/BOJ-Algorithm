//
//  11057_ ClimbNumber.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/04/25.
//

#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;
int n;
int part = 10007;
int sum[1001][10]; // 가능한 수 0 ~ 9
int ret = 0;

int find_climbCount(){
    
    //n이 1일 경우
    for(int i = 0; i < 10; i++){
        sum[1][i] = 1;
    }
    
    // n >= 2
    for(int i = 2; i <= n; i++){
        for(int j = 0; j < 10; j++){
            for(int k = j; k >=0; k--){
                sum[i][j] += sum[i-1][k];
            }
            sum[i][j] %= part;
            
        }
    }
    
    for(int i =0; i < 10; i++){
        ret = (ret + sum[n][i]) % 10007;
    }

    return ret;
}

int main(){
    cin >> n;
    cout << find_climbCount() << '\n';
   
    return 0;
}
