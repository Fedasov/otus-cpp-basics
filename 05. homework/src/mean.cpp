#include "stat.cpp"
// #include "mean.h"
using namespace std;



class Mean : public IStatistics {
public:
    Mean() : sum{0}, k{0} {}

	void update(double next) override {
        k++;
        sum += next;
	}

	double eval() const override {
		return sum / k;
	}

	const char * name() const override {
		return "mean";
	}

private:
    double sum;
    int k;
};