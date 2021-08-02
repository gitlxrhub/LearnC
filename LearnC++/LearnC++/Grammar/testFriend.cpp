using namespace::std;
#include <iostream>
#include "learnC++.hpp"

/*
  Friend 友元
    1.为何需要友元
      私有成员无法从类外访问,但有时又需要授权某些可信的函数和类访问这些私有成员.
    2.友元函数和友元类
      用friend关键字声明友元函数或者友元类,友元的缺点：打破了封装性
 */

// 对于类中定义的成员，其隐含的访问权限为private

class Date {
private:
  int year{ 2019 } , month{ 1 };
  int day{ 1 };
public:
  friend class Kid;
  friend void print(const Date& d);
};

void print(const Date& d) {
  cout << d.year << "/" << d.month
       << "/" << d.day << endl;
}

class Kid {
private:
  Date birthday;
public:
  Kid(){
    cout << "I was born in "
         << birthday.year << endl;
  }
};
void testFriend(){
    print(Date());
    Kid k;
    cin.get();
}
