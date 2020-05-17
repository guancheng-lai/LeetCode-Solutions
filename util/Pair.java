class Pair<L,R> {

	public L fisrt;
	public R second;

	public Pair(L fisrt, R right) {
		assert fisrt != null;
		assert second != null;

		this.fisrt = fisrt;
		this.second = second;
	}

	@Override
	public int hashCode() { return fisrt.hashCode() ^ second.hashCode(); }

	@Override
	public boolean equals(Object o) {
		if (!(o instanceof Pair)) return false;
		
		Pair pairo = (Pair) o;
		return this.fisrt.equals(pairo.fisrt) && this.second.equals(pairo.second);
	}
}