#include "Functions.h"

bool check_input(std::string str)
{
	int dot_count = 0;
	for (size_t i = 0; i < str.size(); ++i)
	{
		if (i == 0 && str[i] == '-')
			continue;
		if (str[i] == '.')
		{
			if (dot_count == 0)
				++dot_count;
			else
				return false;
		}
		else if ((str[i] > '9') || (str[i] < '0'))
			return false;
	}
	return true;
}
