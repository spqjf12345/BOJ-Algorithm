//
//  10828_stack.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/02/06.
//

#include <string>
#include <string.h>
#include <iostream>
#include <stack>

using namespace std;


int main(void){
    int n;
    cin >> n;
    string s;

    stack<int> arr;
    
    for(int i=0; i< n; i++){
        cin >> s;
        if(s == "push"){
            int num;
            cin >> num;
            arr.push(num);
        }else if(s == "top"){
            if(arr.empty()){
                cout << "-1" << endl;
            }else {
                cout << arr.top() << endl;
            }
        }else if(s == "size"){
            cout << arr.size() << endl;
        }else if(s == "empty"){
            if(arr.empty()){
                cout << "1" << endl;
            }else{
                cout << "0" << endl;
            }
            //cout << (arr.empty() ? 1 : 0) << endl;
        }else if(s == "pop"){
            if(arr.empty()){
                cout << "-1" << endl;
            }else{
                cout << arr.top() << endl;
                arr.pop();
            }
        }
    }
    return 0;
}
