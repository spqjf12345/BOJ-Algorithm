//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/03/07.
//

import Foundation

var n = Int(readLine()!)!
var d = Array(repeating: Array(repeating: 0, count: n+1), count: n+1)// 길이가 n이고 마지막 수가 j인 이친수 배열

d[0][0] = 0
d[0][1] = 0


for i in stride(from: 1, to: n+1, by: 1){
    for j in stride(from: 0, to: 2, by: 1){
        if(i == 1){
            d[1][0] = 0
            d[1][1] = 1
        }else {
            if(j == 0){
                d[i][j] = d[i-1][0] + d[i-1][1]
            }else if(j == 1){
                d[i][j] = d[i-1][0]
            }
        }
      
    }
}

print(d[n][0] + d[n][1])


