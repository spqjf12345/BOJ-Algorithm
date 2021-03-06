//
//  1707_bgd.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/02/25.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

enum color { RED, BLUE };
// 이분 그래프인지 아닌지 판별하는 문제

//vector<int> RED_GROUP;
//vector<int> BLUE_GROUP;
string res = "";
int visit[20001];
vector<int> map[20001];
int cnt = 0;
int v, e;

string dfs(int vertex, int color){
    visit[vertex] = color;
    
//    if(color == RED){
//        RED_GROUP.push_back(vertex);
//    }else if(color == BLUE){
//        BLUE_GROUP.push_back(vertex);
//    }
    cnt++;
    //cout << "m : " << map[vertex].size() << " " << endl;
    
    if(cnt == v) return res;
    
    for(int i = 0; i < (int)map[vertex].size(); i++){
        //cout << map[vertex][i]  << " " << endl;
        if(visit[map[vertex][i]] == -1){
            //cout << "here ? " << endl;
            dfs(map[vertex][i], (color + 1) % 2);
        }
        if(visit[map[vertex][i]] == color){
            //cout << "or here" << endl;
            res = "NO";
            //cout << res << endl; // vertex 다 돌면 종료
            return res;
        }
    }
    return res;
    
}

int main(){
    int t;
    cin >> t;
    
    while(t--){
        res = "YES";
        cin >> v >> e; // vertex, edge
        //clear for necxt test case
        for(int i = 0; i < 20001; i++){
            map[i].clear();
            visit[i] = -1;
        }
        //cout <<"init " << visit[2] << endl;
        
        //memset(visit, -1, sizeof(visit));
        
        for(int i = 0; i < e; i++){
            int v1, v2;
            cin >> v1 >> v2;
            map[v1].push_back(v2);
            map[v2].push_back(v1);
        }
        string ans = "";
        for(int j = 1; j <= v; j++){
            if(visit[j] == -1){ // 방문 하지 x으므로
                ans = dfs(j, RED);
            }
        }
        cout << ans << endl;
    }
    
    
    
//
//    if (!res.compare("YES")) {
//       cout << "RED GROUP : ";
//       for (int i = 0; i < (int)RED_GROUP.size(); i++) {
//           cout << RED_GROUP[i] << " ";
//       }
//       cout << "\nBLUE GROUP : ";
//       for (int i = 0; i < (int)BLUE_GROUP.size(); i++) {
//           cout << BLUE_GROUP[i] << " ";
//       }
//       cout << endl;
//    }
    
    return 0;
}
