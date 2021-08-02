using namespace::std;
#include <iostream>
#include "learnC++.hpp"

/*
 实例成员与静态成员
   1. 静态成员的声明
      在类定义中，关键字 static 声明 不绑定到类实例的成员( 该成员无需创建对象即可访问)
   2.静态数据成员的定义
      (1)声明为“constexpr”类型的静态数据成员必须 在类中声明 并初始化。自C++17 起，可不在类外定义
      (2)声明为“inline”(C++17 起) 或者 “const int”  类型的静态数据成员可以 在类中声明 并初始化；
      (3)其它须在类外 定义并初始化，且不带static关键字
 
 静态数据成员需要单独初始化，而且是在类的外面。
 静态成员函数不能调用非静态数据成员和非静态成员函数。
 静态数据成员只有一份，且不依赖对象数量而存在。
 静态成员函数不能用const修饰符。
 普通成员函数可以调用静态成员函数。
 静态成员函数可以独立访问。 类名::静态成员函数名
 非静态成员必须通过类的对象访问。

 */


class Square {
private:
  double side;
  static int numberOfObjects;
  // ...
public:
  Square():Square(1.0){
  }
  Square(double side){
    this->side = side;
    numberOfObjects++;
    cout << numberOfObjects <<endl;
  }
};
int Square::numberOfObjects; // 不带static关键字
void staticMembers(){
    Square s1{}, s2{5.0};
}
