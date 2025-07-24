package Patterns;

public class hollowRombus {

    public static void hollow_rombus(int n){

        for(int i=1; i<=n; i++){

            //for spaces
            for(int m=1; m<=n-i; m++){
                System.out.print(" ");
            }

            //hollow rectangle
            for(int j=1; j<=n; j++){

                if(i==1 || i==n ||j==1 || j==n){
                    System.out.print("*");
                }else{
                    System.out.print(" ");
                }


            }

            System.out.println();
        }
    }
    public static void main(String[] args) {
        hollow_rombus(10);
        
    }
}
