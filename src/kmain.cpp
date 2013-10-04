#if !defined(__cplusplus)
#include <stdbool.h>
#endif
#include <stddef.h>
#include <stdint.h>
 
/* Check if the compiler thinks if we are targeting the wrong operating system. */
#if defined(__linux__)
#error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif

#include <candy/vga_terminal.hpp>
 
#if defined(__cplusplus)
extern "C" /* Use C linkage for kmain, so the assembler can see the unmangled name. */
#endif
void kmain()
{
	VGATerminal t;
	t.Write("Welcome to CandyOS!\n");
	t.Write("This is made in Object Oriented C++!\n");
	t.Write("This command is using the VGA Implementation of the Terminal Interface!\n");
}