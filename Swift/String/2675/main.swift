//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/02/16.
//

import Foundation

var num = Int(readLine()!.split(separator: " ")[0])!

func rePlayString() {
    for _ in 0..<num {
       let line1 = readLine()!.split(separator: " ")
        let cnt = Int(line1[0])!
        let str = line1[1]
        var reStr = ""
        for s in str {
            reStr += String(repeating: s, count: cnt)
        }
        print(reStr)
    }
}

rePlayString()


