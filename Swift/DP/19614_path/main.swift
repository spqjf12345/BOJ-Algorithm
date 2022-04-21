//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/04/21.
//

import Foundation
var line = readLine()!.split(separator: " ").map { Int(String($0))! }
var n = line[0]
var m = line[1]
var need = line[2]
var d = Array(repeating: Array(repeating: 0, count: 16), count: 16)
//var second = false
//var secondD = [[Int]]()
var location = [Int]()
func no() -> Int {
    for i in 1...n {
        for j in 1...m {
            if i == 1 && j == 1 { continue }
            d[i][j] = d[i-1][j] + d[i][j-1]
        }
    }
    return d[n][m]
}

func needs() -> Int {
    var count = 0
    for i in 1...n {
        for j in 1...m {
            count += 1
            if count == need {
                location.append(contentsOf: [i, j])
            }
        }
    }

    d[1][1] = 1
    for i in 1...location[0] {
        for j in 1...location[1] {
            if i == 1 && j == 1 { continue }
            d[i][j] = d[i-1][j] + d[i][j-1]
        }
    }
    let mid = d[location[0]][location[1]]
//    print(d)
//    print("mid \(mid)")
    d = Array(repeating: Array(repeating: 0, count: 16), count: 16)
    d[location[0]][location[1]] = 1
    
    
    for i in location[0]...n {
        for j in location[1]...m {
            if i == location[0] && j == location[1] { continue }
            d[i][j] = d[i-1][j] + d[i][j-1]
        }
    }
    
//    while i <= n {
//        while j <= m {
//            if i > n { return secondD[n][m] }
//            if need == (i-1) * m + j {
//                d[i][j] = d[i-1][j] + d[i][j-1]
//                second = true
//
//                secondD = Array(repeating: Array(repeating: d[i][j], count: m+1), count: n+1)
//                i += 1
//                j += 1
//                continue
//            }else {
//                if second  {
//                    //print( " me \(i) \(j)")
//                    secondD[i][j] = secondD[i-1][j] + secondD[i][j-1]
//                }else {
//                    d[i][j] = d[i-1][j] + d[i][j-1]
//                }
//
//            }
//            j += 1
//        }
//        i += 1
//        j = 2
//    }
//    print(secondD)
    return d[n][m] * mid
}

if need == 0 {
  print(no())
}else {
  print(needs())
}

