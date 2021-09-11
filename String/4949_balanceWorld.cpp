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
string s;
int idx = 0;

string check(string s){
    stack<char> token;
    
    for(int i =0; i < s.length(); i++){
        if(s[i] == '(' || s[i] == '['){
            token.push(s[i]);
        }else if (s[i] == ')'){
            if(!token.empty()){
                if(token.top() == '('){
                    token.pop();
                }
            }else {
                return "no";
            }
        }else if (s[i] == ']'){
            if(!token.empty()){
                if(token.top() == '['){
                    token.pop();
                }
            }else {
                return "no";
            }
        }else if(s[i] == '.'){
            break;
        }
        
    }
    
    if(!token.empty()){
//        while(!token.empty()){
//            cout << token.top() << '\n';
//            token.pop();
//        }
        //cout << "here" << '\n';
        return "no";
    }else {
        return "yes";
    }

   
}

int main(){
    while(true){
        getline(cin, s);
        if(s.length() == 1 && s[0] == '.'){
            break;
        }

        cout << check(s) << '\n';
    }

    return 0;
}
