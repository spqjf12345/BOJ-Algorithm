//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/03/06.
//

import Foundation
var n: Int = Int(readLine()!)! // height

print("\(pow(2, n) - 1)")

func htower(n: Int, from: Int, by: Int, to: Int) { // from -> to
    if(n == 1){
        print("\(from) \(to)")
    }else{
        htower(n: n-1, from: from, by: to, to: by)
        print("\(from) \(to)")
        htower(n: n-1, from: by, by: from, to: to)
    }
    
}

htower(n: n, from: 1, by: 2, to: 3)
