/*
 * =====================================================================================
 *        think too much... just do the basic loop.
 *        Created:  06/29/2013 16:10:06 PM
 * =====================================================================================
 */

#include <sstream>
#include <iterator>
#include <algorithm>

#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

class PeopleCircle{
public:
    string order(int numMales, int numFemales, int K){
		string r(numMales + numFemales, 'M');
		multiset<int> positions;
		int idx = 0;
		int len = numMales + numFemales;
		int key;
		for (int n = 0; n < numFemales; ++n, --len){
			idx +=  K % len - 1;
			idx %= len;
			set<int>::iterator it = positions.upper_bound(idx);
			key = idx + static_cast<int>(distance(positions.begin(), it));
			positions.insert(it, key);
		}
		int n = 0;
		for (multiset<int>::iterator it = positions.begin(); 
				it != positions.end(); ++it){
			r[*it + n++] = 'F';
		}
        return r;
    }
};

int main(){

    // end up with non-number
    vector<int> r( (istream_iterator<int>(cin)), (istream_iterator<int>()) );
	PeopleCircle p;
	cout << p.order(r[0], r[1], r[2]) << endl;

//    copy(r.begin(), r.end(), ostream_iterator<int>(cout, " "));
    return 0;
}

