package Patterns;
public class starPattern {
    public static void main(String[] args) {
        
        // for(int i=0; i<=4; i++){
        //     for(int j=0; j<=i; j++){
        //         System.out.print("*");
        //     }
        //     System.out.println();
        // }

         for(int i=0; i<=4; i++){
            
            for(int j=0; j<=i; j++){
                if (i>0) {
                    System.out.println("*");
                }
                System.out.print("*");
                
                
                // System.out.println();
            }
            
        }

    }
}
