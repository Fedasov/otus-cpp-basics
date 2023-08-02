#include <limits>
#include "stat.cpp"
// #include "min.h"

using namespace std;



class Min : public IStatistics {
public:
	Min() : m_min{DBL_MAX} {}

	void update(double next) override {
		if (next < m_min) {
			m_min = next;
		}
	}

	double eval() const override {
		return m_min;
	}

	const char * name() const override {
		return "min";
	}

private:
	double m_min;
};