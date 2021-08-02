#include <iostream>
using namespace::std;
#include "learnC++.hpp"

/*
    explicit关键字用来修饰类的构造函数，被修饰的构造函数的类，不能发生相应的隐式类型转换，只能以显示的方式进行类型转换。
 explicit使用注意事项:
     1.explicit关键字只能用于类内部的构造函数声明上。
     2.explicit关键字作用于单个参数的构造函数。(这点我不太理解，或者说是错误的，Point3()函数可证明)
     3.explicit关键字用来修饰类的构造函数，被修饰的构造函数的类，不能发生相应的隐式类型转换
 
 没有explicit修饰的构造函数是隐式构造函数，被explicit修饰的是显式构造函数。相反的implicit修饰的是隐式构造函数。
 */

class Point {
public:
    int x, y;
    explicit Point(int x = 0, int y = 0)
        : x(x), y(y) {
            cout << "(" << x << ","
                 << y << ")" << endl;
        }
};

class Point2 {
public:
    int x, y;
    Point2(int x = 0, int y = 0)
        : x(x), y(y) {
            cout << "(" << x << ","
                 << y << ")" << endl;
        }
};

class Point3 {
public:
    int x, y, z;
    explicit Point3(int x, int y,int z = 0)
        : x(x), y(y), z(z) {
            cout << "(" << x << "," << y << "," << z << ")" << endl;
        }
};

void displayPoint(const Point& p)
{
    cout << "(" << p.x << ","
         << p.y << ")" << endl;
}

void displayPoint2(const Point2& p)
{
    cout << "(" << p.x << ","
         << p.y << ")" << endl;
}

void displayPoint3(const Point3& p)
{
    cout << "(" << p.x << ","
         << p.y << "," << p.z << ")" << endl;
}

void testExplicit(){
//    displayPoint(Point(1)); // 只能显示写好参数调用
    /*
     隐式转换:
        “可以用 单个形参来调用 的构造函数定义了从 形参类型 到 该类类型 的一个隐式转换。”
        这里应该注意的是， “可以用单个形参进行调用” 并不是指构造函数只能有一个形参，而是它可以有多个形参，但那些形参都是有默认实参的。
        那么，什么是“隐式转换”呢？ 上面这句话也说了，是从 构造函数形参类型 到 该类类型 的一个编译器的自动转换。
     */
//    displayPoint2(2);//此处即发生一个隐式转换：int类型-->Point2类型，借助Point2的构造函数进行转换，以满足displayPoint2函数的参数期待。
    displayPoint3(Point3(1,2));
}
