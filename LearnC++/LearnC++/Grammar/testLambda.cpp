using namespace::std;
#include <iostream>
#include "learnC++.hpp"
#include <stdio.h>

/*
 [ 捕获列表 ] ( 形参数列表 ) mutable(可选) 异常属性 -> 返回值类型 { 函数体 }
 在‘[]’里面可以填入‘=’或‘&’表示该lambda表达式“捕获”
 ‘&’表示一引用的方式；‘=’表明以值传递的方式捕获

 
  https://blog.csdn.net/lxr_17/article/details/118055263
 */

void lambda1(){
    int x = 10;
    int y = 3;
    int z ;
    int u;
    int w;
    
    w = [=](int i,int j)mutable throw() -> int { return i + j;}(1,3);
    cout<<w<<endl;

    z = [=]()mutable throw() -> int { int n = x + y; x = y ; y = n; return n;}();
    cout<<z<<endl;
    cout<<"x:"<<x<<"\t"<<"y:"<<y<<endl;
    
    u = [&]()mutable throw() -> int { int n = x + y; x = y ; y = n; return n;}();
    cout<<u<<endl;
    cout<<"x:"<<x<<"\t"<<"y:"<<y<<endl;
}

int intShape(int a){
    cout<< "test" <<endl;
    return  a;
}

class Shape{
public:
    string name = "i am shape";
    
    // 匿名函数作为参数传递
    void _shape(function<int(int)> callBack){
        cout<< "_shape "<< this->name <<endl;
        callBack(1);
    }
    
    function<int(int)>func = intShape;

    void mshape(int a){
        int b = 1;
        auto fun = [](int b) -> int{
            cout<< "this->name" << b <<endl;
            return  b;
        };
        this->_shape(fun);
//        this->_shape(this->func);
    }
};

void testLambda(){
//    lambda1();
    Shape shape;
    shape.mshape(1);
    


}
