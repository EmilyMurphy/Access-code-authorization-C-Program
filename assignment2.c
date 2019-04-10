/* Write a program that will perform security authorisation based on access codes.
The access codes are 4 single-digit integer numbers between 0-9,he default authorised access code is 4523.
Author: Emily Murphy
Compiler: CodeBlocks
OS: MAC OS X
Date: 12/03/2017
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// define symbolic names
# define PINSIZE 4
# define OPTION 2
# define ENTRY 6

//prototypes
void enter_code(char[]);
void encrypt_code( char[],int[], int *, int *, int *);
void decrypt_code(int*);
void successfull_incorrect(int*, int*);
void exit_program(int*);

int main() //start main
{
    //intialising variables
    char choice_array[OPTION];
    char choice;
    char entered_pin[ENTRY];
    int counter = 0;
    int successfull = 0;
    int incorrect =0;
    int answer;
    int Comp_temp[PINSIZE];
    int counter_choice = 0;
    int encrypt_counter = 0;

    do{

        //show menu
        printf("\n1. Enter code\n");
        printf("2. Encrypt code and verify if correct \n");
        printf("3. Decrypt code\n");
        printf("4. Display the number of times the code was entered (i) Successfully (ii) Incorrectly\n");
        printf("5. Exit Program\n");

        // scan users choice
        scanf("%1s",choice_array);

        choice = *(choice_array);


        if(choice == '1')//menu option one
        {
            counter_choice++;
            enter_code(entered_pin);

        }

        if(choice == '2')// menu option two
        {
            if(counter_choice > 0) // error checking
            {

                encrypt_code(entered_pin,Comp_temp,&successfull,&incorrect, &counter);
                encrypt_counter++;


            }
            else
            {
                printf("Error, can only encrypt after you enter code\n");
            }


        }

        if(choice == '3')//menu option three
        {
            if(encrypt_counter > 0) // error checking
            {

                decrypt_code(Comp_temp);


            }
            else
            {
                printf("Error, can't decrypt until you encrypt\n");
            }
        }

        if(choice == '4')// menu option four
        {
             successfull_incorrect( &successfull, &incorrect);
        }

        if(choice == '5')//menu option five
        {
            exit_program(&answer);
        }

    }while(choice != '5');//end program in option five

    return(0);

}// end main


//function for option one: enter code
void enter_code(char entered_pin[])
{
    //ensures null terminator
    scanf("%5s",entered_pin);


}//end entered_pin

//function for option two: encrypt code
void encrypt_code(char entered_pin[], int Comp_temp[],int * successfull, int * incorrect, int * counter)
{

        //intialising variables
        int temp_array;
        int i;
        char char_temp;
        char Temp[PINSIZE];
        int int_char;
        int access_code[PINSIZE]= {4,5,2,3};

        *(counter) =0 ;



        //changing string array into an int array
        for(i = 0; i < PINSIZE; i++)
        {

            char_temp = *(entered_pin+i);

            *(Temp+i) = char_temp;

            int_char = atoi(Temp);

            *(Comp_temp+i) = int_char % 10; // gives correct remainder as int

        }//end for



        //swap 1st number with 3rd
        temp_array = *(Comp_temp);
        *(Comp_temp) = *(Comp_temp + 2);
        *(Comp_temp + 2) = temp_array;

        //swap 2nd number with 4th
        temp_array = *(Comp_temp+ 1);
        *(Comp_temp+ 1) = *(Comp_temp+ 3);
        *(Comp_temp+ 3) = temp_array;

        //add 1
        for(i=0; i<PINSIZE; i++)
        {
            *(Comp_temp+i) = *(Comp_temp + i)+1;

        }//end for

        for(i=0; i<PINSIZE; i++)
        {

            if(*(Comp_temp+i) == 10) //check if number is equal to 10
            {
                *(Comp_temp + i) = 0; // change to 0 if equal to 10

            }//end if

        }//end for


        //check if it is access code
        for(i=0; i<PINSIZE; i++)
        {
            if(*(Comp_temp+i) == *(access_code+i))
            {

                *(counter)=*(counter)+1;

            }
            else
            {

                *(counter)= *(counter)-1;

            }// end if else
        }//end for


        if(*(counter) == 4) //error check to see if it is correct code
        {

            printf("CORRECT CODE");

            *(successfull) = *(successfull)+1;

        }
        else
        {

            printf("ERROR CODE");

            *(incorrect) = *(incorrect)+1;

        }



}// end function encrypt code

//function for option 3: decrypt code
void decrypt_code(int Comp_temp[])
{
    //initialise variables
    int other_temp;
    int i;

        //minus 1
        for(i=0; i<PINSIZE; i++)
        {
            *(Comp_temp+i) = *(Comp_temp + i)-1;
        }//end for

        //swap 3rd with 1st
        other_temp = *(Comp_temp + 2);
        *(Comp_temp + 2) = *(Comp_temp);
        *(Comp_temp) = other_temp;

        //swap 4th with 2nd
        other_temp = *(Comp_temp+ 3);
        *(Comp_temp+ 3) = *(Comp_temp+ 1);
        *(Comp_temp+ 1) = other_temp;


}//end decrypt code

//function for option four: display successfull and incorrect
void successfull_incorrect(int *successfull, int *incorrect)
{
    printf("The number of times the code was entered Successfully was %d and Incorrectly was %d \n", *(successfull), *(incorrect));

}//end successfull incorrect

//function for option five: end program
void exit_program(int *answer)
{
    // end program
    printf("Enter any key to end\n ");
    scanf("%d", & *(answer));

}// end exit program
