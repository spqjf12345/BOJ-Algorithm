//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/03/10.
//

import Foundation

var line = readLine()!.split(separator: " ").map{ Int($0)! }

var n = line[0]
var m = line[1]

var roleCake = readLine()!.split(separator: " ").map{ Int($0)! }
var roleCakeArrTen = [Int]()
var roleCakeArrNotTen = [Int]()
var cnt = 0


for i in roleCake {
    if i % 10 == 0 {
        roleCakeArrTen.append(i)
    }else {
        roleCakeArrNotTen.append(i)
    }
}
roleCakeArrTen.sort()
roleCakeArrNotTen.sort()

func cutCake(_ p: Int) -> Void{
    var piece = p
    if(m <= 0 || piece < 10) {
        return
    }
    piece -= 10
    cnt += 1
    m -= 1
    if(piece > 10) {
        cutCake(piece)
    }else if (piece == 10) {
        cnt += 1
    }
    return
}

for i in roleCakeArrTen {
    if(i == 10) { cnt += 1 }
    else { cutCake(i) }
}

for i in roleCakeArrNotTen {
    cutCake(i)
}

print(cnt)

