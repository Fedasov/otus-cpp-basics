#include <vector>

#include "stat.h"
#include "std.h"

using namespace std;



class Std : public IStatistics {
public:
    Std() 
        : sum{0}
        , k{0} 
        , s_std{0}
        , mean{0} {}

    double std_d(vector<double> arrr, double s, int l) {
        mean = s / l;
        for (int i = 0; i < arrr.size(); i++) {
            s_std += (arrr[i] - mean) * (arrr[i] - mean);
        }
        return sqrt(s_std / l);
    }

	void update(double next) override { 
        sum += next;
        k++;
        arr.push_back(next);
	}

	double eval() const {
        Std s;
        double c = s.std_d(arr, sum, k);
		return c;
	}

	const char * name() const {
		return "std";
	}

private:
    vector<double> arr;
    double mean;
    double s_std;
    double sum;
    int k;
};