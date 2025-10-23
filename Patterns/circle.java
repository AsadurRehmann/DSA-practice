package Patterns;

public class circle {
    public static void main(String[] args) {
        int radius=50;
        double dist;

        for(int i=0; i<2*radius; i++){
            for(int j=0; j<=radius*2; j++){

                dist=Math.sqrt((i-radius)*(i-radius)+(j-radius)*(j-radius));

                if(dist>radius-0.5 && dist<radius+0.5){
                    System.out.print("*");
                }else{
                    System.out.print(" ");
                }
            }
            System.out.println();
        }
    }
}
