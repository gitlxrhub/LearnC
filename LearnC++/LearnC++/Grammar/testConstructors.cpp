#include <iostream>
#include "learnC++.hpp"
using namespace::std;

/*
 构造函数
  1.Ctors的特点:
    (1)Automatic invocation(自动调用)
    (2)Has the same name as the defining class (与类同名)
    (3)NO return value (including "void"); (无返回值)
    (4)Can be overloaded (可重载)
    (5)May have no arguments (可不带参数)
 
 2.类可不声明构造函数
    编译器会提供一个带有空函数体的无参构造函数
    只有当未明确声明构造函数时，编译器才会提供这个构造函数，并称之为“默认构造函数”
 */



class Circle {
public:
  // The radius of this circle
  double radius;
 
  // Construct a circle object
  Circle() {
    radius = 1;
  }
 
  // Construct a circle object
  Circle(double newRadius) {
    radius = newRadius;
  }
 
  // Return the area of this circle
  double getArea() {
    return radius * radius * 3.14159;
  }
};

void testConstructors(){
    Circle circle1;
    Circle circle2(5.0);
    cout << "The area of the circle of radius " <<
            circle1.radius << " is " << circle1.getArea() << endl;
    cout << "The area of the circle of radius " <<
            circle2.radius << " is " << circle2.getArea() << endl;
    // Modify circle radius
    circle2.radius = 100.0;
    cout << "The area of the circle of radius " <<
            circle2.radius << " is " << circle2.getArea() << endl;
}
