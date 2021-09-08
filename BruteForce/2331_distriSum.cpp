//
//  2331_distriSum.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/09/08.
//

#include <stdio.h>
#include <iostream>

using namespace std;
int N;

int find_generator(int n){
    int gen = n;
    while(n){
        gen += n % 10;
        n /= 10;
    }
    return gen;
}

int main(){
    cin >> N;
    for(int i = 1; i < N; i++){
        int result = find_generator(i);
        if(result == N){
            cout << i << '\n';
            return 0;
        }
    }
    cout << 0 << '\n';
   
    return 0;
}
