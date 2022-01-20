//
//  10610_30.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/01/10.
//

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;


bool cmp(char a, char b)
{
    if (a > b) {
        return true;
    }
    return false;
}

int main(){
    string s;
    int sum = 0;
    int zeroCount = 0;
    
    cin >> s;
    for(int i = 0; i < s.length(); i++){
        sum += s[i] - '0';
        if(s[i] - '0' == 0){
            zeroCount++;
        }
    }
    
    if(sum % 3 == 0 && zeroCount > 0){
        sort(s.begin(), s.end(), cmp);
        cout << s << '\n';
    }else {
        cout << -1 << '\n';
    }
    
   
    
    return 0;
}
