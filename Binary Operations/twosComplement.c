#include <stdio.h>
#include <string.h>

int main()
{
 //size of the binary number entered by the user
int digits;
int bool=0;  
//index
int i=0;
//used to add 1 to the  one's complement and store the carry in
int add=1;

        printf("How many digits is your binary number?");
        scanf("%d",&digits);
        
//store a binary number entered by the user
char binary[digits+1];
//store one's complement of the binary number
char oneCom[digits+1];
//store two's complement of the binary number
char twoCom[digits+1];


      //checks if the number entered is in base 2
      while (bool!=1){
          
           //prompts the user for a binary number
            printf ("\nEnter a binary number: ");
            scanf("%s", binary);

           
            int check;
            for(i=0; i<strlen(binary); i++)
            {
              check = (int) binary[i]; // Casted to int to return the ASCII code of the character
                 
                /* The ASCII code of  0 is 48, and the ASCII code of 1 is 49
                If the character in the string has an ASCII code below 48 or above 49
                Then the number is not in base 2 and bool is set to 0*/
                 if (check<48 || check>49) {
                 bool=0;
                 break;
                 }
                 
                /* If all the characters have an ASCII code of 48 or 49. 
                Then number is in based 2 and  bool is set to 1 to exit the loop*/
                 else{
                     bool = 1;
                 }
                 
            }
         
          /*prints a message informing the user that the number entered is
          not a binary number*/ 
          if(bool==0){
         printf ("The number you entered is not a binary number");
         }
         
        
        }

    /*inverts all the bits in the binary representation of the 
    number to find its one's complement*/
    for(int j=0; j<strlen(binary); j++)
    {
        if(binary[j]=='1')
        {
            oneCom[j] ='0';
        }
        else if(binary[j] == '0')
        { 
            oneCom[j] ='1';
         
        }
    }
    
    // null-terminates the character string
    oneCom[digits+1] = '\0';


     /*adds 1 to the one's complement in reverse order to obtain the two's complement 
     of the binary number*/
    for (int s=strlen(binary); s >= 0; s--)
	{
		
        if(oneCom[s] == '1' && add == 1)
        {
          
            twoCom[s] = '0';
        }
        else if(oneCom[s] == '0' && add == 1)
        {
            twoCom[s] = '1';
            add = 0;
        }
        else
        {
            twoCom[s] = oneCom[s];
        }
    }
        // null-terminates the character string
    twoCom[digits+1] = '\0';
    
    
    //prints the original binary number , its one's and two's complement
    printf("\nBinary number= %s", binary);
    printf("\nOne's complement = %s", oneCom);
    printf("\nTwo's complement = %s", twoCom);
 
    return 0;
}