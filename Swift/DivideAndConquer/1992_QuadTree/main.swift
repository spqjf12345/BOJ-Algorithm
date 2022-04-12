//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/04/12.
//

import Foundation
var n = Int(readLine()!)!
var quadArr = [[Int]]()

func recursive(_ x: Int, _ y: Int, _ n : Int) -> String {

    if(n == 1) { // 원소 하나값 반환
        return "\(quadArr[x][y])"
    }
    
    var isZero: Bool = true
    var isOne: Bool = true
    
    for i in stride(from: x, to: n + x, by: 1) {
        for j in stride(from: y, to: n + y, by: 1){
            if quadArr[i][j] == 0 {
                isOne = false
            }else if quadArr[i][j] == 1 {
                isZero = false
            }
        }
    }
    
    if isZero == true { // 분할된 영역에서
        return "0"
    }else if isOne == true {
        return "1"
    }else {
        var result = "("
        result += recursive(x, y, n / 2)
        result += recursive(x, y + n / 2 , n / 2)
        result += recursive(x + n / 2, y, n / 2)
        result += recursive(x + n / 2, y + n / 2 , n / 2)
        result += ")"
        return result
    }
}

for _ in 0..<n {
    let line = readLine()!.map { Int(String($0))!}
    quadArr.append(line)
}
print(recursive(0, 0, n))

