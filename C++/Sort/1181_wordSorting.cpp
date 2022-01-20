//
//  1181_wordSorting.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/09/10.
//

#include <stdio.h>
#include <iostream>
#include <set>
using namespace std;

set<string, less<string>> s[51];
int N;
//set<string, greater<string>> s; less, greater_equal, less_equal
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        string str;
        cin >> str;
        s[str.length()].insert(str);
    }
    
    set<int> :: iterator it;
    
    
    for ( auto const & st : s )
     {
       for ( auto const & i : st )
          cout << i << '\n';
     }
    
    return 0;
}

