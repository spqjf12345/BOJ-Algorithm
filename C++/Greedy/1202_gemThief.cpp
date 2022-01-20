//
//  1202_gemThief.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/05/02.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>


using namespace std;
int n, k;

vector<pair<int, int>> bag;

multiset<long long> s;

long long make_greedy(){
    long long answer = 0;

    sort(bag.begin(), bag.end(), [](auto &left, auto &right) { // second 순으로 정렬
            if(left.second == right.second){
                return left.first < right.first;
            }
            return left.second > right.second;
        });
    
//    for(int i =0; i < bag.size(); i++){
//        cout << " bag : " << bag.at(i).first << " " << bag.at(i).second << '\n';
//    }
    
    for(int i = 0; i < bag.size(); i++){ //4
        int nowBagWeight = bag.at(i).first;
        int nowBagValue = bag.at(i).second;
        multiset<long long>:: iterator iter = s.lower_bound(nowBagWeight);
        if(iter == s.end()) continue;
        s.erase(iter);
        answer += nowBagValue;
    }
    
    return answer;
}

int main(){
    cin >> n >> k;
    for(int i =0; i < n ;i++){
        int weight, value;
        cin >> weight >> value;
        bag.push_back({weight, value});
    }
    
    for(int i =0; i < k; i++){
        long long bag;
        cin >> bag;
        s.insert(bag);
    }
    
    cout << make_greedy() << '\n';

    return 0;
}
