#ifndef __CDY_VGA_TERMINAL_HPP__
#define __CDY_VGA_TERMINAL_HPP__

#include <stddef.h>
#include <stdint.h>

#include <candy/terminal.hpp>

/* Hardware text mode color constants. */
enum vga_color
{
	COLOR_BLACK = 0,
	COLOR_BLUE = 1,
	COLOR_GREEN = 2,
	COLOR_CYAN = 3,
	COLOR_RED = 4,
	COLOR_MAGENTA = 5,
	COLOR_BROWN = 6,
	COLOR_LIGHT_GREY = 7,
	COLOR_DARK_GREY = 8,
	COLOR_LIGHT_BLUE = 9,
	COLOR_LIGHT_GREEN = 10,
	COLOR_LIGHT_CYAN = 11,
	COLOR_LIGHT_RED = 12,
	COLOR_LIGHT_MAGENTA = 13,
	COLOR_LIGHT_BROWN = 14,
	COLOR_WHITE = 15,
};

class VGATerminal : public Terminal
{
private:
	size_t currentRow;
	size_t currentColumn;
	uint8_t currentColor;
	uint16_t* vgaBuffer;
protected:
	uint16_t MakeEntry(char c,uint8_t color);
	void PutEntryAt(char c,uint8_t color,size_t x,size_t y);
public:
	static const size_t VGA_WIDTH = 80;
	static const size_t VGA_HEIGHT = 24;
	
	uint8_t MakeColor(enum vga_color fg, enum vga_color bg);
	void SetColor(uint8_t color);
	void PutChar(char c);
	VGATerminal();
};

#endif //__CDY_VGA_TERMINAL_HPP__