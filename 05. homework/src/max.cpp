#include <limits>
#include "stat.cpp"
// #include "max.h"

using namespace std;



class Max : public IStatistics {
public:
	Max() : m_max{-DBL_MAX} {}

	void update(double next) override {
		if (next > m_max) {
			m_max = next;
		}
	}

	double eval() const override {
		return m_max;
	}

	const char * name() const override {
		return "max";
	}

private:
	double m_max;
};