#include <stdio.h>
#include <cs50.h>

int main(void)
{

  printf("Integer, please: \n");
  int fullBoxes = 2;
  int num = 3; //number to be checked
  int userNum = GetInt();
  int facAm[userNum]; //init an array to store number of factors.
  facAm[0] = 1; //initing the two first HCNs.
  facAm[1] = 2;
  int hcnBank[userNum]; //init an array to store hcns.
  hcnBank[0] = 1;
  hcnBank[1] = 2;
  //storing first two hcns.
  while (fullBoxes != userNum) //begin the generation loop!
  {
      int d = 0;
      for (int c = 1; c <= num; c++) //begin counting off.
      {
          if (num % c == 0) //keep checking.
        {
          d++; //d is the number of divisors.
        }
      }

      if (d > facAm[fullBoxes-1]) //number of divisors prove greater than
      {                           //number of previous divisors
        facAm[fullBoxes] = d;     //then log that amount into facAm
        hcnBank[fullBoxes] = num; //and log the hcn itself into the bank.
        fullBoxes++;
      }

      num++; //as the sequence goes on, keep incrementing num.

  }

  for (int w = 0; w < fullBoxes; w++)
  {
    printf("%i\n", hcnBank[w]);
  }
}
