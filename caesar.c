/**
 *  Program to implement Caesar Cipher
 * 
 *  I had a bug where a large k value (65) would not 
 *  resolve properly. The fix was super easy: I just
 *  modulo'd k to make it smaller before passing to the
 *  main for loop.
 *  The logic in the loop may now be overkill.
 *  It would be worth it to revisit this program in 
 *  order to improve it. Magic numbers all over
 *  the place.
 *
 *
 */
 
 #include <stdio.h>
 #include <cs50.h>
 #include <string.h>
 #include <ctype.h>
 
 int main(int argc, string argv[])
 {
    // check user input
    // argc is how many command line args are passed
    // argv[0] is the filename, argv[1] is "k"
    // k is the key determining the amount of shift
    

    
    if(argc != 2)
    {
        printf("That is not valid\n");
        return 1;
    }
    
    int k = atoi(argv[1]);
    if(k < 0)
    {
        printf("That is not valid\n");
        return 1;
    }
    
    // re-size k to a reasonable value
    // that solved my bug for handling large k values
    if(k > 26)
        k = k % 26;

    
    // get a string to encipher from user
    // printf("Please enter a string: ");
    string plaintext = GetString();
    int length = strlen(plaintext);
    
     
    char temp; 
    int wrapper;
    
    for(int i = 0; i < length; i++)
    {
        // Check for passing end of alphabet (upper case)
        temp = plaintext[i];
        wrapper = plaintext[i] + k;
        
        if(isupper(temp) && wrapper > 90)
        {
            temp = (wrapper % 90) + 64;
    
            while(temp > 90)
                temp = temp % 90 + 64;
            
            printf("%c", temp);
        }
        else if(islower(temp) && wrapper > 122)
        {
            temp = (wrapper % 122) + 96;
            
            // bug fixed.
            while(temp > 122)
                temp = temp % 122 + 96;

            printf("%c", temp);
        }
        else if(temp != ' ' && isalpha(temp))
        {        
            temp = plaintext[i] + k;
            printf("%c", temp);
        }
        else if(temp == ' ')
            printf(" ");
        else
            printf("%c", temp);
    }
    
    printf("\n");
    return 0;
 }
