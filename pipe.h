#include <stdio.h>
#include <unistd.h>
#include <linux/input.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <memory.h>
#define MAXPipeBufFERLEN 300
char PipeBuf[MAXPipeBufFERLEN];
void *TheadingCheckWindowFunc()
{
    while (1)
    {
        usleep(200000);
        FILE *fp = popen("xprop -id $(xprop -root 32x '\t$0' _NET_ACTIVE_WINDOW | cut -f 2) WM_CLASS", "r");
        fgets(PipeBuf, sizeof(PipeBuf), fp);

        //puts(PipeBuf);
        pclose(fp);
    }
    return 0;
}