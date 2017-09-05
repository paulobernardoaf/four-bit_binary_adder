#include <stdio.h>
#include <stdlib.h>

/*
                                  ==============================================================
                                  ||  TO COMPILE THE CODE FROM THE TERMINAL USE THIS COMMAND: ||
                                  ||                                                          ||
                                  ||               g++ somador.c -o somador-bin               ||
                                  ||                                                          ||
                                  ||==========================================================||
                                  ||                      TO RUN IT USE:                      ||
                                  ||                                                          ||
                                  ||               ./somador-bin <input1> <input2>            ||
                                  ||                                                          ||
                                  ==============================================================
*//*



                  LOGICAL GATES UTILIZED : AND , OR, XOR

                              AND --> &&
                              OR  --> ||
                              XOR --> ^

*//*



                                                     <<------ TRUTH TABLES ------>>

                                                        -------------------------
                                                        || A | B | SUM | CARRY ||
                                                        ||---------------------||
                                                        || 0 | 0 |  0  |   0   ||
                                                        ||---------------------||
                        HALF ADDER:                     || 0 | 1 |  1  |   0   ||
                                                        ||---------------------||
                                                        || 1 | 0 |  1  |   0   ||
                                                        ||---------------------||
                                                        || 1 | 1 |  0  |   1   ||
                                                        -------------------------



                                                -----------------------------------------
                                                || A | B | CARRY(IN) | SUM | CARRY(OUT)||
                                                ||-------------------------------------||
                                                || 0 | 0 |     0     |  0  |     0     ||
                                                ||-------------------------------------||
                                                || 0 | 0 |     1     |  1  |     0     ||
                                                ||-------------------------------------||
                                                || 0 | 1 |     0     |  1  |     0     ||
                                                ||-------------------------------------||
                        FULL ADDER:             || 0 | 1 |     1     |  0  |     1     ||
                                                ||-------------------------------------||
                                                || 1 | 0 |     0     |  1  |     0     ||
                                                ||-------------------------------------||
                                                || 1 | 0 |     1     |  0  |     1     ||
                                                ||-------------------------------------||
                                                || 1 | 1 |     0     |  0  |     1     ||
                                                ||-------------------------------------||
                                                || 1 | 1 |     1     |  1  |     1     ||
                                                -----------------------------------------




*///==============================================================================================================================================///
///===============================================================================================================================================///



/* FUNCTIONS DECLARATIONS  */
                                                    //__
int sumHalfAdder(int houseNum, int houseNum1)       //  |
{                                                   //  |
  int sum;                                          //  |
  sum = houseNum ^ houseNum1;                       //  |
  return sum;                                       //  |            \.
}                                                   //  |-------------\   These together form the complete HalfAdder.
                                                    //  |-------------/   I needed to separate for code purposes.
int carryHalfAdder(int houseNum, int houseNum1)     //  |            /
{                                                   //  |
  int carry;                                        //  |
  carry = houseNum && houseNum1;                    //  |
  return carry;                                     //__|
}


//==============================================================================================================================================//
//==============================================================================================================================================//

                                                                                //__
int sumFullAdder(int houseNum, int houseNum1, int carry)                        //  |
{                                                                               //  |
  int sum1;                                                                     //  |
  sum1 = (houseNum ^ houseNum1) ^ carry;                                        //  |
  return sum1;                                                                  //  |             \.
}                                                                               //  |--------------\   These together form the complete FullAdder.
                                                                                //  |--------------/   I needed to separate for code purposes.
int carryFullAdder(int houseNum, int houseNum1, int carry)                      //  |             /
{                                                                               //  |
  int carry1;                                                                   //  |
  carry1 =  (houseNum && houseNum1) || ((houseNum ^ houseNum1) && carry);       //  |
  return carry1;                                                                //__|
}


//==============================================================================================================================================//
//==============================================================================================================================================//


/* MAIN FUNCTION DECLARATION   */


int main(int argc, char *argv[])
{
  int num1 = atoi(argv[1]);      //Converting the first input(string) into an integer
  int num2 = atoi(argv[2]);      //Converting the second input(string) into an integer
  int i, houseNum1[5], houseNum2[5];


                                //__
  for (i = 0; i < 4;i++)        //  |
  {                             //  |
    houseNum1[i] = num1%10;     //  |
    num1 = num1 / 10;           //  |             \.
  }                             //  |--------------\    Here I segregated the digits from each number to compare them later.
                                //  |--------------/    Used loops and arrays to store the values.
  for (i = 0; i < 4; i++)       //  |             /
  {                             //  |
    houseNum2[i] = num2%10;     //  |
    num2 = num2 / 10;           //__|
  }


//===========================================================================================================================================//
//===========================================================================================================================================//



  /*  The next part is a bit confuse to explain, so i will start from the ending (line 176)

    ** The counting direction of the digits is left->right **

    Line 176 is the printf of the fourth digit (or fifth if needed), to print this digit we just need to use the sumHalfAdder() function;

    Line 175 is the printf of the third digit (or fouth if needed), to print this digit we need to use the sumFullAdder() function with
    the carryHalfAdder() function from the previous(fourth) digit on it.

    Line 174 is the printf of the second digit (or third if needed), to print this digit we need to use the sumFullAdder() function with
    the carryFullAdder() function from the previous(third) digit with the carryHalfAdder() function from the fourth digit on it.

    Line 173 is the printf of the first digit (or second if needed), to print this digit we need to use the sumFullAdder() function with
    the carryFullAdder() function from the previous(second) digit with the carryFullAdder() function from the third digit with the
    carryHalfAdder() function from the fourth digit on it.

    Line 169 only printf if the carryFullAdder() function from the fourth digit with the carryFullAdder() function from the third digit
    with the carryFullAdder() function from the second digit with the carryHalfAdder() function from the first digit, is equal to one.
    (cases that both first digits are one (ex: 1001 + 1010 = 10011))

  */





  if (carryFullAdder(houseNum1[3], houseNum2[3], carryFullAdder(houseNum1[2], houseNum2[2], carryFullAdder(houseNum1[1], houseNum2[1], carryHalfAdder(houseNum1[0], houseNum2[0])))) == 1)
  {
    printf("%d", carryFullAdder(houseNum1[3], houseNum2[3], carryFullAdder(houseNum1[2], houseNum2[2], carryFullAdder(houseNum1[1], houseNum2[1], carryHalfAdder(houseNum1[0], houseNum2[0])))));
  }
  printf("%d", sumFullAdder(houseNum1[3], houseNum2[3], carryFullAdder(houseNum1[2], houseNum2[2], carryFullAdder(houseNum1[1], houseNum2[1], carryHalfAdder(houseNum1[0], houseNum2[0])))));
  printf("%d", sumFullAdder(houseNum1[2], houseNum2[2], carryFullAdder(houseNum1[1], houseNum2[1], carryHalfAdder(houseNum1[0], houseNum2[0]))));
  printf("%d", sumFullAdder(houseNum1[1], houseNum2[1], carryHalfAdder(houseNum1[0], houseNum2[0])));
  printf("%d\n", sumHalfAdder(houseNum1[0], houseNum2[0]));

  return 0;
}
