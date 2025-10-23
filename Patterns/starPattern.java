package Patterns;

public class starPattern{

    public static void main(String[] args) {
        int input=4;
        //  1 
        for(int i=0; i<input; i++){

                //right-side spaces 
                for(int rs=1; rs<=input; rs++){
                    System.out.print(" ");
                }
                
                //upper-side pyramid
                for(int j=1; j<input-i; j++){
                    System.out.print(" ");
                }

                for(int k=1; k<=(2*i)+1; k++){
                    System.out.print("*");
                }
                System.out.println();

        }
        //  2
        for(int i=1; i<=input; i++){
            //spaces
            for(int rs=1; rs<=input-i; rs++){
                System.out.print(" ");
            }

            // stars
            for(int j=1; j<=i; j++){
                System.out.print("*");
            }

            //right side

           //spaces
            for(int j=1; j<=7; j++ ){
                System.out.print(" ");
            }
            
            //stars
            for(int k=1; k<=i; k++){
                System.out.print("*");
            }
            System.out.println();


        }


        //inverted
        for(int i=input-1; i>0; i--){
            //spaces
            for(int rs=1; rs<=input-i; rs++){
                System.out.print(" ");
            }

            // stars
            for(int j=1; j<=i; j++){
                System.out.print("*");
            }

            for(int r7spaces=1; r7spaces<=7; r7spaces++){
                System.out.print(" ");
            }

            for(int rstars=1; rstars<=i; rstars++){
                System.out.print("*");
            }
            System.out.println();

        }



        //  3
        int exspaces=0;
        for(int i=input; i>0; i--){

            for(int spaces=1; spaces<=input; spaces++){
                System.out.print(" ");
            }

            for(int pyspaces=0; pyspaces<exspaces; pyspaces++){
                System.out.print(" ");
            }

            for(int k=1; k<=(2*i)-1; k++){
                System.out.print("*");
            }


                System.out.println();
                exspaces+=1;
        }


    }
}