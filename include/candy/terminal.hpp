#ifndef __CDY_TERMINAL_HPP__
#define __CDY_TERMINAL_HPP__

#include <candy/types.hpp>

class Terminal
{
public:
	void Write(const CString data);
	virtual void PutChar(char c);
};

#endif //__CDY_TERMINAL_HPP__