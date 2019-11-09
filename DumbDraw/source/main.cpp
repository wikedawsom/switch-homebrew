// Include the most common headers from the C standard library
#include <stdio.h>
#include <string.h>

// Include the main libnx system header, for Switch development
#include <switch.h>

// Main program entrypoint
int main(int argc, char* argv[])
{
	consoleInit(NULL);

	//To move the cursor you have to print "\x1b[r;cH", where r and c are respectively
	//the row and column where you want your cursor to move
	//printf("\x1b[16;20HHello World!");
	u32 col = 0;
	u32 row = 0;

	while (appletMainLoop())
	{
		hidScanInput();
		u64 kDown = hidKeysDown(CONTROLLER_P1_AUTO);

		if ((kDown & KEY_DOWN) && row < 45)
			row++;
		if ((kDown & KEY_UP) && row > 0)
			row--;
		if ((kDown & KEY_LEFT) && col > 0)
			col--;
		if ((kDown & KEY_RIGHT) && col < 80)
			col++;

		//if (kDown & KEY_A)
		//	printf(CONSOLE_ESC(%1$d;1m));

		// Clears the screan by using printf("\x1b[2J");
		if (kDown & KEY_MINUS)
			consoleClear();
		
		if (kDown & KEY_PLUS)
			break; // break in order to return to hbmenu

		// Update Console window with current cursor position
		printf("\x1b[%i;%iH@",row,col);
		consoleUpdate(NULL);
	}
	// Deinitialize and clean up resources used by the console (important!)
	consoleExit(NULL);
	return 0;
}