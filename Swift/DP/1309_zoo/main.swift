//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/04/16.
//

import Foundation
var n = Int(readLine()!)!
var d: [[Int]] = Array(repeating: Array(repeating: 0, count: 3), count: n+1)
var mod = 9901
func placeLion() -> Int {
    d[1][0] = 1 // n이 1일때 0 - 사자 x
    d[1][1] = 1 // 사자 왼쪽에
    d[1][2] = 1 // 사자 오른쪽에
    for i in 2..<n+1 {
        d[i][0] = (d[i-1][0] + d[i-1][1] + d[i-1][2]) % 9901
        d[i][1] = (d[i-1][0] + d[i-1][2]) % 9901
        d[i][2] = (d[i-1][0] + d[i-1][1]) % 9901
    }
    return (d[n].reduce(0) { $0 + $1 }) % 9901
}
print(placeLion())
