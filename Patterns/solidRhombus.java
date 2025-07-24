package Patterns;



public class solidRhombus {

    public static void solidRombus(int n){
        for(int i=1; i<=n; i++){
            
            //n-i spaces
            for(int j=1; j<=n-i; j++){
                System.out.print(" ");
            }

            //n stars
            for(int k=1; k<=n; k++){
                System.out.print("*");
            }

            //i-1 spaces
            for(int l=1; l<=i-1; l++){
                System.out.print(" ");
            }
            System.out.println();
        }
    }
    public static void main(String[] args) {
        solidRombus(5);
    }
}
