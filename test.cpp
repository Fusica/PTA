/**
 * @Author: Max
 * @Time: 10/26/21 17:34
 */

#include<iostream>
#include<string>
#include<vector>

using std::cout; using std::cin;
using std::endl; using std::string;
using std::vector;

//template<typename T>
//void printVector(std::vector<T> v) {
//    for (const auto &item : v) {
//        cout << item << "; ";
//    }
//    cout << endl;
//}

int main() {
    vector<string> str_arr1;
    str_arr1.push_back("string");
    cout <<  * str_arr1.begin();

//    printVector(str_arr1);
//    str_arr1.emplace_back("Palm Cove");
//    printVector(str_arr1);


    return 0;
}