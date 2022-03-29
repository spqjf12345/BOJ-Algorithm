//
//  17609_similarPalindrome.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/03/29.
//

#include <iostream>
#include <string.h>
    
using namespace std;
int n;

int palindrome(int left, int right, string s, bool check){
    while(left < right){
        if(s[left] != s[right]){
            if(check){
                if(palindrome(left+1, right, s, false) == 0 || palindrome(left, right-1, s, false) == 0) {
                    return 1;
                }
            }
            return 2;
        }else {
            left++;
            right--;
        }
    }
    return 0;
}

int main(){
    string s;
    cin >> n;
    while (n--) {
        cin >> s;
        cout << palindrome(0, (int)s.length()-1, s, true) << '\n';
    }
    return 0;
}
