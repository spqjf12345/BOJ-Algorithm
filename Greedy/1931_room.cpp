//
//  1931_room.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/02/10.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int assign_meeting_room(int n, vector<pair<int, int>> v){
    int cnt = 1; // 제일 빨리 끝나는 거 일단 넣어 놓기
    
    sort(v.begin(), v.end(), [](auto &left, auto &right) { // second 순으로 정렬
        if(left.second == right.second){
            return left.first < right.first;
        }
        return left.second < right.second;
    });
    
    int before_meet = 0;
    for(int i = 1; i < (int)v.size(); i++){
        if(v.at(i).first >= v.at(before_meet).second){
            cnt++; //put meeting
            before_meet = i;
        }
    }

    
    return cnt;
}


int main(){
    //make input
    int n;
    cin >> n;
    
    vector<pair<int, int>> v;
    int start, finish;
    for(int i =0; i < n; i++){
        cin >> start >> finish;
        v.push_back(make_pair(start, finish));
        //cout << v[i].front().first << v[i].front().second << endl;
    }
    int count = assign_meeting_room(n, v);
    cout << count << endl;
    return 0;
}
