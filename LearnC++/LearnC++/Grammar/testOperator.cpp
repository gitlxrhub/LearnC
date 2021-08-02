#include <iostream>
using namespace::std;
#include "learnC++.hpp"

/*
    1.类型转换：operator <类型>()
    2.运算符重载：<类型> operator <运算符>(<参数表>)
 */

/*
 类型转换
 
 转换函数必须是类方法
 转换函数不能指定返回类型
 转换函数不能有参数
 */
class Complex{
public:
    operator double(){
        cout << "类型转换" << endl;
        return 1;
    }
};


// 运算符重载
class MyClass
{
public:
   MyClass() {}
   MyClass(int a, double b):a_(a),b_(b){}
   ~MyClass(){}

   int get_a() { return a_; }
   double get_b() { return b_; }

   MyClass operator+(const MyClass &adder) const//以成员函数方式重载+
   {
     cout << "operator+ " << "a_: " << a_ << " adder.a_: " << adder.a_ << endl;
     cout << "operator+ " << "b_: " << b_ << " adder.b_: " << adder.b_ << endl;
       MyClass sum;
       sum.a_ = a_ + adder.a_;
       sum.b_ = b_ + adder.b_;
       return sum;
   }
   friend MyClass operator-(const MyClass &A,const MyClass &B)//以友元方式重载-
   {
     cout << "operator- " << " A.a_: " << A.a_ << " B.a_: " << B.a_ << endl;
     cout << "operator- " << " B.b_: " << A.b_ << " B.b_: " << B.b_ << endl;
       MyClass diff;
       diff.a_ = A.a_ - B.a_;
       diff.b_ = A.b_ - B.b_;
       return diff;
   }

private:
    int a_;
    double b_;
};

void testOperator(){
    MyClass A(1, 1.1);
    MyClass B(2, 2.2);
    MyClass sum = A + B;
    MyClass diff = A - B;
    cout << "sum:" << sum.get_a() << "\t" << sum.get_b() << endl;
    cout << "diff:" << diff.get_a() << "\t" << diff.get_b() << endl;
    
    
    Complex a;
    double b = a;
    
    cout << "a:" << a << endl;
    cout << "b:" << b << endl;
}
