#include <vector>
#include <math.h>
#include <algorithm>

#include "pct.h"
#include "stat.h"

using namespace std;


class Pct : public IStatistics {
public:
	Pct (double proc) : procentil(proc) {};

    double pct(vector<double> arrr) {
		sort(arrr.begin(), arrr.end());
        int index = static_cast<int>(ceil(procentil * arrr.size()));
        return arrr[index - 1];
    }

	void update(double next) override {
		arr.push_back(next);
	}

	double eval() const override {
        Pct p(procentil);
        double c = p.pct(arr);
		return c;
	}

	const char * name() const override {
		return (procentil == 0.9) ? "pct90" : "pct95";
	}

private:
	double procentil;
    vector<double> arr;
};