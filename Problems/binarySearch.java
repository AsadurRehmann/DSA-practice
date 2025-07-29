public class binarySearch {
    
    public static int search(int numbers[],int key){
        int start=0,end=numbers.length-1;
        
        while (start<=end) {
            int middle=(start+end)/2;
            if(numbers[middle]==key){
                return middle;
            }
            if(numbers[middle]<key){
                start=middle+1;
            }
            if(numbers[middle]>key){
                end=middle-1;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        int numbers[]={2,4,6,8,10};
        int key=10;
        System.out.println("key:"+search(numbers,key));
    }
}
