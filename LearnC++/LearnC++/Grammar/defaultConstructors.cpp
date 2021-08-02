using namespace::std;
#include <iostream>
#include "learnC++.hpp"

/*
  默认构造函数
  初始化方式，c++初始化方式太多了，列出常用的三种
  执行次序：
    就地初始化 -> Ctor初始化类别 -> 在Ctor函数体中为成员赋值
  优先级：
    在Ctor函数体中为成员赋值 > Ctor初始化类别 > 就地初始化
 */

class Circle{
private:
    double radius;
public:
    Circle(){};
    Circle(double r){
        radius = r;
    };
    double getCircle(){
        cout << "radius:" << radius << endl;
        return 3.14*radius*radius;
    }
};

class Square{
private:
    double side;
public:
    Square(){}; // 如果写了带有参数的构造函数那这个默认的构造函数就会自动去除，这里就必须手动再添加上
    Square(double s){
        side = s;
    };
    double getSquare(){
        return side*side;
    }
};

class Combo{
public:
    Circle c{1.0};// 就地初始化
    Square s;
//    Combo():c{1.0}{  // okey 初始化列表
//    };
    Combo():s{10.0}{ // 如果函数体里赋值了那就必须要在先初始化，这种方式就是 构造函数初始化列表
        // s{10.0};// error
        s = {20.0}; // 这个时候只能赋值，不能叫初始化
    }
};
void defaultConstructors(){
    Combo cb;
    cout << cb.s.getSquare() << endl;
}
