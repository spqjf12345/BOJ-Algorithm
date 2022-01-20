//
//  1966_printerQueue.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/04/22.
//

#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int testCase;
int ducumentN;
int what;
int document[101];
priority_queue<int> pri_queue;

void find_priority(){
    int me = document[what]; //5
    int best = 0;
    for(int i =0; i <ducumentN; i++){
        if(document[i] > best){
            best = document[i];
        }
    }
    cout << "me is " << me << '\n';
    cout << "best is " << best << '\n';
    
    if(me == best){
        cout << "1" << '\n';
    }

}

void clear_document(){
    for(int i = 0; i < ducumentN; i++){
        document[i] = 0;
    }
}

int main(){
    cin >> testCase;
    for(int i =0; i < testCase; i++){
        cin >> ducumentN >> what;
        for(int i = 0; i <ducumentN; i++ ){
            cin >> document[i];
        }
        find_priority();
        clear_document();// document 초기화
    }
    return 0;
}
