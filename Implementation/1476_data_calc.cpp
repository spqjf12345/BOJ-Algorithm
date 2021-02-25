//
//  1476_data_calc.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/02/22.
//

#include <stdio.h>
#include <iostream>

using namespace std;

int main(){

    int e, s, m;
    int y = 0;
    
    cin >> e >> s >> m;
    while(++y){
        if(!((y - e) % 15 || (y - s) % 28 || (y - m) % 19)){ // 셋다 true가 아닐때에만 
            break;
        }
    }
    
    cout << y << endl;
    return 0;
}
