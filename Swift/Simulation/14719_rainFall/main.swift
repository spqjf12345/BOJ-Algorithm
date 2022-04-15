//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/04/14.
//

import Foundation
var line = readLine()!.split(separator: " ").map { Int(String($0))! }
var H = line[0]
var M = line[1]

var arr = readLine()!.split(separator: " ").map{ Int(String($0))! }
var maxHeight = arr.max()!
var isWall: [[Bool]] = Array(repeating: Array(repeating: false, count: M), count: H)

var cntArr = arr
for i in 0..<M {
    for j in stride(from: H-1, to: -1, by: -1) {
        if arr[i] > 0 {
            arr[i] -= 1
            isWall[j][i] = true
        }
    }
}

func findRain() -> Int {
    var rainCnt = 0
    
    for i in stride(from: isWall.count - 1, to: -1, by: -1) { // 0층 부터 검사
        let falseCnt = isWall[i].filter{ $0 == false }.count
        if falseCnt > 0 { // 빗물 생길 수 있다면
            print("i \(i) floor")
            var first: Int = -1
            var end: Int = -1
            var falseArr = [Int]()
            for j in 0..<isWall[i].count {
                if isWall[i][j] == true && first == -1 {
                    first = j
                    print("j is \(j)")
                }
                else if isWall[i][j] == false { falseArr.append(j) }
                else if isWall[i][j] == true && first != -1 && !falseArr.isEmpty {
                    end = j // end는 가장 나중 값으로 누적 될 것
                }
            }
            print("\(first) \(end)")
            if first == -1 || end == -1 { break }
            var canCnt = 0
            for i in falseArr {
                if i >= first && i <= end {
                    canCnt += 1
                }
            }
            rainCnt += canCnt
//            let canCnt = falseArr.filter{ $0 >= first && $0 <= end }.count
//            if canCnt == falseCnt {
//                print("canCnt \(canCnt)")
//                rainCnt += canCnt
//            }
            
        }
        
    }

    return rainCnt

}
print(findRain())
