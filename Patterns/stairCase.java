package Patterns;
public class stairCase {
    public static void main(String[] args) {
        
        int input =5;
        

        for(int i=1; i<=input; i++){

            for(int j=1; j<=i*2; j++){
                System.out.print("* ");
            }
            System.out.println();

            for(int j=1; j<=i*2; j++){
                System.out.print("* ");
            }
            System.out.println();

        }
    }
}
