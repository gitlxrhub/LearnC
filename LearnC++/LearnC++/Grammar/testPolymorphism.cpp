using namespace::std;
#include <iostream>
#include "learnC++.hpp"
#include <string>

/*
 多态
 
 基类与派生类中有同名函数
  (1)通过派生类对象访问同名函数，是静态联编
  (2)通过基类对象的指针访问同名函数，是静态联编
  (3)通过基类对象的指针或引用访问同名虚函数，是动态联编
 */

class A{
public:
    // 虚函数的传递性
    virtual std::string toSting(){
        return  "A";
    }
};
    
class B:public A{
public:
     std::string toSting() override{ // override显式声明覆写：制定一个虚函数复写另外一个虚函数，指定这个方法是重写方法，这样就可以检测语法错误，比如函数名写错了
        return  "B";
    }
};

class C:public A{
public:
    std::string toSting(){
        return  "C";
    }
};

void print(A o){
    cout << o.toSting() <<endl;
}

void print(B o){
    cout << o.toSting() <<endl;
}

void print(C o){
    cout << o.toSting() <<endl;
}

void print_(A* o){
    cout << o->toSting() <<endl;
}

void print_(A& o){
    cout << o.toSting() <<endl;
}

void testPolymorphism(){
    A a;
    B b;
    C c;
    print(a);
    print(b);
    print(c);
    
    A* p1 =&a;
    A* p2 =&b;
    A* p3 =&c;
    print_(p1); //Output A
    print_(p2); //Output B
    print_(p3); //Output C
    
    print_(a);
    print_(b);
    print_(c);
}

/*
  override显式声明覆写
   C++11引入override标识符，指定一个虚函数覆写另一个虚函数。
   override的价值在于：避免程序员在覆写时错命名或无虚函数导致隐藏bug
 */
class E {
public:
  virtual void foo() {}
  void bar() {}
};
class D : public E {
public:
//  void foo() const override { // 错误： D::foo 不覆写 E::foo
//  }                           // （签名不匹配）
  void foo() override;   // OK ： D::foo 覆写 E::foo
//  void bar() override {} // 错误： E::bar 非虚
};
 
//void D::foo() override {// 错误： override只能放到类内使用
//}


/*
  final 显式声明禁止覆写
     C++11引入final特殊标识符，指定派生类不能覆写虚函数
     struct可与class互换；差别在于struct的默认访问属性是public
 */

struct Base {
    virtual void foo();
};

struct Q : Base
{
    void foo() final; // A::foo 被覆写且是最终覆写
//    void bar() final; // 错误：非虚函数不能被覆写或是 final
};

struct P final : Q // struct P 为 final，不能被继承
{
//    void foo() override; // 错误： foo 不能被覆写，因为它在 Q 中是 final
};
