//
//  19598_room_min.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/02/10.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int assign_room_min(int n, vector <pair<int, int>> v){
    int cnt = 1;
    sort(v.begin(), v.end(), [](auto &left, auto &right) { // second 순으로 정렬
        if(left.second == right.second){
            return left.first < right.first;
        }
        return left.second < right.second;
    });
//    for(int i = 0;i< n; i++){
//        cout << v.at(i).first << " " << v.at(i).second << endl;
//    }
    
    int before_meet = 0;
    for(int i = 1; i < (int)v.size(); i++){
        if(v.at(i).first >= v.at(before_meet).second){
            cnt++; //put meeting
            before_meet = i;
            //cout << before_meet << endl;
        }
    }
    
    
    return cnt;
}

int main(){
    int n;
    cin >> n;
    vector <pair<int, int>> v;
    int start, finish;
    for(int i = 0; i < n; i++){
        cin >> start >> finish;
        v.push_back(make_pair(start, finish));
    }
    int count = assign_room_min(n, v);
    cout << count << endl;
    return 0;
}
