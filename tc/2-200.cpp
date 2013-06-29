/*
 * =====================================================================================
 *       Filename:  t.cpp
 *        Created:  04/06/2013 11:33:06 AM
 * =====================================================================================
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

class Time {
public:
    string whatTime(int seconds){
        int hour = 0;
        int min = 0;
        int sec = 0;
        hour = seconds / 3600;
        min = (seconds / 60) % 60;
        sec = seconds % 60;
        stringstream out;
        string r;
        out << hour << ":" << min << ":" << sec;
        r = out.str();
        cout << r;
        return r;
    }
};

int main(){
    int n;
    cin >> n;
    Time t;
    t.whatTime(n);
    return 0;
}

