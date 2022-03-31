//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/03/31.
//

import Foundation
var n = Int(readLine()!)!
var m = Int(readLine()!)!
//var A = Array(repeating: Array(repeating: 0, count: n+1), count: n+1)
//var B = Array(repeating: 0, count: n*n + 1)
//
//for i in 1..<n+1{
//    for j in 1..<n+1 {
//       A[i][j] = i * j
//    }
//}

func binearySearch(_ left: Int, _ right: Int) -> Int {
    if(left > right) { return left }
    var mid = (left + right) / 2
    var cnt = 0
    
    for i in 1..<n+1 {
        if(n > mid / i) { // mid 보다 작은 수 더해줌
            cnt += mid / i
        }else {
            cnt += n
        }
    }
    if(cnt < m) {
        return binearySearch(mid+1, right)
    }else {
        return binearySearch(left, mid - 1)
    }
}

print(binearySearch(1, m))


