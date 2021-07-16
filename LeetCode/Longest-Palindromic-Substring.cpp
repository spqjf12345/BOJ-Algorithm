//
//  Longest-Palindromic-Substring.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/06/28.
//

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;
string s;
string outPut = "";
bool check_Palindrom(int start, int end){
    while(start < end){
        if(s[start] == s[end]){
            start++;
            end--;
            continue;
        }
        return false;
    }
    
   
    return true;
}

int main(){
    cin >> s;
  
    for(int startIndex = 0; startIndex < s.length(); startIndex++){
        for(int endIndex = (int)s.length() - 1; endIndex > startIndex; endIndex--){
            cout << startIndex << " " << endIndex <<'\n';
            //cout << check_Palindrom(startIndex, endIndex) << '\n';
            if(check_Palindrom(startIndex, endIndex) == true){
                if((int)outPut.length() < (endIndex+1 - startIndex)){
                    outPut = s.substr(startIndex,  (endIndex+1 - startIndex));
                }
            }
        }
    }
    if(outPut == ""){
        outPut = s[0];
    }
    
    cout << outPut << '\n';
    
    
    return 0;
}
