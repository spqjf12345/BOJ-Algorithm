//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/04/16.
//

import Foundation
var n = Int(readLine()!)!
var arr = Array(repeating: 0, count: n)
var m = Int(readLine()!)!
for _ in 0..<m {
    let vip = Int(readLine()!)!
    arr[vip-1] = 1
}
var result = 1
for i in arr.split(separator: 1) {
    var d = Array(repeating: 0, count: i.count)
    if i.count == 1 || i.count == 2 {
        result *= i.count
    }else {
        d[0] = 1 // 1명
        d[1] = 2 // 2명
        for num in 2..<i.count {
            d[num] = d[num-1] + d[num-2]
        }
        result *= d[i.count - 1]
    }
}

print(result)

