//
//  main.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2020/12/19.
//
#include <iostream>
#include <string>

using namespace std;


int main() {
    int temp;
    int needBag = 0;
    int setBag5 = 5;
    int setBag3 = 3;
    
    cin >> temp;
    
    while(temp > 0){
        if(temp % setBag5 ==0){
            temp -=setBag5;
            needBag +=1;
        }else if(temp % setBag3 ==0){
            temp -= setBag3;
            needBag +=1;
        }else if(temp > setBag5){
            temp -=setBag5;
            needBag +=1;
            
        }else{
            needBag = -1;
            break;
        }
            
    }

    cout << needBag <<endl;
    return 0;
}


