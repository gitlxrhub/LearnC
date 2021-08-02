#include "learnC++.hpp"
#include <iostream>
using namespace::std;
/*
 引用
 引用就是另一个变量的别名
 */
int reference1() {
    int x = 0;
    int y{10};
    int& rx = x;
    rx = 8;
    
    const char* s = "Hello";
    const char* t = "World";
    const char*& r = s;
    r = t;
//  s = t;
    std::cout << r << std::endl;
    std::cout << t << std::endl;
    return 0;
}

// 值作为形参传入
void swap1(int x,int y){
    int s = 0;
    s = x; x = y; y = s;
}

// 指针作为形参传入
void swap2(int* x,int* y){
    int s = 0;
    s = *x;
    *x = *y;
    *y = s;
}

// 引用类型作为形参传入，这个时候就实现了形参和实参的绑定，实际的操作就是直接操作实参的‘a’和‘b’
void swap3(int& x,int& y){
    int s = 0;
    s = x; x = y; y = s;
}

int reference2(){
    int a = 1,b = 2;
    std::cout << "Before calling" << std::endl;
    std::cout << "a=" << a << std::endl;
    std::cout << "b=" << b << std::endl;
//    swap1(a,b);
    swap2(&a,&b);
//    swap3(a,b);
    std::cout << "After calling" << std::endl;
    std::cout << "a=" << a << std::endl;
    std::cout << "b=" << b << std::endl;

    return  0;
}


/*
 1.数组作为参数传入函数，为了规范化，我们还要将数组的大小也要作为参数传入,而不是在函数内部去定义大小。
 2.数组名就是首元素的地址，所以实际上传入函数的不是数组名，而是首元素的地址，所以操作的数据是实际的实参。
 3.二维数组作为参数 与一维数组一样，有两种声明方式，但是区别是必须写出列数。
   第一种  int sum(int A[ ][ 4] , int size)  不能写成 int sum(int A[ ][ ] , int size)，必须将列数写进去，size的值是行数
   第二种  int sum(int （*A）[ 4] , int size)  //同样，必须将列数写进去，size的值是行数，而且必须要将*和数组名括起来。
 */
void selectSort(double list[],const size_t size){
    for (int i = 0; i < size - 1; i ++) {
        double min = list[i];
        int index = i;
        for (int j = i+1; j < size; j ++) {
            if (min > list[j]) {
                min = list[j];
                index = j;
            }
        }
        if(index != i){
            list[index] = list[i];
            list[i] = min;
        }
    }
}


int reference3(){
    double aList[]{1.0,2.1,1.2,65.3,9.0,1.2,2.14,1.00,7.69};
    cout << "排序--前--如下"<< endl;
    for (double i: aList) {
        cout << i << endl;
    }
    selectSort(aList,sizeof(aList)/sizeof(aList[0]));
    cout << "排序--后--如下"<< endl;
    for (double i: aList) {
        cout <<  i << endl;
    }
    return  0;
}
