//
//  5585_change.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/02/25.
//

#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
    int change[6] = {500, 100, 50, 10, 5, 1};
    int money;
    cin >> money;
    int moneyTochange = 1000 - money;
    //cout << moneyTochange << endl;
    int count = 0;
    for(int i = 0; i <6; i++){
        if(moneyTochange == 0) break;
        count += moneyTochange / change[i];
        moneyTochange = moneyTochange % change[i];
        //cout << moneyTochange << endl;
    }
    cout << count << endl;
    return 0;
}
