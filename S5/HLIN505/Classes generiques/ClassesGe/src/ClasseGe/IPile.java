package ClasseGe;

public interface IPile<A> {
	boolean estvide();
	void empile(A a);
	A depile();
	int nbElements();
	A sommet();
}
