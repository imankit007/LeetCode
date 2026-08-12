class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {

        int[] arr = new int[26];
        
        for (int i = 0; i < magazine.length(); i++) {
            char c = magazine.charAt(i);
            arr[c - 'a']++;
        }
        
        for (int i = 0; i < ransomNote.length(); i++) {
            char c = ransomNote.charAt(i);
            arr[c - 'a']--;
            if (arr[c - 'a'] < 0) {
                return false;
            }
        }
        return true;
        
    }
}