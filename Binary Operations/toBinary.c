#include <stdio.h>
#include <string.h>

int main()
{
    
    int n;
//Store zeros in the array
    char binary[]="0000000000000000";
//Another array of the same length to store the digits after every addition
    char bin[strlen(binary)];
    int add=1;
//prompts the user for a decimal number
    printf("Which decimal number do you want to convert to binary?\n");
    scanf("%d",&n);
//outer loop to handle the number of additions  
  while (n!=0)
  {
//inner loop to perform the addition
  for (int s=strlen(binary); s >= 0; s--)
	{
        if(binary[s] == '1' && add == 1)
        {
            bin[s] = '0';
        }
        else if(binary[s] == '0' && add == 1)
        {
            bin[s] = '1';
            add = 0;
        }
        else
        {
            bin[s] = binary[s];
        }
   
    }
//function to copy the elements of bin to binary after every addition
 strcpy(binary, bin);    
       add=1; 
    n--;
  }
//outputs the equivalent binary number  
        printf("\nBinary number= %s", binary);
    return 0;
}
