/*
 * =====================================================================================
 *       Filename:  t.cpp
 *        Created:  04/20/2013 14:43:06 AM
 * =====================================================================================
 */

#include <sstream>
#include <iterator>
#include <algorithm>
#include <cmath>

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class RectangularGrid {
public:
    long jc(int n){
        return n*(n+1)/2;
    }

    long long countRectangles(int width, int height){
        long long r = 0;
        int big, small;
        if (width > height){
            big = width;
            small = height;
        }else{
            small = width;
            big = height;
        }
        r = jc(width) * jc(height);
        for (; small > 0; --small, --big){
            r -= small * big;
        }
        return r;
    }
};

int main(){

    string line;
    getline(cin, line);
    istringstream tmp(line);
    vector<int> v;
    int width, height;
    int t;
    while (tmp >> t){
        v.push_back(t);
    }
    width = v[0];
    height = v[1];
    RectangularGrid x;
    cout << x.countRectangles(width, height) << endl;

//    copy(r.begin(), r.end(), ostream_iterator<int>(cout, " "));
    return 0;
}

