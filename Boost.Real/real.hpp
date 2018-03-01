#include <functional>
#include <utility>

#ifndef __TEST_REAL_HPP__
#define __TEST_REAL_HPP__

namespace test {
	namespace real {
		enum op_type { id, add, subtract, multiply, divide };

		template<typename rational_t, typename integer_t>
			class real_num {
				std::function<std::pair<rational_t, rational_t>(int)> op1, op2;
				op_type op;

				public:
				std::pair<rational_t, rational_t> operator()(int K)
				{
					/* the approximation function for this real number
					 * The behaviour of this is determined by op;
					 * if op = id, then it simply returns op1(K)
					 * if op = add, it returns op1(K) + op2(K) */
					/* current behaviour: just return op1(K) */

					return op1(K);
				}

				real_num(std::function<std::pair<rational_t, rational_t>(int)> unary)
					: op1(unary), op(id) {};

				real_num operator+(const real_num &other);
				real_num operator*(const real_num &other);
				real_num operator-(const real_num &other);
				real_num operator/(const real_num &other);
				real_num operator!=(const real_num &other);
				real_num operator=(const real_num &other);
				real_num operator<(const real_num &other);

				real_num operator+(const integer_t &other);
				real_num operator*(const integer_t &other);
				real_num operator-(const integer_t &other);
				real_num operator/(const integer_t &other);
				real_num operator!=(const integer_t &other);
				real_num operator=(const integer_t &other);
				real_num operator<(const integer_t &other);
			};
	}
}

#endif
