package CercleSportif;

public enum Jour {
	Lu("Lundi"),
	Ma("Mardi"),
	Me("Mercredi"),
	Je("Jeudi"),
	Ve("Vendredi"),
	Sa("Samedi"),
	Di("Dimanche");
	private String nom;
	private Jour(String nom) {
		this.nom=nom;
	}
	
	public String toString() {
		return nom;
	}

}
