#include <stdio.h>
 
int main()
{
    int a = 10, b = 0, c = 10;
 
    // The folloing program generates a map of India
    char* str = "TFy!QJu ROo TNn(ROo)SLq SLq ULo+UHs UJq "
                "TNn*RPn/QPbEWS_JSWQAIJO^NBELPeHBFHT}TnALVlBL"
                "OFAkHFOuFETpHCStHAUFAgcEAelclcn^r^r\\tZvYxXyT|S~Pn SPm "
                "SOn TNn ULo0ULo#ULo-WHq!WFs XDt!";
 
    while (a != 0)
    {
        a = str[b++];
        while (a-- > 64)
        {
            if (++c == 90) // 'Z' is 90 in ascii
            {
                c = 10;        // '\n' is 10 in ascii
                putchar('\n'); // or putchar(c);
            }
            else
            {
                if (b % 2 == 0)
                    putchar('!');
                else
                    putchar(' ');
            }
        }
    }
 
    return 0;
}
