/*
 * =====================================================================================
 *       Filename:  t.cpp
 *        Created:  04/06/2013 11:33:06 AM
 * =====================================================================================
 */

#include <iostream>
#include <sstream>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

// pair: score, nth
struct cmp{
    bool operator()(pair<int, int> p1, pair<int, int> p2){
        if (p1.first == p2.first){
            return p1.second > p2.second;
        }
        return p1.first < p2.first;
    }
};

class Bonuses{
public:
    vector<int> getDivision(vector<int> &points){
        int sum = 0;
        vector<int> r(points.size(), 0);
        set<pair<int, int>, cmp> example;
        for (int i = 0; i < points.size(); ++i){
            sum += points[i];
        }
        int allocated = 0;
        for (int i = 0; i < points.size(); ++i){
            r[i] = points[i] * 100 / sum;
            allocated += r[i];
            example.insert(make_pair(points[i], i));
        }
        if (allocated < 100){
            int left = 100 - allocated;
            cout << sum << left << endl;
            for (set<pair<int, int>, cmp>::reverse_iterator it = example.rbegin();
                    it != example.rend() && left > 0; ++it){
                ++r[it->second];
                --left;
            }
        } // if (allocated

        for (set<pair<int, int>, cmp>::reverse_iterator it = example.rbegin(); it != example.rend(); ++it){
            cout << it->first << " " << it->second << "\t";
        }
        cout << endl;
        return r;
    }
};

int main(){
    vector<int> ci;

    string line;
    getline(cin, line);
    istringstream tmp(line);
    int t;
    while (tmp >> t){
        ci.push_back(t);
    }

    Bonuses b;
    vector<int> r = b.getDivision(ci);
    copy(r.begin(), r.end(), ostream_iterator<int>(cout, " "));
    return 0;
}

