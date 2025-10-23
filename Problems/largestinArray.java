
public class largestinArray {
    
    public static int largest(int nums[]){
        int key=Integer.MIN_VALUE;
        for(int i=0; i<nums.length; i++){

            if(key<nums[i]){
                key=nums[i];
            }
        }
        return key;
    }
    
    public static void main(String[] args) {
        int nums[]= new int[200000000];
        for (int i=0; i<nums.length; i++){
            nums[i]=i+1;
        }
        System.out.println("Largest number is "+largest(nums));
    }
}
