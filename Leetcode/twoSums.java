import java.util.Arrays;

public class twoSums {

    public int[] Sums(int[] nums,int target){

        for(int i=0; i<=nums.length; i++){
            for(int j=i+1; j<nums.length; j++){
                if(nums[i]+nums[j] == target){
                    return new int[] {i,j};
                }
            }    
        }
        return new int[] {};
        
    }

    public static void main(String[] args) {
        
        int[] nums={3,3};
        int target=6;

        twoSums s1=new twoSums();
        
       int[] results = s1.Sums(nums, target);
        System.out.println(Arrays.toString(results));

    
    }
}
