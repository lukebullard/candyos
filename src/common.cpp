#include <stddef.h>
#include <stdint.h>

#include <candy/types.hpp>
#include "common.hpp"

size_t strlen(const CString str)
{
	size_t ret = 0;
	while ( str[ret] != 0 )
		ret++;
	return ret;
}