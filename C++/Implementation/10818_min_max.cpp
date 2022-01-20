//
//  10818_min_max.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/02/12.
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, max, min;
    max = -1000000;
    min = 1000000;
    cin >> n;
    int v[n];
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    max = v[0];
    min = v[1];
    for(int i = 0; i < n; i++){
        if(v[i] > max){
            max = v[i];
        }
        if(v[i] < min){
            min = v[i];
        }
    }
        
    cout << min << " " << max << endl;
    
    return 0;
}
