//
//  2805_cutWood.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/02/22.
//

#include <iostream>
#include <algorithm>

using namespace std;
long long N, need, result;
int wood[1000001];

int mid = 0;
int main(){
    cin >> N >> need;
    for(auto i = 0; i < N; i++){
        cin >> wood[i];
    }
    
    sort(wood, wood+N);
    
    int start = 0; int end = wood[N-1];
    while(start <= end){
        mid = (start + end) / 2;
        long long tempsum = 0;
        //cout << mid << '\n';
        for(auto i = 0; i < N; i++){
            if(wood[i] - mid > 0){
                tempsum += wood[i] - mid;
                //wood[i] -= mid;
            }
        }
        
        if(tempsum < need){
            end = mid -1 ;
        }else if(tempsum >= need) {
            start = mid + 1;
            result = mid;
        }
    }
    
    cout << result << '\n';
    
    
    return 0;
}
