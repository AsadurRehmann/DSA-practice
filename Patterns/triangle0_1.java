package Patterns;
public class triangle0_1 {
    public static void main(String[] args) {
        for(int i=0; i<=4; i++){
            for(int j=0; j<=i; j++){
                if((i+j)%2==0){
                    System.out.print("0");
                }
                if((i+j)%2!=0){
                    System.out.print("1");
                }
            }
            System.out.println();
        }
    }
}
