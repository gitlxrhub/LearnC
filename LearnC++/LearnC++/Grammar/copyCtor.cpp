using namespace::std;
#include <iostream>
#include "learnC++.hpp"

class Squares{
private:
    double side;
    static int numberOfObjects;
public:

    Squares():Squares(2.0){
        cout <<"1-  numberOfObjects:" << numberOfObjects <<endl;
    }
    Squares(double side){
        this->side = side;
        numberOfObjects++;
        cout <<"2-  numberOfObjects:" << numberOfObjects <<endl;
    }
    
    Squares(int side){
        this->side = (side);
        numberOfObjects++;
        cout <<"3-  numberOfObjects:" << numberOfObjects <<endl;

    }
    
    //  拷贝构造函数
    /*      方法1 Circle (Circle&);
            方法2 Circle (const Circle&);
            方法3  X(const X&, int = 1); 带有额外的默认参数的拷贝构造函数
        警告：
            两个对象obj1和obj2已经定义。然后这种形式的语句：
            obj1 = obj2;
            不是调用拷贝构造函数，而是对象赋值。
     */
    Squares(const Squares& s){
        this->side = s.side;
        numberOfObjects++;
        cout <<"4- numberOfObjects:" << numberOfObjects <<endl;
    }
    
    ~Squares(){
        numberOfObjects--;
    }
    
    double getArea(){
        return numberOfObjects;
    }
};

int Squares::numberOfObjects{1}; // 不带static关键字
// 在堆和栈上分别拷贝创建Square对象
void copyCtor(){
    Squares s1{};
    Squares s2{s1};
    Squares* s3 = new Squares{s1};
    cout <<"getArea():" << s3->getArea() <<endl;
}
