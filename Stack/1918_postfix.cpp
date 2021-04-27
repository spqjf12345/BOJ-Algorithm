//
//  1918_postfix.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/04/26.
//

#include <stdio.h>
#include <string>
#include <iostream>
#include <stack>
#define MAX 100
using namespace std;

string arr[MAX];
stack <char> character;
stack <char> operators;

int main(){
    string temp;
    cin >> temp; // \n 받지 x
    int k = 0;
    int i = 0;
    for(i = 0; i < temp.length(); i++){
        //피연산자
        if( (temp[i] >= 65  and temp[i] <= 90) or (temp[i] >= 97 and temp[i] <= 122)){
            arr[k++] = temp[i]; // 정답 배열에 추가
//            character.push(temp[i]);
        }
        else {
            //연산자
            switch (temp[i]) {
                case '(':
                    operators.push('(');
                    break;;
                case '+':
                case '-':
                    while(!operators.empty() && operators.top() !='('){
                        arr[k++] = operators.top();
                        operators.pop();
                    }
                    operators.push(temp[i]);
                    break;
                //우선 순위가 높으므로
                case '*':
                case '/':
                    while(!operators.empty() && (operators.top() == '*' || operators.top() == '/')){
                        arr[k++] = operators.top();
                        operators.pop();
                    }
                    operators.push(temp[i]);
                    break;
                case ')':
                    while(!operators.empty() && operators.top() != '('){
                        arr[k++] = operators.top();
                        operators.pop();
                    }
                    if(operators.top() == '('){
                        operators.pop();
                    }
                    break;
                default:
                    break;
            }
        }
      
    }
    while(!operators.empty()){
        arr[k++] = operators.top();
        operators.pop();
    }
    
    for(int i = 0; arr[i] != "\0"; i++){
        cout << arr[i] << "";
    }
    cout << '\n';
    
    return 0;
}
