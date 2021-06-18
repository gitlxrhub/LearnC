//
//  main.cpp
//  LearnC++
//
//  Created by ethan on 2021/6/4.
//

#include <iostream>
//#include <vector>
//#include "reference.hpp"
//#include "dataType.hpp"
//#include "auto.hpp"
//#include "declType.hpp"
//#include "testPointer.hpp"
//#include "testConstructors.hpp"
//#include "defaultConstructors.hpp"
//#include "staticMembers.hpp"
//#include "testFriend.hpp"
//#include "copyCtor.hpp"
//#include "baseClassCtor.hpp"
//#include "testPolymorphism.hpp"
//#include "testTemplate.hpp"
//#include "selectionSort.hpp"
//#include "testOperator.hpp"
#include "learnC++.hpp"

using namespace std;


class B {
public:
  void f() {
      cout << "B ~ f() " << endl;
  }
  void g() { f();
      cout << "B ~ g() " << endl;
  }
};
class D : public B {
public:
  void f() {
      cout << "D ~ f() " << endl;
  }
    void g() { B::f();
        cout << "D ~ g() " << endl;
    }
};

int main(int argc, const char * argv[]) {
//    baseClassCtor();
//    B b;
////    B* pb = &b;
//    D d;
//    D* pd = &d;
//    b.f();
//    pd->f();
    
    HailStone();
    
    
    
    return 0;
}
