class Solution {
    public boolean hasDuplicate(int[] nums) {
        Set seen = new HashSet();
        for (int num: nums) {
            if (seen.contains(num)) {
                return true;
            }
            seen.add(num);
        }

        return false;
    }
}