//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/03/16.
//

import Foundation
//https://danidani-de.tistory.com/5

var line = readLine()!.split(separator: " ").map{ Int($0)! }
var n = line[0] // 3
var num = line[1] // 10
var d: [Int] = Array(repeating: 0, count: num+1)
var arr: [Int] = Array(repeating: 0, count: n)

for i in 0..<n {
    arr[i] = Int(readLine()!)!
}

d[0] = 1

for i in arr {
    for j in 1..<num+1 {
        if i <= j {
            d[j] += d[j-i]
            if d[j] > Int(pow(2.0, 31.0)){ d[j] = 0 }
        }
    }
}

print(d[num])

