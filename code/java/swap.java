//Program to Swap two numbers wihtout using a third vairable
import java.util.*;
class swap {
    public static void main(String[] args) {
        int a,b;
        Scanner scan = new Scanner(System.in);
        System.out.println("\nSwapping values of two variables wihtout using third variable\n");
        System.out.print("Enter value of a: ");
        a = scan.nextInt();
        System.out.print("Enter value of b: ");
        b = scan.nextInt();
        System.out.println("\nValues before swapping:\na: " + a + "\nb: " + b);
        //Add second & first no and save in second no
        b = a + b;
        //Find the remainder of second no when divided by 10 and save in first no
        a = b % 10;
        //Subtract the first no from second and savve in second no
        b = b - a;
        //Print swapped values wihtout using third variable
        System.out.println("\nValues after swapping:\na: " + a + "\nb: " + b);
    }     
}

/*
Output:
Swapping values of two variables wihtout using third variable

Enter value of a: 10
Enter value of b: 3

Values before swapping:
a: 10
b: 3

Values after swapping:
a: 3
b: 10
*/