
#include "learnC++.hpp"
#include <iostream>

int dataType(){
    long int x (1.1);
    std::cout << x << std::endl;
    // 类型强制转换
//    std::cout << static_cast<double>(1/2) << std::endl;
//    std::cout << static_cast<double>(1)/2 << std::endl;
    return 0;
}
/*
 List Initialization（列表初始化）
 列表初始化的两个分类
 1. Direct list initialization (直接列表初始化)
 2. Copy list initialization (拷贝列表初始化)
 */
void initialization(){
    //直接列表初始化
    /* Variable initialization */
    int x{}; // x is 0;
    int y{ 1 }; // y is 1;
    /* Array initialization */
    int array1[]{ 1,2,3 };
    char s1[ 3 ] { 'o', 'k' };
    char s3[]{ "Hello" };
    
    //拷贝列表初始化
    /* Variable initialization */
    int z = { 2 };
    /* Array initialization */
    int array2[] = { 4,5,6 };
    char s2[] = { 'y','e','s' };
    char s4[] = { "World" };
    char s5[] = "Aloha"; // Omit curly braces (省略花括号)
}
