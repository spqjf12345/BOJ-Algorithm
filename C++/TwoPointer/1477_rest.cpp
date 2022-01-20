//
//  1477_rest.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/04/05.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int already, will, dis;
int min_num = 0;
vector<int> v;

void set_rest(){
    sort(v.begin(), v.end());
    int left = 1; int right = dis;
    while(left <= right){
        int mid = (left + right)/ 2;
        int rest = 0;
        for(int i = 1; i < (int)v.size(); i++){
            //0이 나누어 떨어지면 기존에 있던 위치에 다시 세우는 것이므로 
            if((v.at(i) - v.at(i - 1)) % mid == 0){
                rest += (v.at(i) - v.at(i - 1) - 1)/ mid;
            }else{
                rest += (v.at(i) - v.at(i - 1))/ mid;
            }
        }
        if(rest > will) left = mid + 1;
        else right = mid - 1;
    }
    cout << left << '\n';
}

int main(){
    cin >> already >> will >> dis;
    v.push_back(0);
    for(int i = 0; i < already; i++){
        int temp;
        cin >>temp;
        v.push_back(temp);
    }
    v.push_back(dis);
    set_rest();
    return 0;
}
