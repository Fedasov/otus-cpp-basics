#pragma once
#include "stat.h"
#include <vector>

class Pct : public IStatistics {
public:
	Pct (double proc);
    double pct(std::vector<double> arrr);
	void update(double next);
	double eval();
	const char * name();

private:
	double procentil;
    std::vector<double> arr;
};