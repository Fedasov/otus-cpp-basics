#pragma once

#include <vector>

#include "stat.h"

class Std : public IStatistics {
public:
    Std();
    double std_d(std::vector<double> arrr, double s, int l);
	void update(double next);
	double eval();
	const char * name();

private:
    std::vector<double> arr;
    double mean;
    double s_std;
    double sum;
    int k;
};