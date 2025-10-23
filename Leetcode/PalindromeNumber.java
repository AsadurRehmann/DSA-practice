public class PalindromeNumber {
    public boolean isPalindrome(int x){
        int input=x;
        int reversed=0;
        if(x<0){
            return false;
        }

        String store = "";
        while (x != 0) {
            int last = x % 10;
            if (reversed > Integer.MAX_VALUE / 10 || reversed < Integer.MIN_VALUE / 10) {
                return false; // Return 0 if it goes out of bounds
            }
            reversed = reversed * 10 + last;
            
            x = x / 10;
        }
        if(input==reversed)
        return true;
        
        return false;
    }

    public static void main(String[] args) {
        PalindromeNumber s1=new PalindromeNumber();
        System.out.println(s1.isPalindrome(105));
    }
}
