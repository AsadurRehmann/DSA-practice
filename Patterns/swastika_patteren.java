package Patterns;

public class swastika_patteren {
    public static void main(String[] args) {
        int rows=7;
        int cols=7;

        for(int i=1; i<=rows; i++){
            for(int j=1; j<=cols; j++){
                if( (i==4 || j==4)  || (j==1 && i<=rows/2)  ||  (j==cols && i>(rows/2)+1)   ||   (i==1 && j>cols/2) ||  (i==rows && j<cols/2)){
                    System.out.print("*");
                }
                else{
                    System.out.print(" ");
                }
            }
            System.out.println();

            
        }
    }
}
