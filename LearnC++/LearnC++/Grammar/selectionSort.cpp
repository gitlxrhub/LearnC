#include <iostream>
#include "learnC++.hpp"
#include <array>
#include <vector>
#include <set>
using namespace::std;
// 选择排序
void selectSort1(double list[],const size_t size){
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





void selectionSort(){
    int values[] = {1,5,3,4,9,6};
    vector<int> doubleVector(values,values+6);
    
    set<int> doubleSet;
    for (int i = 0; i < doubleVector.size(); i ++) {
        cout << "doubleVector  "<< doubleVector[i] << endl;
        doubleSet.insert(doubleVector[i] );
    }
    
    set<int>::iterator p;
    for (p = doubleSet.begin(); p != doubleSet.end(); p++) {
        cout << "doubleSet  "<< *p << endl;
    }

    
    
//    double aList[]{1.0,2.1,1.2,65.3,9.0,1.2,2.14,1.00,7.69};
//    cout << "排序--前--如下"<< endl;
//    for (double i: aList) {
//        cout << i << endl;
//    }
//    selectSort1(aList,sizeof(aList)/sizeof(aList[0]));
//    cout << "排序--后--如下"<< endl;
//    for (double i: aList) {
//        cout <<  i << endl;
//    }
    
/*
    std::array<double,9> bList = {1.0,2.1,1.2,65.3,9.0,1.2,2.14,1.00,7.69};
    cout << "排序--前--如下"<< endl;
    for (double i: bList) {
        cout << i << endl;
    }
    selectSort2(bList);
    cout << "排序--后--如下"<< endl;
    for (double i: bList) {
        cout <<  i << endl;
    }
 */
}
