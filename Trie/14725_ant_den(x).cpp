//
//  14725_ant_den.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/02/25.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int char_to_index(char c){
    return c - '0';
}

struct Trie {

    bool is_terminal;
    Trie * next[10];
    Trie(): is_terminal(false) {
        memset(next, 0, sizeof(next));
    }

    ~Trie() {
        for (int i = 0; i < 10; ++i) {
            if (next[i]) {
                delete next[i];
            }
        }
    }

    void insert(const char * key) {
        //cout << "key : "<< *key << " " << endl; //9, 1, 1 \0
        if (*key == '\0') {
            is_terminal = true;
        }
        else {
            int index = char_to_index(*key);
            if (next[index] == 0)
                next[index] = new Trie();
            next[index]->insert(key + 1); // 있으면 만득지 않고 다음 키 확인
        }
    }

    bool find(const char * key) {

        if (*key == '\0') return true;

        // Return false if there is already terminal node before string is the end.
        
        //while finding -> 마지막 노드 만나면 false 하게 함
        if (is_terminal) return false;

        int index = char_to_index(*key);
        return next[index]->find(key + 1);
    }
};

string depth(int j){
    string s = "";
    if(j ==0) return s;
    else{
        for(int i =0; i <j; i++){
            s += "--";
        }
        return s;
    }
    
}


int main(){
    int N;
    cin >> N;
    
    char den[N][26]; // 알파벳 길이
    
    Trie * root = new Trie();
    int n;
    for(int i =0; i < N; i++){
        //cout << "enter : ";
        cin >> n;
        for(int j =0; j < n; j++){
            scanf("%s", &den[i][j]);
            //cin >> den[i][j];
        }
        root->insert(den[i]);
        //cout << den[i];
    }
    
//    for(int i = 0; i < N; i++){
//        //root->find(den[i]);
//        printf("%s: be\n", root->find(den[i]) != 0 ? "Prefix Exist" : "Prefix Not Exist");
//
//    }
    
    for(int i =0; i < N; i++){
//        cout << strlen(den[i]) << endl;
//        cout << sizeof(den[i]) << endl;
//        cout << sizeof(char) << endl;
        string str = "";
        for(int j = 0; j < strlen(den[i]); j++){
            str = depth(j);
            //cout << str << " " << endl;
            cout << str + den[i][j] << endl;
        }
    }
    
    

    
    return 0;
}

