
#include <stdio.h>
#include <iostream>
//#include <queue>
#include <string.h>


using namespace std;
int arr[501][501];
int n, m;
int dp[501][501];

int dx[] = { 0, 0, 1, -1 }; //up down left right
int dy[] = { 1, -1, 0, 0 };
bool visit[501][501];
int cnt = 0;

int find_route(int i, int j){
    
    if(i == n -1 && j == m -1) return 1;
   
    for(int s = 0; s < 4; s++){
        int nx = i + dx[s];
        int ny = j + dy[s];
        if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if(arr[nx][ny] >= arr[i][j]) continue;
        dp[nx][ny] += find_route(nx, ny);
    }
    
    return dp[n-1][m-1];
    
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j= 0; j < m; j++){
            cin >> arr[i][j];
            dp[i][j] = -1;
        }
    }

    cout << find_route(0, 0) + 1 << '\n';
//    
//    for(int i = 0; i < n; i++){
//        for(int j= 0; j < m; j++){
//            cout << dp[i][j] << " ";
//        }
//        cout << '\n';
//    }
    return 0;
}
