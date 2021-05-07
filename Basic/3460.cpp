//
//  3460.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/05/08.
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;
int TC;
vector<int> v;

void find_one(int n){
    int divide = 2;
    while(n != 0){
        v.push_back(n % divide);
        n = n / 2;
    }
    for(int i = 0; i < v.size(); i++){
        if(v.at(i) == 1){
            cout << i << " ";
        }
    }
    v.clear();
}
int main(){
    cin >> TC;
    for(int i = 0; i <TC; i++){
        int n;
        cin >> n;
        find_one(n);
    }
    return 0;
}
