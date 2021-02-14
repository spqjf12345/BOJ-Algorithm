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
    int cnt;
    vector<pair<int, int> > vv;
    sort(v.begin(), v.end()); // first 원소 기준으로 오름차순을 정렬
    
    vector<pair<int, int> >::iterator  iter;
    
    for(iter = v.begin(); iter != v.end(); ++iter){
          int i = 0;
          //cout << vv.size() << endl;
          for(i = 0; i < vv.size(); i++) // 검사할 갯수 0번째부터 검사 시작
          {
              //cout << i << " " << vv[i].first <<" " << vv[i].second << endl;
              if((*iter).first >= vv[i].first && (*iter).first < vv[i].second){
                  continue;
              }
              else {
                  vv[i].second = (*iter).second;
                  break;
              }

          }
          
          if(i ==  vv.size()){
              //cout << "push " << i << " " << (*iter).first << (*iter).second << endl;
              vv.push_back(*iter);// 처음 넣는 곳
          }
              
      }
    
    cnt = (int)vv.size();
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
