package tableau;

public class Main {

	public static void main(String[] args) {
		int T[] = {10, 2, 6, 11, 7, 2, -1, 0, 9};
		Tableau obj = new Tableau(T);
		obj.triBulles();
		obj.affiche();
	}
}
