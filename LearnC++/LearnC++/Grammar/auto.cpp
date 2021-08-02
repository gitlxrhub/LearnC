#include <iostream>
#include "learnC++.hpp"

auto max(int x,int y){
    return x > y ? x : y;
}

void testAuto(){
    //1.auto 变量必须在定义的时候初始化
    auto a = 3;
//    auto x; // error
//    x = 3;
    
    //2.定义一个auto序列的变量必须始终推导成同一类型
//    auto x{1},y{2},z{'q'}; //error
    
    //3.如果初始化表达式是引用或者const，则去除引用或const语意
    int y1{22},&y2{y1};
    auto y3{y2};
    y1 = 33;
//    std::cout << y3 << std::endl;
    
    //4.如果auto关键字带上&号，则不去除引用或const语意
    auto& y4{y2};
    y1 = 44;
//    std::cout << y4 << std::endl;
    
    //5.初始化表达式为数组时，auto关键字推导类型为指针
    int p[3]{1,2,3};
    auto p1 = p;
    std::cout << p1[1] << std::endl;
    std::cout << typeid(p1).name() << std::endl;
    
    //6.若表达式为数组切auto带上&，则推导类型为数组类型
    auto& p2 = p;
    std::cout << p2[1] << std::endl;
    std::cout << typeid(p2).name() << std::endl;
    
    //7.c++14中，auto可以作为函数的返回值类型和参数类型
    auto aa{55},bb{66};
    std::cout << max(aa,bb) << std::endl;

}
