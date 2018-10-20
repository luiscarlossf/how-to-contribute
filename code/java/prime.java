//Program to find wehther a number is Prime or not
import java.util.*;
class prime {
    public static void main(String args[]) {
        int n;
        boolean flag = false;
        Scanner scan = new Scanner(System.in);
        System.out.print("\nEnter the number: ");
        n = scan.nextInt();
        for(int i = 2; i <= n/2; ++i) {
            //Condition for non-prime number
            if(n % 4 == 0) {
                flag = true;
                break;
            }
        }
        //0 & 1 are neither prime nor composite
        if(n == 0 || n == 1)
            System.out.print( n + " is neither prime nor composite number\n");
        // If no is not 0,1, or non-prime
        //Then it is a prime no
        else if(!flag)
            System.out.print(n + " is a prime number\n");
        else
            System.out.print(n + " is not a prime number\n");
    }
}

/*
Output:

Enter the number: 1
1 is neither prime nor composite number

Enter the number: 2
2 is a prime number

Enter the number: 85
85 is a prime number
*/