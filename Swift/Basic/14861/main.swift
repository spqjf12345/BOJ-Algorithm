//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/04/18.
//

import Foundation
var x = Int(readLine()!)!
var y = Int(readLine()!)!
if x > 0 && y > 0 {
    print(1)
}else if x < 0 && y > 0 {
    print(2)
}else if x < 0 && y < 0 {
    print(3)
}else {
    print(4)
}
