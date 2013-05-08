/**
 *  caesar debug program
 *
 *
 */


#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

int main(void)
{
    
    string clear = "barfoo";
    printf("clear: %s\n", clear);
    int span = strlen(clear);
    printf("span: %d\n", span);
    int k = 65;
    if (k > 26)
        k = k % 26;
    printf("k: %d\n", k);
    
    char temp;
    
    for(int i = 0; i < span; i++)
    {

        temp = clear[i] + k;
        printf("* %c *", temp);
        if(temp > 122)
        {
            temp = temp % 122 + 96;
            printf("%c", temp);
        }
    }
    printf("\n");
    return 0;
}
