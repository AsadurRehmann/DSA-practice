package Patterns;
public class halfPyramid {
    public static void main(String[] args) {
        int a=1;
        for(int i=0; i<=4; i++){
            for(int j=0; j<=i; j++){
                System.out.print(a);
                a++;
            }
            a=1;
            System.out.println();
        }
    }
}
