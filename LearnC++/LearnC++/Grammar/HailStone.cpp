#include <iostream>
using namespace::std;
#include "learnC++.hpp"
#include <stdio.h>
/*
 目前"HailStone序列"还未被证明是否有穷，所以它未必是一个算法。 算法必须满足有穷性。
 * HailStone序列
 * n=1时，返回1；
 * n>1时且为偶数时，{n} ∪ {n/2}
 * n>1时且为奇数时，{n} ∪ {3n + 1}
 */

int hailStone(int n){
    int length = 1;
    while ( 1 < n ) { n % 2 ? n = 3*n + 1 : n /= 2; length++; }
    return length;
};

void HailStone(){
    cout << hailStone(9) << endl;
}

