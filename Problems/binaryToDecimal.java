package Problems;
import java.util.Scanner;

public class binaryToDecimal {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int input =sc.nextInt();
        int power=0;
        int decimal=0;

        while (input>0) {
            int last=input%10;
            decimal+=last*Math.pow(2, power);
            power++;
            input=input/10;
        }
        System.out.println(decimal);
        sc.close();
    }
}
