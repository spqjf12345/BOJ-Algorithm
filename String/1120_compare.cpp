//
//  1120_compare.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/12/11.
//

#include <stdio.h>
#include <iostream>

using namespace std;
string a, b;
int compare(string a, string b){
    int diff = 0;
    int min = 1000000;
    if(a.length() == b.length()){
        for(int i =0; i < a.length(); i++){
            if(a[i] != b[i]){
                diff++;
            }
        }
    }else {
        for(int i =0; i <= b.length() - a.length(); i++){
            diff = 0;
            for(int j =0; j < a.length(); j++){
                if(a[j] != b[j+i]){
                    diff++;
                }
            }
            if(diff < min) { min = diff; }
        }
        return min;
    }
    
    return diff;
}
int main(){
    cin >> a >> b;
    cout << compare(a, b) << '\n';

    return 0;
}
