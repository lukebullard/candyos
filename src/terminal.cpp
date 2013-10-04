#include <stddef.h>
#include <stdint.h>

#include "common.hpp"

#include <candy/types.hpp>
#include <candy/terminal.hpp>

void Terminal::Write(const CString data)
{
	size_t datalen = strlen(data);
	for ( size_t i = 0; i < datalen; i++ )
		PutChar(data[i]);
}