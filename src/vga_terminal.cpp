#include <stddef.h>
#include <stdint.h>

#include <candy/terminal.hpp>
#include <candy/vga_terminal.hpp>

uint16_t VGATerminal::MakeEntry(char c, uint8_t color)
{
	uint16_t c16 = c;
	uint16_t color16 = color;
	return c16 | color16 << 8;
}

uint8_t VGATerminal::MakeColor(enum vga_color fg,enum vga_color bg)
{
	return fg | bg << 4;
}

void VGATerminal::SetColor(uint8_t color)
{
	currentColor = color;
}

void VGATerminal::PutEntryAt(char c, uint8_t color, size_t x, size_t y)
{
	const size_t index = y * VGA_WIDTH + x;
	vgaBuffer[index] = MakeEntry(c, color);
}


VGATerminal::VGATerminal()
{
	currentRow = 0;
	currentColumn = 0;
	currentColor = MakeColor(COLOR_LIGHT_GREY, COLOR_BLACK);
	vgaBuffer = (uint16_t*) 0xB8000;
	for ( size_t y = 0; y < VGA_HEIGHT; y++ )
	{
		for ( size_t x = 0; x < VGA_WIDTH; x++ )
		{
			const size_t index = y * VGA_WIDTH + x;
			vgaBuffer[index] = MakeEntry(' ', currentColor);
		}
	}
}


void VGATerminal::PutChar(char c)
{
	if (c == '\n')
	{
		currentRow++;
		currentColumn=0;
		return;
	}
	PutEntryAt(c, currentColor, currentColumn, currentRow);
	if ( ++currentColumn == VGA_WIDTH )
	{
		currentColumn = 0;
		if ( ++currentRow == VGA_HEIGHT )
		{
			currentRow = 0;
		}
	}
}