//
//  1259_palindrom.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/12/11.
//

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;
int n;
string check_palindrom(int n){
    string s = to_string(n);
    int start = 0;
    int end = (int)s.length() - 1;
    
    while(start <= end){
        if(s[start] != s[end]){
            return "no";
        }
        start++;
        end--;
    }

    return "yes";
}
int main(){
    cin >> n;
    while(n !=0){
        cout << check_palindrom(n) << '\n';
        cin >> n;
    }
    return 0;
}
