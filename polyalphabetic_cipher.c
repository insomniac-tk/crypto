#include <stdio.h>
#include<string.h>
#define max 100
//print text
void print_text(char text[])
{
    int i;
    for(i=0;i<strlen(text);i++)
    {
        printf("%c",text[i]);
    }
}

void encrypt(char message[],char key_string[])
{
    char table[26][26];
    int i,j,len;
    len = strlen(message);
    char cipher_text[max];
    //the poly table
    for(i=0;i<26;i++)
    {
        for(j=0;j<26;j++)
        {
            int tmp = 65 + (j+i)%26  ;
            table[i][j] = tmp;
        }
    }

    // the main loop running over the message and key text
    for(i=0;i<len;i++)
    {
        
        char plain = message[i]; // get the character from msg -> column
        char key  =  key_string[i];
        int itr,plain_index,key_index;
        for(itr=0;itr<26;itr++)
        {
            if(table[0][itr]==plain)
               {
                   plain_index = itr;
                   break;
               }
        }
        for(itr=0;itr<26;itr++)
        {
            if(table[itr][0]==key)
               {
                   key_index = itr;
                   break;
               }
        }
        // we have the indices now hurrrrrayyyyyyyy!!!
        cipher_text[i] = table[key_index][plain_index];
    }
    printf("\n");
    printf("Cipher Text :");
    puts(cipher_text);
}


int main()
{ 
    char input[max],keyword[max];
    printf("Enter plain text >> ");
    scanf("%[^\n]%*c",input); // scan upto newlien char , ignore the \n 
    int len = strlen(input);
    printf("Enter keyword(should be %d characters long) >> ",len);
     scanf("%[^\n]%*c",keyword); // scan upto newlien char , ignore the \n 
    printf("Plain Text :");
    int i;
    for(i=0;i<strlen(input);i++)
         printf("%c",input[i]);
   printf("\nKeyword:");
   for(i=0;i<strlen(keyword);i++)
         printf("%c",keyword[i]);
     encrypt(input,keyword);
    return 0;
}
