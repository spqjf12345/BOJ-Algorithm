//
//  1110_addCycle.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/04/21.
//

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;
string number;



int main(){
    int count = 0;
    int result = -1;
    string temp;
    cin >> number;
    
    int first = number[0] - '0';
    int second = number[1] - '0';
    
    //한자리수 일때
    if(second == -48){
        second = first;
        first = 0;
    }
    
    while(true){
        if(result == stoi(number)) break;
        if(first + second > 10){
            temp = to_string(first + second)[1];
        }else if(first + second == 10){
            temp = "0";
        }else{
            temp = to_string(first + second);
        }

        temp = to_string(second).append(temp);
        //cout << "temp is " << temp << '\n';
        first = temp[0] - '0';
        second = temp[1] - '0';
        result = stoi(temp);
        count++;
    }
    
    cout << count << '\n';
    
    return 0;
}
