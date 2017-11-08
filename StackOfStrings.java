import java.util.Scanner;

import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;;

public class StackOfStrings {
    public static void main(String[] args) {
        LinkedStackOfStrings stack = new LinkedStackOfStrings();

        java.util.Scanner scan = new java.util.Scanner(System.in);
        try {
            while(scan.hasNext()) {
                String s = scan.next();
                if(s.equals("-")) {
                    stack.pop();
                } else {
                    System.out.print(" " + scan.next());
                    stack.push(s);
                }
            }
        } catch(Exception e) {
            System.out.println("Exception!!" +  e);
        }
        System.out.println(" ");
        /*

        while(!StdIn.isEmpty()) {
          try {
            String s = StdIn.readString();
            if (s.equals("-")) {
                StdOut.print(stack.pop());
                //System.out.print("popped!");
            } else {
                System.out.print(" "+  s);
                stack.push(s);
            }
          } catch(NullPointerException e) {
              System.out.println("Exception!!" +  e);
          }
        }
        */
    }
}
