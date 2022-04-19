//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/04/19.
//

import Foundation

var result = 0
for _ in 0..<5 {
    var num = Int(readLine()!)!
    if num <= 40 {
        result += 40
    }else {
        result += num
    }
}
print(result / 5)
