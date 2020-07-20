import java.util.*;
class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        
        Map<String, List<String>> map = new HashMap<>();
        
        for(String s:strs) {
            char array[] = s.toCharArray();
            Arrays.sort(array);
            String sorted = new String(array);
            
            if(!map.containsKey(sorted)) {
                map.put(sorted, new LinkedList<String>());
            }
            map.get(sorted).add(s);
        }
        
        return new LinkedList<>(map.values());
        
    }
}