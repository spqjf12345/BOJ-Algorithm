//
//  15686_chicken_delivery.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/02/18.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
#define INF 987654321

struct Chicken {
    int x; int y; bool close;
};

int N, M, ans = INF;
int arr[51][51];
vector<pair<int, int>> person;
vector<Chicken> chicken;

int distance(pair<int, int> per, Chicken chick) {
    //cout << abs(per.first - chick.x) + abs(per.second - chick.y) << '\n';
    return abs(per.first - chick.x) + abs(per.second - chick.y);
    
}
void choose_chicken(int startIndex, int cnt){
    if(cnt == M){ // M개 뽑았을 경우
        int sum = 0;
        
        for(int i = 0; i < person.size(); i++){
            int dist = INF;
            for(int j = 0; j < chicken.size(); j++){
                if(!chicken[j].close){ // 폐점되지 않은 치킨집이라면
                    dist = min(dist, distance(person[i], chicken[j]));
                   // cout << "dist " << dist << '\n';
                }
            }
            sum += dist;
        }
        
        ans = min(ans, sum);
        return;
    }

    
    //backTracking
    for(int i = startIndex; i < chicken.size(); i++){
        if(chicken[i].close == true){
            chicken[i].close = false;
            choose_chicken(i, cnt+1);
            chicken[i].close = true;
        }
    }
    
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 1) {
                person.push_back({i, j});
            }else if(arr[i][j] == 2){
                chicken.push_back({i, j, true});
            }
        }
    }
    
    choose_chicken(0, 0);
    cout << ans << '\n';
    return 0;
}
