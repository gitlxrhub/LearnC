#include <iostream>
#include "learnC++.hpp"
using namespace::std;
/*
 1.指针
    指针是一个地址，它长得像 0x8FFF 这个样子。地址呢，就是某个内存位置的一个编号。那这个位置的内存是可以存放一些数据的。这些数据就叫做“指针所指的数据”或者“指针指向的数据”
 2. 常量和指针
    我们把指针放到一个变量里面，就是指针变量；
    我们把指针放到常量中，就是指针常量；
    那如果一个指针（也就是地址，比如0x8FFF）所指的数据（也就是0x8FFF这个内存位置存放的数据）是常量，这个指针被称为常量指针。
    所以，有一种东西，叫做“常量指针常量”。就是说，一个常量中存着一个指针，这个指针又指向另外一个常量。
 3.指针传递和引用传递
   ①指针传递：指针传递参数本质上是值传递的方式，它所传递的是一个地址值。值传递过程中，被调函数的形式参数作为被调函数的局部变量处理，即在栈中开辟了内存空间以存放由主调函数放进来的实参的值，从而成为了实参的一个副本。值传递的特点是被调函数对形式参数的任何操作都是作为局部变量进行，不会影响主调函数的实参变量的值。
   ②引用传递：引用传递过程中，被调函数的形式参数也作为局部变量在栈中开辟了内存空间，但是这时存放的是由主调函数放进来的实参变量的地址。被调函数对形参的任何操作都被处理成间接寻址，即通过栈中存放的地址访问主调函数中的实参变量。正因为如此，被调函数对形参做的任何操作都影响了主调函数中的实参变量。
 3.总结
    *（指针）和 const（常量） 谁在前先读谁 ；* 代表被指的数据，名字代表指针地址， &x表示取x的地址名，*x表示取出地址名x指定的值
 */



// 常量指针/常指针
// 特征：指针所指向的内容不可以通过指针的间接引用(*p)来改变。
void opinter1(){
    const int x = 1;
    const int x1 = 2;
    const int* p1= &x; //这里可以不用先定义
    p1 = &x1;      //指针 p1的类型是  (const int*)
//    *p1 = 10;     // Error! 因为声明中 const int* const在前面
    
    char* s1 = "Hello";     // Error!
    const char* s2 = "Hello";     // Correct!
    std::cout << s2 << std::endl; // Output: Hello 数组名就是数组首地址的别名，数组名就是一个指针常量 此时数组名就相当于是指针
    std::cout << *s2 << std::endl; // Output: H
    std::cout << &s2 << std::endl; // Output: 0x7ffeefbff3b0
}

// 指针常量
// “指针常量”的含义是：指针本身的内容是个常量，不可以改变
void opinter2(){
    int x = 1, y = 1;
    int* const p2 = &x; //常量 p2的类型是  (int*) 所以必须初始化赋值
    *p2 = 10;     // Okay!  → x=10
//    p2 = &y;      // Error! p2 is a constant 不可以改变其值
    std::cout << *p2 << std::endl; // Output:  10
    std::cout << p2 << std::endl; // Output:  0x7ffeefbff3cc
    
}

void opinter3(){
    char a[3]{'a','b','c'}, b[3]{'d','e','f'};
    char const* p = a;
    p = b;
//    p = b + 1;
    std::cout << p << std::endl; // Output:  defabc
//    opinter1();
//    opinter2();
    
    
    int X[] = {1,2,3,4,5};
    for (auto x: X) {
        cout << x <<endl;
    }
}


void opinter4(){
    char a[3] {'a'}, b[3] {'A'};
    char* const p = a;
    char* p1 = a;
    cout <<(*p+2) << endl; // Output 100
    cout <<(*p)+1 << endl; // Output 99
    
    p[1] = 'A';
    cout << p << endl; // aA
    
    
    cout << p1 << endl;
    cout << *p1 << endl;
    cout << *p1+1 << endl;
}

void opinter5(){
    int y {0}, &x {y};
    cout << x << endl; // 0
    cout << &x << endl; // 0x7ffeefbff3dc
    cout << &y << endl; // 0x7ffeefbff3dc
    // x存放的是y的地址的说法是错误的，正确的是，x是指针变量，这里存放的是y的值，指针变量不一定非要存放地址。
}



void testPointer(){


}


