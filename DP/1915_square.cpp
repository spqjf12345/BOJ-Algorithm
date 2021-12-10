//
//  1915_square.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/02/05.
//

#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;

int R1, R2;
int arr[1001][1001] = {0};
int memo[1001][1001] = {0};
string s;
int ans = 0;



void input(){
    cin >> R1 >> R2;
    for(int i = 0; i < R1; i++){
        cin >> s;
        for(int j = 0; j < R2; j++){
            arr[i][j] = s[j] - 48;
            if(arr[i][j] == 1){
                memo[i][j] = 1;
                ans = memo[i][j];
            }
        }
    }
}

void find_biggest_square(){

    for(int i = 1; i < R1; i++){
        for(int j = 1; j < R2; j++){
            if(arr[i-1][j-1] == 1 && arr[i-1][j] == 1 && arr[i][j-1] == 1 && arr[i][j] == 1){
                memo[i][j] = min(memo[i-1][j-1], memo[i-1][j]);
                memo[i][j] = min(memo[i][j], memo[i][j-1]) + 1;
            }
            ans = max(ans, memo[i][j]);
        }
    }
    cout << ans * ans << endl;
    
    
    
}

int main (){
    input();
    find_biggest_square();
    return 0;
}


