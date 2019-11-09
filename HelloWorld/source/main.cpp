// Include the most common headers from the C standard library
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Include the main libnx system header, for Switch development
#include <switch.h>

// Main program entrypoint
int main(int argc, char *argv[])
{
    consoleInit(NULL);
    //Move the cursor to row 16 and column 20 and then prints "Hello World!"
    //To move the cursor you have to print "\x1b[r;cH", where r and c are respectively
    //the row and column where you want your cursor to move
    //printf("\x1b[16;20HHello World!");

    printf("Hello World\n");
    // Main loop
    while(appletMainLoop())
    {
        // Scan all the inputs. This should be done once for each frame
        hidScanInput();
        u64 kDown = hidKeysDown(CONTROLLER_P1_AUTO);
		if (kDown & KEY_A)
			for(int i = 0; i < 10; i++)
				printf("Hello\n");
        if (kDown & KEY_PLUS)
            break; // break in order to return to hbmenu
        consoleUpdate(NULL);
    }

    // Deinitialize and clean up resources used by the console (important!)
    consoleExit(NULL);
    return 0;
}