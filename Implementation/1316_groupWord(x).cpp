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
#include <algorithm>
#include <unordered_map>

using namespace std;
unordered_map<char, bool> dic;
string word = "";
int n;
vector<string> rev;
int cnt = 0;


bool check_word(string word){
    bool dic[26] = { false };
    for(int i = 0; i < word.length(); i++){
        char idx = word[i];
        if(dic[idx - 'a']){
            return false;
        }else {
            dic[idx - 'a'] = true;
            while(1){
                if (idx != word[++i]) { //현재와 다른 알파벳이 올때까지 탐색
                    i--;
                    break;
                }
            }
        }
    }
    return true;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> word;
        if(check_word(word)) {
            cnt++;
        }
    }
    cout << cnt << '\n';
    
    return 0;
}
//vector<string> v;
//vector<string> rev;
//
//int main(){
//    int n = 0, cnt = 0;
//    string word = "";
//    cin >> n;
//    for(int i = 0; i < n; i++){
//        cin >> word;
//        v.push_back(word);
//    }
//
//    for(int i = 0; i < n; i++ ){
//        string unique_word = v.at(i);
//        unique_word.erase(unique(unique_word.begin(), unique_word.end()));
//        rev.push_back(unique_word);
//    }
//
//    for(int k = 0; k < n; k++){
//        map<char, int> hash_map;
//        bool check = false;
//
//        for(int i = 0; i < rev.at(k).length(); i++){
//            char t = rev[k][i];
//            hash_map[t]++;
//            if(hash_map[t] > 1){
//                check = true;
//            }
//        }
//
//        if(check == false){
//            cnt++;
//        }
//    }
//
//    cout << cnt << endl;
//    return 0;
//}
