//
//  8958.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/12/11.
//

#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;
int Tcase;
string s;

void check(string s){
    int result = 0;
    for(int i =0; i < s.length(); i++){
        if(s[i] == 'O'){
            int idx = 1;
            result += idx;
            while(s[++i] != 'X' && i < s.length()){
                idx++;
                result += idx;
            }
        }
    }
    cout << result << '\n';
}
int main(){
    cin >> Tcase;
    
    for(int i =0; i < Tcase; i++){
        cin >> s;
        check(s);
    }
    
    return 0;
}
