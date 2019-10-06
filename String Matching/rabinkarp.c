#include<stdio.h>
#include<string.h>
#define d 256
int main()
{   char string[80],pattern[80];
    int q;
    printf("Enter the string \n");
    scanf("%s",string);
    printf("Enter a pattern to be searched \n");
    scanf("%s",&pattern);
    printf("Enter a mod-value \n");
    scanf("%d",&q);
    int patternlen = strlen(pattern);
    int stringlen = strlen(string);
    int i, j;
    int p = 0; //hash for pattern
    int t = 0; //hash for string
    int h = 1;

    for (i = 0; i < patternlen-1; i++)
        h = (h*d)%q;

    for (i = 0; i < patternlen; i++)
    {
        p = (d*p + pattern[i])%q;
        t = (d*t + string[i])%q;
    }
 
    for (i = 0; i <= stringlen - patternlen; i++)
    {
 
        if ( p == t )
        {
            for (j = 0; j < patternlen; j++)
            {
                if (string[i+j] != pattern[j])
                    break;
            }
 
            
            if (j == patternlen)
                printf("Pattern found at index %d.\n", i);
        }
 
        if ( i < stringlen-patternlen)
        {
            t = (d*(t - string[i]*h) + string[i+patternlen])%q;
            if (t < 0)
                t = (t + q);
        }
    }
    return 0;
}