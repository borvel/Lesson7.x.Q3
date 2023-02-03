#include "numbers.h"
#include <random>

namespace Random {
    std::random_device rd;
    std::mt19937 mt{ rd() };
    int get(int min, int max)
    {

        std::uniform_int_distribution num{ min, max };
        return num(mt);
    }
}

int compare(const int num, const int winning_num)
{
	if (num < winning_num)
		return 0;
	else if (num > winning_num)
		return 1;
	return 2;
}
