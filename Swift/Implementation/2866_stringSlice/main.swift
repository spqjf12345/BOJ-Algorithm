//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/03/25.
//

import Foundation
var line = readLine()!.split(separator: " ").map { Int($0)! }
var R = line[0]
var C = line[1]

var map: [[Character]] = []
for _ in 0..<R {
    let line1 = Array(readLine()!)
    map.append(line1)
}

func checkBS(left: Int, right: Int) -> Int {
    var start = left
    var end = right
    while(start <= end) {
        let mid = (start + end) / 2
        var check: [String] = []
        var bool: Bool = false
        
        for i in 0..<C {
            var str = ""
            for j in stride(from: mid, to: end+1, by: 1){
                str += String(map[j][i])
            }
            if(!check.contains(str)) {
                // 동일 문자 x
                check.append(str)
            }else {
                end = mid - 1
                bool = true
                break
            }
        }
        
        if(bool) { // 동일 문자 있다면
            end = mid - 1
        }else { // 없다면
            start = mid + 1
        }
        check = [] // 초기화

    }
    
    return start-1
               
//
//    var charArr: [String] = Array(repeating: "", count: C)
//    for i in stride(from: R-1, to: 0, by: -1){
//        var check: [String] = []
//        for j in 0..<C {
//            //print(map[i][map[i].index(map[i].startIndex, offsetBy: j)])
//
//            charArr[j].append(map[i][map[i].index(map[i].startIndex, offsetBy: j)])
//            if(!check.contains(charArr[j])){
//                check.append(charArr[j])
//            }
//        }
//        if(check.count == C){ // 중복되는게 없을 시
//            return i
//        }
//        check = [] // 초기화
//    }
//    return 0
}

print(checkBS(left: 0, right: R-1))


