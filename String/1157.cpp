//
//  1157.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/04/08.
//

#include <stdio.h>
#include <iostream>
#include <cctype>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

vector<char> si;

int main(){
    map<char,int> hm;
    int max = 0;
    string maxString = "";
    string str;
    cin >> str;
    transform(str.begin(),str.end(), str.begin(), ::toupper);
    
    for(int i =0; i < str.length(); i++){
        char st = str[i];
        hm[st] += 1;
    }
    
    map<char, int>::iterator iter;
    
    for(iter = hm.begin(); iter != hm.end() ; iter++){
        if(iter == hm.begin()){
            si.push_back(iter->second);
        }
        if(iter->second >= max){
            if(iter->second == max){
                si.push_back(iter->second);
            }else if(iter->second > max){
                si.clear();
                si.push_back(iter->second);
            }
            max = iter->second;
            maxString = iter->first;
        }
    }
    
    if(si.size() > 1){
        cout << "?" << '\n';
        return 0;
    }
    
    cout << maxString << '\n';
    
    return 0;
}
