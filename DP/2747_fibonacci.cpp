//
//  2747_fibonacci.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/04/23.
//

#include <stdio.h>
#include <iostream>

using namespace std;
int memo[46];

int fibonacci(int N){
    if(N == 0) return 0;
    else if ( N == 1) return 1;
    else {
        if(memo[N] >0) return memo[N];
        memo[N] = fibonacci(N-1) + fibonacci(N-2);
        return memo[N];
    }
}

int main(){
    int N;
    cin >> N;
    cout << fibonacci(N) << '\n';
}
