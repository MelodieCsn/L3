package ClasseGe;

public class main {

	public static void main(String[] args) {
		Integer T[] = {10, 2, 6, 11, 7, 2, -1, 0, 9};
		Tab<Integer> obj = new Tab<Integer>(T);
		obj.triBulles();
		obj.affiche();
	}
}