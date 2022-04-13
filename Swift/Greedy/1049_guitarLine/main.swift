//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/04/13.
//

import Foundation

var line = readLine()!.split(separator: " ").map { Int(String($0))! }
var n = line[0]
var Tcase = line[1]
var brand = [(Int, Int)]()

for i in 0..<Tcase {
    var line = readLine()!.split(separator: " ").map { Int(String($0))! }
    brand.append((line[0], line[1]))
}

var minPrice = 0
while n != 0 {
    var select = 100000
    for i in brand {
        var choose = 100000
        if n < 6 {
            //choose package or one
            choose = min(i.0, i.1 * n)
        }else {
            choose = min(i.0, i.1 * 6)
        }
        select = min(select, choose)
    }
    minPrice += select // 최소값 업데이트

    if(n < 6) {
        break
    }else {
        n = n - 6
    }
    
}

print(minPrice)
