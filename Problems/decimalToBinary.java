package Problems;
import java.util.Scanner;

public class decimalToBinary {
    public static void main(String[] args) {
        Scanner sc =new Scanner(System.in);
        System.out.print("Enter a integer:");
        int input = sc.nextInt();
        String result="";
        

        while (input>0) {
            if (input%2==0) {
            while (input%2==0) {
                 int x=input/2;
                 input/=2;
                 result+="0";
            }
        }

        if ((input%2==1)) {
            while (input%2==1) {
                 int x=input/2;
                 input/=2;
                 result+="1";
            }
        } 
        }
       
        result=new StringBuilder(result).reverse().toString();
        System.out.println("Binary:"+result);
        sc.close();
    }
}
