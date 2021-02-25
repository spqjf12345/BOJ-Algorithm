//
//  1316_groupWord.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/02/23.
//

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;
vector<string> v;
vector<string> rev;

map<char, int> hash_map;

int main(){
    int n = 0, cnt = 0;
    string word = "";
    cin >> n;
    for(int i = 0; i <n; i++){
        cin >> word;
        v.push_back(word);
    }
    
    for(int i = 0;i < n; i++ ){
        string unique_word = v.at(i);
        unique_word.erase(unique(unique_word.begin(), unique_word.end()));
        rev.push_back(unique_word);
    }

    for(int k = 0; k < n; k++){
        bool check = false;
        int len = (int)rev[k].length();
        
        //cout << len << endl;
        for(int i = 0; i < len; i++){
            char t = rev[k][i];
            //cout << t << " ";
            hash_map[t] += 1;
            if(hash_map[t] >1){
                check = true;
                //cout << "check true" << endl;
            }
        }
        
        if(check == false){
            cnt++;
        }
        hash_map.clear();
    }
    cout << cnt << endl;

    return 0;
}
