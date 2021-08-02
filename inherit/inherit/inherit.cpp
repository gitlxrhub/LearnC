#include<iostream>
using namespace std;
class Father{
public:
    Father()=default;
    void Father_show1(){
        cout<<"调用Father类的public方法：Father_show1"<<endl;
    }
protected:
    void Father_show2(){
        cout<<"调用Father类的protected方法：Father_show2"<<endl;
    }
private:
    void Father_show3(){
        cout<<"调用Father类的private方法：Father_show3"<<endl;
    }
};

class Son:public Father{
/* 从Father类中继承的所有成员
     三种属性能力的强弱：public<protected<private
     public:
         public:
            * 在Father类中属于public方法，继承到子类Son后放在类的public部分，由于public=public，因此在子类Son中Father_show1()方法仍是public方法
             void Father_show1(){
                 cout<<"调用Father类的public方法：Father_show1"<<endl;
             }
         protected:
            * 在Father类中属于protected方法，继承到子类Son后放在类的public部分，由于protected>public,因此子类Son中Father_show2()方法是protected方法
             void Father_show2(){  由于protected>public,因此子类Son中Father_show2()方法是protected方法
                 cout<<"调用Father类的protected方法：Father_show2"<<endl;
             }
         private:
            *在Father类中属于private方法，可以理解为“父亲的隐私”，继承到子类Son后放在类的public部分，由于private>public,因此子类Son中Father_show3()方法是private方法。然而正所谓“儿子即使继承了父亲的财产，也无法知晓父亲的隐私”，因此不管儿子以何种方式（public/protected/private）继承父亲的“财产”也无法利用父亲的“隐私”去进行“交易”，换句话说就是父类的private成员虽然可以被子类继承，但子类中的任何成员方法都不能在其函数体中调用这些从父类中继承而来的private成员。因此Son类中的成员方法不管其为与什么部分，都无法调用Father_show3
             void Father_show1(){
                 cout<<"调用Father类的public方法：Father_show1"<<endl;
             }
     */
public:
    Son()=default;
    void Son_fun1(){
        cout<<"调用Son类的public方法：Son_fun1"<<endl;
        Father_show1();
        Father_show2();
        //Father_show3(); //错误：无法调用Father类的private方法
    }
protected:
    void Son_fun2(){
        cout<<"调用Son类的protected方法：Son_fun2"<<endl;
        Father_show1();
        Father_show2();
        //Father_show3(); //错误：无法调用Father类的private方法
    }
private:
    void Son_fun3(){
        cout<<"调用Son类的private方法：Son_fun3"<<endl;
        Father_show1();
        Father_show2();
        //Father_show3();//错误：无法调用Father类的private方法
    }
};


class Son2:protected Father{
/* 从Father类中继承的所有成员
     三种属性能力的强弱：public<protected<private
    protected:
         public:
            * 由于public<protected,因此方法Father_show1()在类Son中是protected方法
             void Father_show1(){
                 cout<<"调用Father类的public方法：Father_show1"<<endl;
             }
         protected:
            * 由于protected=protected，因此方法Father_show2()在类Son中是protected方法
             void Father_show2(){  由于protected>public,因此子类Son中Father_show2()方法是protected方法
                 cout<<"调用Father类的protected方法：Father_show2"<<endl;
             }
         private:
            * 就像在公有继承中分析的那样，Father_show3()在类Son中虽然是private方法，但Son类中的任何成员方法都不能在其函数体中调用方法Father_show3()
             void Father_show1(){
                 cout<<"调用Father类的public方法：Father_show1"<<endl;
             }
     */
public:
    Son2()=default;
    void Son_fun1(){
        cout<<"调用Son类的public方法：Son_fun1"<<endl;
        Father_show1();
        Father_show2();
        //Father_show3(); //错误：无法调用Father类的private方法
    }
protected:
    void Son_fun2(){
        cout<<"调用Son类的protected方法：Son_fun2"<<endl;
        Father_show1();
        Father_show2();
        //Father_show3(); //错误：无法调用Father类的private方法
    }
private:
    void Son_fun3(){
        cout<<"调用Son类的private方法：Son_fun3"<<endl;
        Father_show1();
        Father_show2();
        //Father_show3();//错误：无法调用Father类的private方法
    }
};

class Son3:private Father{
/* 从Father类中继承的所有成员
     三种属性能力的强弱：public<protected<private
    private:
         public:
          * 由于public<private,因此方法Father_show1()在类Son中是private方法，但类Son中的成员方法可以在函数体内调用该方法
             void Father_show1(){
                 cout<<"调用Father类的public方法：Father_show1"<<endl;
             }
         protected:
           * 由于private>protected，因此方法Father_show2()在类Son中是private方法,但类Son中的成员方法可以在函数体内调用该方法
             void Father_show2(){  由于protected>public,因此子类Son中Father_show2()方法是protected方法
                 cout<<"调用Father类的protected方法：Father_show2"<<endl;
             }
         private:
            * 就像在公有继承中分析的那样，Father_show3()在类Son中虽然是private方法，但Son类中的任何成员方法都不能在其函数体中调用方法Father_show3()
             void Father_show1(){
                 cout<<"调用Father类的public方法：Father_show1"<<endl;
             }
     */
public:
    Son3()=default;
    void Son_fun1(){
        cout<<"调用Son类的public方法：Son_fun1"<<endl;
        Father_show1();
        Father_show2();
        //Father_show3(); //错误：无法调用Father类的private方法
    }
protected:
    void Son_fun2(){
        cout<<"调用Son类的protected方法：Son_fun2"<<endl;
        Father_show1();
        Father_show2();
        //Father_show3(); //错误：无法调用Father类的private方法
    }
private:
    void Son_fun3(){
        cout<<"调用Son类的private方法：Son_fun3"<<endl;
        Father_show1();
        Father_show2();
        //Father_show3();//错误：无法调用Father类的private方法
    }
};

// 保护继承（protected）和私有继承（private）有何不同
/*
我们发现上面的程序可以顺利运行。这是因为当Father类以保护方式（protected）继承GrandFather类时，GrandFather类中的公有方法GrandFather_show()会以protected方法的形式存在于类Father中，当类Son再以公有方式（public）继承类Father时，方法GrandFather_show()会仍以protected方法的形式存在与类Son中，由于一个类中的成员方法允许在其函数体内调用protected部分的成员，因此系统允许在Son类的成员方法Son_show()调用方法GrandFather_show()，从而使程序顺利运行。
 */
class _GrandFather{ //祖父类
public:
    _GrandFather()=default;
    void _GrandFather_show(){
        cout<<"调用_GrandFather类的方法：_GrandFather_show"<<endl;
    }
};

class _Father:protected _GrandFather{ //父类
public:
    _Father()=default;
};
class _Son:public _Father{ //子类
public:
    _Son()=default;
    void _Son_show(){
        cout<<"调用_Son类的方法：_Son_show"<<endl;
        _GrandFather_show();
    }
};


/*
    因为当Father类以私有（private）继承GrandFather类时，GrandFather类中的公有方法GrandFather_show()会以private方法的形式存在于类Father中，换句话说方法GrandFather_show()变成了类Father的“隐私”；当类Son再以公有方式（public）继承类Father时，由于“儿子无法利用父亲的“隐私”进行交易”，因此无法在Son类中的任何成员方法中调用GrandFather_show()方法，包括Son_show()。此时如果我们将类Son中成员函数Son_show()中的语句
 */
class _GrandFather1{ //祖父类
public:
    _GrandFather1()=default;
    void _GrandFather1_show(){
        cout<<"调用_GrandFather1类的方法：_GrandFather1_show"<<endl;
    }
};
class _Father1:private _GrandFather1{ //父类
public:
    _Father1()=default;
};
class _Son1:public _Father1{
public:
    _Son1()=default;
    void _Son1_show(){
        cout<<"调用_Son1类的方法：_Son1_show"<<endl;
//        GrandFather_show();  错误
    }
};

int main(){
    Son s;
    s.Son_fun1(); //正确，只能调用对象的public方法
//    s.Son_fun2(); 错误
//    s.Son_fun3(); 错误
    s.Father_show1();
//    s.Father_show2(); 错误
//    s.Father_show3(); 错误
    
    Son2 s2;
    s2.Son_fun1();
//    s2.Son_fun2(); //错误
//    s2.Son_fun3(); //错误
//    s2.Father_show1(); //错误
//    s2.Father_show2(); //错误
//    s2.Father_show3(); //错误
    
    Son3 s3;
    s3.Son_fun1();
//    s3.Son_fun2(); //错误
//    s3.Son_fun3(); //错误
//    s3.Father_show1(); //错误
//    s3.Father_show2(); //错误
//    s3.Father_show3(); //错误
    
    _Son _s;
    _s._Son_show();
    
    _Son1 _s1;
    _s1._Son1_show();

    return 0;
}
