/*
 * =====================================================================================
 *       Filename:  146-div2 250
 *        Created:  04/20/2013 16:10:06 PM
 * =====================================================================================
 */

#include <sstream>
#include <iterator>
#include <algorithm>

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class A{
public:
    int a;
    double b;
};

int main(){

//    string line;
//    getline(cin, line);
//    istringstream tmp(line);
//    vector<int> v;
//    int t;
//    while (tmp >> t){
//        v.push_back(t);
//    }

    // 以非数据结尾即可
    vector<int> r( (istream_iterator<int>(cin)), (istream_iterator<int>()) );
    int n = r.size();
    for (int i = 0; i < n; ++i){
        cout << r[i];
        if (r[i] < n){
            n = r[i];
        }
    }

    A &na = new A();
    na.a = 1;
    na.b = 123.234;
    delete na;
    
//    copy(r.begin(), r.end(), ostream_iterator<int>(cout, " "));
    return 0;
}

