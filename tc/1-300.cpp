/*
 * =====================================================================================
 *       Filename:  1.cpp
 *        Created:  04/05/2013 09:06:11 PM
 * =====================================================================================
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BinaryCode{
public:
    vector<string> decode(string dst){
        int len = dst.length();
        bool flag0 = true;
        bool flag1 = true;
        vector<int> src0(len+2, 0), src1(len+2, 0);
        src1[1] = 1;
        for (int i = 1; i <= len; ++i){
            if (flag0){
                src0[i+1] = dst[i-1] - '0' - src0[i] - src0[i-1];
                if (src0[i+1] != 0 && src0[i+1] != 1){
                    flag0 = false;
                }
            }
            if (flag1){
                src1[i+1] = dst[i-1] - '0' - src1[i] - src1[i-1];
                if (src1[i+1] != 0 && src1[i+1] != 1){
                    flag1 = false;
                }
            }
            if (!(flag0 || flag1)){
                break;
            }
        }
        if (src0[len+1] == 1){
            flag0 = false;
        }
        if (src1[len+1] == 1){
            flag1 = false;
        }
        vector<string> result(2, "");
        if (flag0){
            for (int i = 1; i <= len; ++i){
                result[0].push_back('0' + src0[i]);
            }
        }else{
            result[0] = "NONE";
        }
        if (flag1){
            for (int i = 1; i <= len; ++i){
                result[1].push_back('0' + src1[i]);
            }
        }else{
            result[1] = "NONE";
        }
        cout << result[0] << "\t" << result[1] << endl;
        return result;
    }
};

int main(){
    BinaryCode b;
    string s;
    cin >> s;
    b.decode(s);
    return 0;
}
