import java.util.Scanner;

public class stringSearch {
    
    public static void search(String names[],String input){

        int a=0;
        while(a<names.length){
            if(names[a].trim().toLowerCase().equals(input)){
                
                System.out.println("Found at index:"+a);
                break;
                
            }
            a++;
            
        }
        
    }

    public static void main(String[] args) {
        String names[] = {"Asad","Zain","Faisal","Umer","Numan"};
       
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter:");
        String input=sc.nextLine().trim().toLowerCase();
        search(names, input);
        sc.close();
        
    }
}
