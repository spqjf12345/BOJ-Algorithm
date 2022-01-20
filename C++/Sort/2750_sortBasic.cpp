//
//  2750_sortBasic.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/02/22.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v;

int main(){
    int n;
    cin >> n;
    for(int i =0; i< n; i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    for(int i =0; i< (int)v.size(); i++){
        cout << v.at(i) << endl;
    }
    return 0;
}
