package Patterns;

public class butterflyPatteren {

    public static void main(String[] args) {
        
    

    for(int i=1; i<=4; i++){
        //i stars
        for(int j=1; j<=i; j++){
            System.out.print("*");
        }

        //2x(n-i) spaces

        for(int k=1; k<=2*(4-i); k++){
            System.out.print(" ");
        }

        //i stars

        for(int l=1; l<=i; l++){
            System.out.print("*");
        }
        System.out.println();
    }



        for(int i=4; i>=1; i--){
        //i stars
        for(int j=1; j<=i; j++){
            System.out.print("*");
        }

        //2x(n-i) spaces

        for(int k=1; k<=2*(4-i); k++){
            System.out.print(" ");
        }

        //i stars

        for(int l=1; l<=i; l++){
            System.out.print("*");
        }
        System.out.println();
    }

}
    
}
