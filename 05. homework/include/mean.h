#pragma once
#include "stat.h"

class Mean : public IStatistics {
public:

    Mean();
	void update(double next);
	double eval();
	const char * name();

private:
    double sum;
    int k;
};