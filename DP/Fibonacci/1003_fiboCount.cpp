//
//  1003_fiboCount.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/09/02.
//

#include <stdio.h>
#include <iostream>

using namespace std;
int TC;
int n;

int memo[41] = {0, };

int fibo_count(int n){
    if(n == 0){
        return 0;
    }else if(n == 1){
        return 1;
    }
    
    if(memo[n] > 0){
        return memo[n];
    }
    
    memo[n] = fibo_count(n-1) + fibo_count(n-2);
    return memo[n];
    
}

int main(){
    cin >> TC;
    for(int i = 0; i < TC; i++){
        cin >> n;
        if(n == 0){
            cout << "1 0" <<'\n';
        }
        else {
            cout << fibo_count(n - 1) << " " << fibo_count(n) << '\n';
        }
    }
    return 0;
}
