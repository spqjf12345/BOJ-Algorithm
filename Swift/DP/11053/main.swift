//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/03/10.
//

import Foundation
var n: Int = Int(readLine()!)!
var arr: [Int] = readLine()!.split(separator: " ").map{ Int($0)! }

var dp: [Int] = Array(repeating: 0, count: n)
var maxCount = 1

for i in 0..<n {
    dp[i] = 1
    for j in 0..<i {
        if(arr[i] > arr[j] && dp[j] + 1 > dp[i]){
            //i를 마지막에 추가했을 때 값이 현재보다 커야 하므로
            dp[i] = dp[j] + 1
            maxCount = max(maxCount, dp[i]);
        }
        
    }
}

print(maxCount)

