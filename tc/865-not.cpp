/*
 * =====================================================================================
 *
 *       Filename:  srm570-250.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  04/05/2013 06:37:14 PM
 * =====================================================================================
 */

#include <iostream>
#include <vector>
using namespace std;

class RobotHerb{
    public:
        long long getdist(int times, vector<int> &steps){
            long long dx = 0;
            long long dy = 0;
            int dir_one = 0;
            vector<pair<int, int> > dirs;
            dirs.push_back(pair<int, int>(0, 1));
            dirs.push_back(pair<int, int>(1, 0));
            dirs.push_back(pair<int, int>(0, -1));
            dirs.push_back(pair<int, int>(-1, 0));
            for (vector<int>::const_iterator it = steps.begin(); it != steps.end(); ++it){
                dx += dirs[dir_one].first * *it;
                dy += dirs[dir_one].second * *it;
                dir_one = (dir_one + *it) % 4;
            }

            long long rx = 0;
            long long ry = 0;
            int srcdir = 0;
            //            for (vector<pair<int, int> >::iterator it = dirs.begin(); it != dirs.end(); ++it){
            int onedir = 0;
            for (; onedir < 4; ++onedir){
                if ((dx % 2) == dirs[onedir].first && (dy % 2) == dirs[onedir].second){
                    break;
                }
            }

            for (int n = 0; n < times; ++n){
                rx += dirs[(srcdir+onedir)&3].first * dx;
                ry += dirs[(srcdir+onedir)&3].second * dy;
                srcdir = (srcdir + dir_one) % 4;
            }
            return abs(rx) + abs(ry);
        }
};

int main(){
    RobotHerb r;
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    cout << r.getdist(1, v) << endl;
    return 0;
}
