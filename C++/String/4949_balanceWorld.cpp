//
//  4949_balanceWorld.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/09/10.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <stack>

using namespace std;
int idx = 0;

string check(string s){
    stack<char> token;
    
    for(int i =0; i < s.length(); i++){
        if(s[i] == '(' || s[i] == '['){
            token.push(s[i]);
        }else if (s[i] == ')') {
            if(!token.empty() && token.top() == '('){
                token.pop();
            }else{
                token.push(s[i]);
            }
        }else if (s[i] == ']') {
            if(!token.empty() && token.top() == '['){
                token.pop();
            }else{
                token.push(s[i]);
            }
        }else {
            continue;
        }
    }
    
    if(!token.empty()){
        return "no";
    }else {
        return "yes";
    }

   
}

int main(){
    while(true){
        string s;
        getline(cin, s);
        if(s.length() == 1 && s[0] == '.'){
            break;
        }

        cout << check(s) << '\n';
    }

    return 0;
}
