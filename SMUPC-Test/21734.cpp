//
//  21734.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/06/12.
//

#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;
string num;

int main(){
    cin >> num;
    for(int i =0; i < num.length(); i++){
        int ten = 0;
        int n = (int)num[i];

        do{
            ten += n % 10;
            n = n / 10;
        }while(n != 0);
            
        for(int j = 0; j < ten; j++){
            cout << num[i];
        }
        cout << '\n';
       
    }
    return 0;
}
