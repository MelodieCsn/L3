package Exercice6EntNatPartie2;

public class ErrNat extends Exception {

	private static final long serialVersionUID = 1L;

	private int nombre;
	
	public ErrNat(int nb) {
		nombre = nb;
	}
	
	public int getNombreExcep() {
		return nombre;
	}		
}

