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
var roleCakeArr = roleCakeArrTen + roleCakeArrNotTen
//print(roleCakeArr)
func seperate() {
    for i in roleCakeArr {
        if(i < 0){ // 못먹음
            continue
        }else if(i == 10){
            cnt += 1
        }else { // 잘라 먹기
            var piece = i
            while(m > 0 && piece > 10){
                piece -= 10
                cnt += 1
                m -= 1
                if(piece == 10){ // 자를 필요 x
                    cnt += 1
                    break
                }
            }
           
        }
    }
    
}
seperate()
print(cnt)

