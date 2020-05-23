import java.util.Map.*;

class Solution {
	public String frequencySort(String s) {
		HashMap<Character, Integer> m = new HashMap<>();
		for (char c : s.toCharArray()) {
			m.put(c, m.getOrDefault(c,0) + 1);
		}
		
		List<Entry<Character, Integer>> list = new LinkedList<Entry<Character, Integer>>(m.entrySet());

		// Sorting the list based on values
		Collections.sort(list, new Comparator<Entry<Character, Integer>>() {
			public int compare(Entry<Character, Integer> o1, Entry<Character, Integer> o2) {
				 return o2.getValue().compareTo(o1.getValue());
			}
		});
		
		StringBuilder sb = new StringBuilder();
		
		for(Entry<Character, Integer> e : list) {  
			int times = (int)e.getValue();
			for (int i = 0; i < times; ++i) {
				sb.append( e.getKey() );
			}
		}   
		
		return sb.toString();
	}
}