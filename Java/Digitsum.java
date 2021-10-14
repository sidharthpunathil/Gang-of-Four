import java.io.*;
import java.util.Scanner;
class Digitsum{
    public static void main(String args[]) {
        int n,r,sum=0;
        Scanner reader=new Scanner(System.in);
        System.out.print("Enter the number: ");
        n=reader.nextInt();
        while(n!=0)
        {
            r=n%10;
            sum=sum+r;
            n=n/10;
        }
        System.out.println("Digit Sum: "+sum);
    }
}
