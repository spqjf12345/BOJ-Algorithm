//
//  3085_candyGame.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/09/02.
//

#include <stdio.h>
#include <iostream>
#include <stack>
#include <algorithm>

//candy = c, p, z, y
int dx[4] = { -1, 0, 1, 0};
int dy[4] = { 0, 0, 1, -1};

using namespace std;
int n;
char arr[51][51];
//char copy_arr[51][51];
//int direct = 3;
int max_count = 0;

//int dfs(int i, int j){
//    int cnt = 0;
//    int visit[51][51] = { false, };
//    stack<pair<int, int>> s;
//    s.push({i, j});
//    while(!s.empty()){
//
//        int x = s.top().first;
//        int y = s.top().second;
//        char c = copy_arr[x][y];
//        s.pop();
//        visit[x][y] = true;
//        for(int i =0; i < 4; i++){
//            int nx = i + dx[i];
//            int ny = i + dy[i];
//
//            if(nx >= n || nx < 0 || ny >= n || ny <0) { continue;}
//            if(c == copy_arr[nx][ny] && visit[nx][ny] == false){
//                visit[nx][ny] = true;
//                cnt++;
//            }
//        }
//    }
//    return cnt;
//}

void check(){
    //양 옆에서 최대값 있는지 check
    for(int i = 0; i < n; i++){
        int count = 1;
        char target = arr[i][0];
        for(int j = 1; j < n; j++){
            if(arr[i][j] == target){
                count++;
            }else {
                count = 1; // 1로 다시 세기
            }
            target = arr[i][j]; // 그 전 값으로 타겟
            if(count > max_count) { max_count = count;}
        }
    }
    
    //앞 뒤에서 최대값 있는지 check
    for(int i = 0; i < n; i++){
        int count = 1;
        char target = arr[0][i];
        for(int j = 1; j < n; j++){
            if(arr[j][i] == target){
                count++;
            }else {
                count = 1; // 1로 다시 세기
            }
            target = arr[j][i]; // 그 전 값으로 타겟
            if(count > max_count) { max_count = count;}
        }
    }
}


void candy_change(){
    for(int i = 0; i < n; i++){ // 양 옆 바꾸기
        for(int j = 0; j < n; j++){
            //target candy - arr[i][j];
            if(arr[i][j] == arr[i][j+1]){
                continue;
            }else {
                swap(arr[i][j], arr[i][j+1]);
                check();
                swap(arr[i][j], arr[i][j+1]);
            }
        }
    }
    
    for(int i = 0; i < n; i++){ // 앞 뒤 바꾸기
        for(int j = 0; j < n; j++){
            //target candy - arr[i][j];
            if(arr[i][j] == arr[i + 1][j]){
                continue;
            }else {
                swap(arr[i][j], arr[i + 1][j]);
                check();
                swap(arr[i][j], arr[i+1][j]);
            }
           
        }
    }
    cout << max_count << '\n';
    
}



int main(){
    cin >> n;
    for(int i =0; i < n; i++){
        for(int j =0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    candy_change();
    
    return 0;
}
