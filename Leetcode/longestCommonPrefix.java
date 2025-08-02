public class longestCommonPrefix {
    public static String commonPrefix(String strs[]) {

        String result = "";

        for (int i = 0; i < strs[0].length(); i++) {
            char first = strs[0].charAt(i);

            for (int j = 0; j < strs.length; j++) {

                if (i >= strs[j].length() || first != strs[j].charAt(i)) {
                    return result;
                }

            }
            result += first;
        }
        return result;

    }

    public static void main(String[] args) {
        String strs[] = { "dog", "racecar", "car" };

        System.out.println(commonPrefix(strs));
        commonPrefix(strs);
    }
}
