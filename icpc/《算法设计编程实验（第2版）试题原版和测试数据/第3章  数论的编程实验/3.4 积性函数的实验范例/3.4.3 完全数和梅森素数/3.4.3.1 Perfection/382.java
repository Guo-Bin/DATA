// by Dan Joyce
// solves Problem 6: Perfection
// of 1996 Mid Atlantic programming contest

// Note: output format still not perfect

// input is a list of integers
// output ids each as either perfect, deficient or abundant


import java.io.*;
import common.doinput;

class problem6 {

  public static void main (String [] args) throws IOException {
    int num, sum, count;
    String num_string;
    doinput myinput = new doinput();

    System.out.println("PERFECTION OUTPUT");

    num = myinput.nextint();

    while (num != 0)  {
      // what is it?
      if (num != 1)
        sum = 1;
      else sum = 0;
      count = 2;
      while (count < num)  {
        if ((num % count) == 0) 
          sum = sum + count;
        count = count + 1;
        }

      System.out.print (num + " ");
      if (sum < num) System.out.println ("DEFICIENT");
      if (sum == num) System.out.println ("PERFECT");
      if (sum > num) System.out.println ("ABUNDENT");

      num = myinput.nextint();
      }
    System.out.println("END OF OUTPUT");
  }
}

