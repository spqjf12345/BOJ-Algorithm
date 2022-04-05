//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/03/31.
//

import Foundation
var minS = "0123456789"
var maxS = "9876543210"
var n = Int(readLine()!)!
var signArr = readLine()!.split(separator: " ")

//func backTracking(){
//
//}
var idx = 0

while(idx < signArr.count){
    if(signArr[idx] == "<"){
        var temp = idx
        while(signArr[temp] != ">"){
            temp += 1
        }
        
        print(maxS[maxS.index(maxS.startIndex, offsetBy: idx+1)...maxS.index(maxS.startIndex, offsetBy: temp+1)])
    }
    idx = idx + 1
}
