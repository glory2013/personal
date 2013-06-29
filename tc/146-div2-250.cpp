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

class YahtzeeScore{
public:
    int maxPoints(vector<int> toss){
        int r = 0;
        vector<int> sum(7, 0);
        for (int i = 0; i < 6; ++i){
            ++sum[toss[i]];
        }
        for (int i = 1; i <= 6; ++i){
            int s = sum[i]*i;
            if (r < s){
                r = s;
            }
        }

        return r;
    }
};

int main(){

    string line;
    getline(cin, line);
    istringstream tmp(line);
    vector<int> x;
    int t;
    while (tmp >> t){
        x.push_back(t);
    }
    YahtzeeScore r;
    cout << r.maxPoints(x) << endl;


//    copy(r.begin(), r.end(), ostream_iterator<int>(cout, " "));
    return 0;
}

