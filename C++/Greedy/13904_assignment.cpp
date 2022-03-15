//
//  13904_assignment.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/03/15.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, maxDay, sum = 0;

vector<int> v[1001];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int day, value;
        cin >> day >> value;
        v[day].push_back(value);
        if(day > maxDay){
            maxDay = day;
        }
    }
    
    for(int i = 0; i < n; i++){
        sort(v[i].begin(), v[i].end());
    }
    
    for(int i = maxDay; i >= 1; i--){
        int maxValue = 0;
        int maxValueIndex = 0;
        for(int j = i; j <= maxDay; j++){
            if(v[j].size() != 0){
                if(v[j][v[j].size()-1] > maxValue) {
                    maxValue = v[j][v[j].size()-1];
                    maxValueIndex = j;
                }
            }
        }
        if(maxValue != 0){
            sum += maxValue;
            v[maxValueIndex].erase(v[maxValueIndex].begin() + v[maxValueIndex].size() - 1);
        }
    }
    
    cout << sum << '\n';
    return 0;
}
