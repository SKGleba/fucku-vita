#include <string.h>
#include <stdio.h>

#include <switch.h>

int main(int argc, char **argv)
{
    gfxInitDefault();

    //Initialize console. Using NULL as the second argument tells the console library to use the internal console structure as current one.
    consoleInit(NULL);

    //Move the cursor to row 16 and column 20 and then prints "Hello World!"
    //To move the cursor you have to print "\x1b[r;cH", where r and c are respectively
    //the row and column where you want your cursor to move
    printf("Heres a handy guide! Not prerssing anything will say 'fuck you', pressing A will say 'Shut up' and pressing B will say 'Bitch'!");
	printf("\x1b[16;20HFuck you.");
    
	while(appletMainLoop())
    {
        //Scan all the inputs. This should be done once for each frame
        hidScanInput();

        //hidKeysDown returns information about which buttons have been just pressed (and they weren't in the previous frame)
        u64 kDown = hidKeysDown(CONTROLLER_P1_AUTO);
		if(kDown & KEY_A)
		{
			printf(" Shut up.");
		}

		if(kDown & KEY_B)
		{
			printf(" Bitch.");
		}
		
        if (kDown & KEY_PLUS) break; // break in order to return to hbmenu
		
        gfxFlushBuffers();
        gfxSwapBuffers();
        gfxWaitForVsync();
    }

    gfxExit();
    return 0;
}
