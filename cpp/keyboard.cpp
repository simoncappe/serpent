#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

#include "keyboard.h"

static struct termios oldSettings, newSettings;

void keyboard_init()
{
    tcgetattr(fileno(stdin), &oldSettings);
    newSettings = oldSettings;
    newSettings.c_lflag &= (~ICANON & ~ECHO);
    tcsetattr(fileno(stdin), TCSANOW, &newSettings);
}

void keyboard_end()
{
    tcsetattr(fileno(stdin), TCSANOW, &oldSettings);
}

char keyboard_scan()
{
    char ret = 0;

    fd_set set;
    struct timeval tv;

    // Modification de période de scan
    // Passage 1s à 1 ms
    tv.tv_sec = 0;
    tv.tv_usec = 1000;

    FD_ZERO(&set);
    FD_SET(fileno(stdin), &set);

    int res = select(fileno(stdin) + 1, &set, NULL, NULL, &tv);

    if (res > 0)
    {
        char c;
        //printf("Input available\n");
        read(fileno(stdin), &ret, 1);
    }
    else if (res < 0)
    {
        //perror("select error");
    }
    else
    {
        //printf("Select timeout\n");
    }

return ret;
}
