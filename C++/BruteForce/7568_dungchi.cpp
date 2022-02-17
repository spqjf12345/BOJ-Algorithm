//
//  7568_dungchi.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/02/18.
//

#include <iostream>
using namespace std;
int N;
pair<int, int> arr[50];

void ranking(){
    
    for(int i =0; i < N; i++){
        pair<int, int> target = arr[i];
        int rank = 1;
        for(int j = 0; j < N; j++){
            if(target.first < arr[j].first && target.second < arr[j].second){
                rank++;
            }
        }
        cout << rank << ' ';
    }
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        int height, weight;
        cin >> height >> weight;
        arr[i].first = height;
        arr[i].second = weight;
    }
    
    ranking();
    return 0;
}
