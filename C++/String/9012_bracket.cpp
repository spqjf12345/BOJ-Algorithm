//
//  bracket.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/04/21.
//

#include <iostream>
#include <stack>
#include <string>

using namespace std;
int N;


bool isBracket(string s){
    int len = (int)s.length();
    stack <char> ss;
    for(int i = 0; i < len; i++){
        char c = s[i];
        
        if(c == '('){
            ss.push(c);
        }else{
            if(!ss.empty()){
                ss.pop();
            }else{
                return false;
            }
        }
    }
    return ss.empty();
}


int main(){
    cin >> N;
    for(int i =0; i < N; i++){
        string s;
        cin >> s;
        if(isBracket(s)){
            cout << "YES" << '\n';
        }else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}
