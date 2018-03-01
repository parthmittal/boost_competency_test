#include <utility>
#include <boost/rational.hpp>
#include <real.hpp>

#ifndef __TEST_ONE_THIRD_HPP__
#define __TEST_ONE_THIRD_HPP__

namespace test_one_third {
	typedef int integer_t;
	typedef boost::rational<integer_t> rational_t;

	std::pair<rational_t, rational_t> one_third(int K)
	{
		/* we know exact value is rational, so just return that every time */
		return {{1, 3}, {0, 1}};
	}

	void test()
	{
		std::function< std::pair<rational_t, rational_t>(int) > f(one_third);
		test::real::real_num<rational_t, integer_t> rn_one_third(f);

		if (rn_one_third(42) == std::make_pair(rational_t(1, 3), rational_t(0, 1))) {
			std::cerr << "test for 1/3 passed" << std::endl;
		} else {
			std::cerr << "test for 1/3 failed" << std::endl;
		}
	}
};

#endif
