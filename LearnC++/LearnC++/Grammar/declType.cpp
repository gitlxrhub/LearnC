#include <iostream>
#include "learnC++.hpp"

/*
  Automatic Type Deduction: decltype（自动类型推导：decltype关键字）
  1.关键字decltype的用法
    decltype利用已知类型声明新变量。
    有了auto，为什么还要整出一个decltype？原因是，我们有时候想要从表达式的类型推断出要定义的变量类型，但不想用该表达式的值初始化变量。
    decltype是在编译期推导一个表达式的类型，它只做静态分析，因此它不会导致已知类型表达式执行。
    decltype 主要用于泛型编程（模板）
  2.decltype与auto的对比
    decltype和auto都是C++11自动类型推导的关键字。它们
 有很多差别：
    auto忽略最上层的const，decltype则保留最上层的const
    auto忽略原有类型的引用，decltype则保留原有类型的引用
    对解引用操作，auto推断出原有类型，decltype推断出引用；
  3.auto推断时会实际执行，decltype不会执行，只做分析。总之在使用中过程中和const、引用和指针结合时需要特别小心。
 */

int fun1(){ return 10;}
auto fun2(){ return  'gg';}
void testDeclType(){
    decltype(fun1()) x;
    decltype(fun2()) y = fun2();
    
    std::cout << typeid(x).name() << std::endl;
    std::cout << x << std::endl;
    std::cout << typeid(y).name() << std::endl;
    std::cout << y << std::endl;
}
