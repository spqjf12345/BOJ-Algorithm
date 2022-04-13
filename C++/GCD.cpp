//
//  GCD.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/04/13.
//

#include <stdio.h>
#include <iostream>

using namespace std;
int i = 2;
int n = 6;
int main(){
    for(i=2; i*i <= n;i++) {
        if(n % i == 0) {
            cout << i << " " << n/i << " ";
        }
            
        
    }
        
            
            
    return 0;
}
