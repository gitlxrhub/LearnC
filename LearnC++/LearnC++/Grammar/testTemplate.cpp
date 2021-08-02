#include <iostream>
#include "learnC++.hpp"
using namespace std::string_literals;
/*
 函数模板
 C++引入了带有泛型的函数模板
 */

template <typename T,typename Q>
auto add(T x, Q y){
    return (x+y);
}


/*
 函数模版实例化
    1.实例化
      函数模板只是蓝图，本身不是不是类型、函数,编译器扫描代码，遇到模版定义时，并不立即产生代码,
      确定模板实参后，编译器生成实际函数代码。
    2.两种实例化方法
      显式实例化
      隐式实例化
 */

template <typename R>
void foo(R x){
    std::cout << "显示实例化foo()" << x << std::endl;
}

template <typename TT>
TT mMax(TT x, TT y){
    return ( x > y ? x : y );
}
// 显示实例化：整数
template int mMax<int>(int,int);

template void foo<>(char);
template void foo(long);
template void foo(double);
template void foo(int);

void testTemplate(){
    
    long int a = 222;
    
    foo('a');
    foo(a);
    foo(1.2);
    foo(1);
    
    
    
    std::cout << add(2,3.3) << std::endl;
    // 调用显示实例化函数
    std::cout << mMax(1,2) << std::endl;
    // 浮点实例化 （隐式实例化） mMax<double>(double)
    std::cout << mMax(1.2, 2.1) << std::endl;
    // 字符串字面量实例化
    std::cout << mMax("abd", "abc") << std::endl; // 其实是比较的字符串的地址
    std::cout << mMax("abc", "abd") << std::endl;
    // std::string类型实例化
    std::cout << mMax("abd"s, "abc"s) << std::endl; // 真正的字符串内容比较
    std::cout << mMax("abc"s, "abd"s) << std::endl;

}
