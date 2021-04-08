//
//  1152_count.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/04/08.
//

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

string str = "";

int main(){
    int cnt = 0;
    getline(cin, str);
    //cout << str.length()<< '\n';
    if(str.empty()){
        cout << "0";
        return 0;
    }
    for(int i = 0; i < str.length(); i++){
        if(str[i] == ' '){
            cnt++;
        }
    }
    if(str[0] == ' '){
        cnt--;
    }
    if(str[str.length() - 1] == ' '){
        cnt--;
    }
    
    cout << cnt + 1 << "\n";
}
