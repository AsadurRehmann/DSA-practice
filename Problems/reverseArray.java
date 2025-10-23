import java.util.*;

public class reverseArray {
    
    public static int[] reverse(int arr[]){
        int start=0,last=arr.length-1;

        while(start< last){
            int temp=arr[last];
                arr[last]=arr[start];
                arr[start]=temp;
                start++;
                last--;
        }
        return arr;
    }
    public static void main(String[] args) {
        int arr[] = {1,2,3,4,5,6,7,8,9,10,11};
        System.out.println("reversed array: " + Arrays.toString(reverse(arr)));
    }
}
