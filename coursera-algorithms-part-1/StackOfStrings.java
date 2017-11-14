import java.util.*;
import java.io.*;

public class StackOfStrings {
    public static void main(String[] args) {
        //LinkedStackOfStrings stack = new LinkedStackOfStrings();
        FixedCapacityStackOfStrings stack = new FixedCapacityStackOfStrings();

        try {
        Scanner scan = new Scanner(System.in);
       // int i = scan.nextInt();
        String s = scan.nextLine();

        System.out.println(s);
        } catch(Exception e) {
        }

        /*
        while(!StdIn.isEmpty()) {
            String s = StdIn.readString();
            if (s.equals("-")) StdOut.print(stack.pop());
            else stack.push(s);
        }
        */
    }
}
