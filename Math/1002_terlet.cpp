//
//  1002_terlet.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/06/12.
//

#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;
int Tcase;
int x1, y_1, r1, x2, y2, r2;
int answer;


int find_location(){
    int location = 0;
    int d1 = pow(r1 + r2, 2);
    int d2 = pow(r1 - r2, 2);
    
    int oper = pow((x1 - x2), 2) + pow((y_1 - y2), 2);
//    cout << "d2 : " << d2 << '\n';
//    cout << "oper : " << oper << '\n';
    if(oper == 0){
        if(d2 == 0){
            location = -1;
        }else{
            location = 0;
        }
    }else if (oper == d1 || oper == d2){
        location = 1;
    }else if(d2 < oper && oper < d1){
        location = 2;
    }else {
        location = 0;
    }
    
    return location;
}

int main(){
    cin >> Tcase;
    for(int i = 0; i < Tcase; i++){
        cin >> x1 >> y_1 >> r1 >> x2 >> y2 >> r2;
        answer = find_location();
        cout << answer << '\n';
    }
    return 0;
}
