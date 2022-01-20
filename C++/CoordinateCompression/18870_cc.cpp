//
//  18870_cc.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/02/18.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int main(){
    
    int N;
    cin >> N;
    vector<int> index(N);
    vector<int> points(N);
    
    for(int i = 0; i < N; i ++){
        cin >> index.at(i);
        points.at(i) = index.at(i);
    }
    sort(index.begin(), index.end()); -10 -9 2 4
    index.erase(unique(index.begin(), index.end()), index.end());
    
    for(auto& c : points){ 0 1 2
        cout << lower_bound(index.begin(), index.end(), c) - index.begin() << " ";
    }
    cout << endl;
    
    return 0;
}
