class Trie {

	Trie[] data;
	
	/** Initialize your data structure here. */
	public Trie() {
		data = new Trie[27];
	}
	
	/** Inserts a word into the trie. */
	public void insert(String word) {
		if (word.length() == 0) {
			data[26] = new Trie();
			return;
		}
		
		// System.out.println(c);
		int idx = word.charAt(0) - 'a';
		if (data[idx] == null) {
			data[idx] = new Trie();
		}
		
		data[idx].insert(word.substring(1));
	}
	
	/** Returns if the word is in the trie. */
	public boolean search(String word) {
		if (word.length() == 0) return data[26] != null;
		int idx = word.charAt(0) - 'a';
		if (data[idx] == null) return false;
		return data[idx].search(word.substring(1));
	}
	
	/** Returns if there is any word in the trie that starts with the given prefix. */
	public boolean startsWith(String prefix) {
		if (prefix.length() == 0) return true; 
		int idx = prefix.charAt(0) - 'a';
		if (data[idx] == null) return false;
		return data[idx].startsWith(prefix.substring(1));
	}
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */