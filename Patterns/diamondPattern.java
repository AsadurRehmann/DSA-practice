package Patterns;

public class diamondPattern {

    public static void diamond_patteren(int n){

        for(int i=1; i<=n; i++){

            //n-i spaces
            for(int j=1; j<=n-i; j++){
                System.out.print(" ");
            }

            //2*i-1 stars
            for(int k=1; k<=(2*i)-1; k++){
                System.out.print("*");
            }
            System.out.println();

            //now invert it
            
        }

        for(int i=n; i>=1; i--){
                        //n-i spaces
            for(int j=1; j<=n-i; j++){
                System.out.print(" ");
            }

            //2*i-1 stars
            for(int k=1; k<=(2*i)-1; k++){
                System.out.print("*");
            }
            
            System.out.println();

        }
    }
    public static void main(String[] args) {
        diamond_patteren(5);
        
    }
}
