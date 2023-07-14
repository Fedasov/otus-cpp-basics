#include <vector>
#include <math.h>
#include <algorithm>

#include "stat.cpp"

using namespace std;


class Pct95 : public IStatistics {
public:
    double pct(vector<double> arrr) {
		sort(arrr.begin(), arrr.end());
        int index = static_cast<int>(ceil(0.95 * arrr.size()));
        return arrr[index - 1];
    }

	void update(double next) override {
		arr.push_back(next);
	}

	double eval() const override {
        Pct95 p;
        double c = p.pct(arr);
		return c;
	}

	const char * name() const override {
		return "pct95";
	}

private:
    vector<double> arr;
};