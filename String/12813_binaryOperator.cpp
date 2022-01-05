//
//  12813_binaryOperator.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/12/26.
//

#include <stdio.h>
#include <iostream>

using namespace std;
string s;

char A[100001] = {0, };
char B[100001] = {0, };
char result[100001] = {0, };

void print(){
    for(int i = 0; i < 6; i++){
        cout << result[i];
    }
    cout << '\n';
}

int main(){
    cin >> A >> B;

    //AND
    for(int i = 0; i < 6; i++){
        result[i] = A[i] & B[i];
    }
    print();
    
    //OR
    for(int i = 0; i < 6; i++){
        result[i] = A[i] | B[i];
    }
    print();
    
    //XOR
    for(int i = 0; i < 6; i++){
        result[i] = A[i] != B[i] ? '1' : '0';
    }
    print();
    
    //~A
    for(int i = 0; i < 6; i++){
        result[i] = A[i] == '1' ? '0' : '1';
    }
    print();
    
    //~A
    for(int i = 0; i < 6; i++){
        result[i] = B[i] == '1' ? '0' : '1';
    }
    print();
    
    return 0;
}
