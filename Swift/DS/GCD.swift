//
//  GCD.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/02/19.
//

import Foundation

func gcdIterativeEuklid(_ m: Int, _ n: Int) -> Int {
    var a: Int = 0
    var b: Int = max(m, n)
    var r: Int = min(m, n)

    while r != 0 {
        a = b
        b = r
        r = a % b
    }
    return b
}

//with recursion
func gcdRecursiveEuklid(_ m: Int, _ n: Int) -> Int {
    let r: Int = m % n
    if r != 0 {
        return gcdRecursiveEuklid(n, r)
    } else {
        return n
    }
}

//gcd(3819, 1710) = gcd(1710, 3819 % 1710) =
//gcd(1710, 399)  = gcd(399, 1710 % 399)   =
//gcd(399, 114)   = gcd(114, 399 % 114)    =
//gcd(114, 57)    = gcd(57, 114 % 57)      =
//gcd(57, 0)
