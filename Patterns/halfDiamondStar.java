package Patterns;

public class halfDiamondStar {
    public static void main(String[] args) {
        int n=6;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
             System.out.print("*");
        }
       System.out.println();
    }

    for(int i=n-1; i>=1; i--){
        for(int j=1; j<=i; j++){
            System.out.print("*");
        }
        System.out.println();
    }


        
        // for(int k=n-1; k>=1; k--){
        //     System.out.print("*");
        // }
        // System.out.println();
     
 }

}
