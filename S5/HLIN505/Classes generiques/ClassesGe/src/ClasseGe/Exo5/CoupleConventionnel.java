package ClasseGe.Exo5;

public class CoupleConventionnel <A extends Mâle, B extends Femelle> extends Paire<A, B> {

	public CoupleConventionnel() {
		super();
	}

	public CoupleConventionnel(A a, B b) {
		super(a, b);
	}

}
