//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/04/20.
//

import Foundation

var s: [String] = readLine()!.map { String($0) }
var total = 0
var dic: [String: Int] = [:]

func backTracking(_ lastText: String, _ cnt: Int) {
    if cnt == s.count {
        total += 1
        return
    }
    
    for i in 0..<sortDic.count {
        //중복 시
        if sortDic[i].value < 1 || lastText == sortDic[i].key { continue }
        sortDic[i].value -= 1
        backTracking(sortDic[i].key, cnt + 1)
        sortDic[i].value += 1
    }
}

for i in s {
    dic[i, default: 0] += 1
}

var sortDic = dic.sorted(by: { $0.key < $1.key })
//print(sortDic)
backTracking("", 0)
print(total)
