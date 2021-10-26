/**
 * @Author: Max
 * @Time: 10/26/21 20:16
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include<vector>

using namespace std;
using std::vector;


int count(string &main_str, int l){
    string mock;
    mock = main_str;
    vector<string> sub_str;

//    for (int i = 0; i < l; ++i) {
//        mock = mock.erase(i, 1);
//        sub_str.push_back(mock);
//        mock = main_str;
//    }
//
    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < l-1; ++j) {
            mock = mock.erase(i, 1);
            mock = mock.erase(j, 1);
            sub_str.push_back(mock);
            mock = main_str;
        }
    }

//    for (int i = 0; i < l; ++i) {
//        for (int j = 0; j < l-1; ++j) {
//            for (int k = 0; k < l-2; ++k) {
//                mock = mock.erase(i, 1);
//                mock = mock.erase(j, 1);
//                mock = mock.erase(k, 1);
//                sub_str.push_back(mock);
//                mock = main_str;
//            }
//        }
//    }



    int len_sub_str;
    len_sub_str = sub_str.size();

    for (int i = 0; i < len_sub_str; ++i) {
        cout << sub_str[i] << "\n";
    }

    for (int i = 0; i < len_sub_str; ++i) {
        for (int j = i+1; j < len_sub_str; ++j) {
            if (sub_str[i] == sub_str[j]){
                sub_str.erase(sub_str.begin() + j)
                j += 1;
                len_sub_str = sub_str.size();
            }
        }
    }
    for (int i = 0; i < len_sub_str; ++i) {
        cout << sub_str[i] << "\n";
    }
    cout << len_sub_str;
}

int main() {
    string main_str;
    getline(cin, main_str);
    int l = main_str.length();
    count(main_str, l);
    return 0;
}

//for (int i = 0; i < l; ++i) {
//for (int j = i+1; j < l; ++j) {
//for (int k = j+1; k < l; ++k) {
//mock = mock.erase(i, 1);
//mock = mock.erase(j, 1);
//mock = mock.erase(k, 1);
//sub_str.push_back(mock);
//mock = main_str;
//}
//}
//}


//for (int i = 0; i < l; ++i) {
//mock = mock.erase(i, 1);
//sub_str.push_back(mock);
//mock = main_str;
//}