//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/02/22.
//

import Foundation

var n = Int(readLine()!)!

//1
var first = Int(Double(n) * 0.78)

//2
var second = Int((Double(n) * 0.2) * 0.78 + (Double(n) * 0.8))

print(first, second, separator: " ")
