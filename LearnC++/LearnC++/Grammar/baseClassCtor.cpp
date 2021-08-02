using namespace::std;
#include <iostream>
#include "learnC++.hpp"
#include <set>
/*
 继承中的构造函数
 1. 派生类继承的成员
 1.1. C++11:派生类不继承的特殊函数
     (1)析构函数
     (2)友元函数
 1.2. 继承基类构造函数
     (1)using A::A;  继承所有基类ctor
     (2)不能仅继承指定的某个基类ctor
     (3)可以重写基类中的ctor
 1.3. 派生类构造函数必须调用基类构造函数。
 
 构造函数链
    这里的顺序不管怎么变，都是先调用基类的构造函数，再掉内嵌的构造函数，如果还有爷爷类，那就从爷爷类开始调用。从上往下
 析构函数链
    从下往上
 */


class B{
public:
    B(){
        cout <<"B()" <<endl;
    }
    B(int i){
        cout <<"B(int " << i << " )" <<endl;
    }
    B(char c){
        cout <<"B(char " << c << " )" <<endl;
    }
};



class B1:public B{
public:
    using B::B;  // 继承基类所有构造函数
};

class B2:public B{
public:
    using B::B;
    B2() = default;
    B2(double x):B{static_cast<int>(x)},x{1.0}{
        cout <<"B2(double "<< x <<" )" <<endl;
    }
private:
    double x{1.0};
};

class D{
public:
    D(){
        cout <<"D()" <<endl;
    }
};

class B3:public B{
public:
    using B::B;
    B3() = default;
    
    /*
     构造函数链
        这里的顺序不管怎么变，都是先调用基类的构造函数，再掉内嵌的构造函数，如果还有爷爷类，那就从爷爷类开始调用。从上往下
     析构函数链
        从下往上
     */
    B3(double x):d1{},B{static_cast<int>(x)},d2{}{ 
        cout <<"B3(double "<< x <<" )" <<endl;
    }
private:
    D d1,d2;
};

// 若基类ctor未被显式调用，基类的默认构造函数就会被调用，为了规范啊一般在基类中都要写好默认的构造函数
// 也就是说派生类构造函数必须调用基类构造函数。
class B4:public B{
public:
    using B::B;
    
//    // 情况一： B基类中有B4(),默认调用B()构造函数
//    B4():B(){
//        cout <<"B4()" <<endl;
//    }
    
    // 情况二： B基类中没有有B(),则需要手动调用基类的构造函数
    B4(int i):B{1}{
        cout <<"B4()" <<endl;
    }
};

class S {
  
  int age;
  int n{7};
  std::string s{"Hello"};
  set<int> intSet{1,1,1};
//    int a[] = {1,2,3}; 
//
//  auto b[] = {1,2,3};
public:
  int x = 7;
  
  S() {
      int a[]={1,2,3};
      int ss = 1;
      std::cout << "init S " << a[1] << std::endl;
  }
    
    
};


void baseClassCtor(){
//    B b;
//    B1 b1; // B1中如果没有构造函数，B1会默认生产一个构造函数并调用B中的默认构造函数(无参构造函数)
//    B1 b1_{1}; //相当于B1中 B(int i):B1(i){}
    
    /*
     Output
        B(int 1 )
        B2(double 1.03 )
     */
//    B2 b2{1.03};
    
    
    /*
     Output
        B(int 1 )
        D()
        D()
        B3(double 1.03 )
     */
//    B3 b3{1.03};
    
//    B4 b4{1};
//    std::cout << __cplusplus << std::endl; 显示C++版本
    
    S s{};
    std::cout << s.x << std::endl;
}
