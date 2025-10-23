public class binarySearch {
    
    public static int search(int numbers[],int key){
        int start=0,end=numbers.length-1,result=-1;
        
        while (start<=end) {
            int middle=(start+end)/2;

            if(numbers[middle]==key){
                result=middle;
                end=middle-1;
            }
            if(numbers[middle]<key){
                start=middle+1;
            }
            if(numbers[middle]>key){
                end=middle-1;
            }
        }
        return result;
    }

    public static void main(String[] args) {
        int numbers[]={2,4,4,4,10};
        int key=4;
        System.out.println("First or only occurence of the key:"+search(numbers,key));
    }
}
