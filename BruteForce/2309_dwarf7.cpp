//
//  2309_dwarf7.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/04/06.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

///9난쟁이 중 진짜 난쟁이 찾기
using namespace std;
vector<int>arr;
vector<int>re_arr;

int visit[100];
int cnt = 0;

void brute_dwarf7(int score, int cnt){
    if (score == 100 and cnt == 7){
        sort(re_arr.begin(), re_arr.end());
        
        for(int i = 0; i < 7; i++){
            cout << re_arr.at(i) << "\n";
        }
        exit(0);//system call 탈출
    }
    
    if (cnt > 7 || score > 100){
        return;
    }
    
    for(int i= 0; i <9; i++){
        if(visit[arr[i]] == false){
            visit[arr[i]] = true;
            re_arr.push_back(arr[i]);
            brute_dwarf7(score + arr[i], cnt + 1);
            visit[arr[i]] = false;
            re_arr.pop_back();
        }
    }
    return;

}

int main(){
    memset(visit, false, sizeof(visit));
    for(int i =0; i < 9; i++){
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    brute_dwarf7(0, 0);
    
    return 0;
}
