package CercleSportif;

public class Adherent {
	private static int nbAdherents=0;
	private String nom;
	private boolean cotisationAquitee;
	private int numero;
	private int derniereAnneeCotisee;
	public int getDerniereAnneeCotisee() {
		return derniereAnneeCotisee;
	}
	public void setDerniereAnneeCotisee(int derniereAnneeCotisee) {
		this.derniereAnneeCotisee = derniereAnneeCotisee;
	}
	public int getNumero() {
		return numero;
	}
	public void setNumero(int numero) {
		this.numero = numero;
	}
	public boolean isCotisationAquitee() {
		return cotisationAquitee;
	}
	public void setCotisationAquitee(boolean cotisationAquitee) {
		this.cotisationAquitee = cotisationAquitee;
	}
	public String getNom() {
		return nom;
	}
	public void setNom(String nom) {
		this.nom = nom;
	}
	public static int getNbAdherents() {
		return nbAdherents;
	}
	public static void setNbAdherents(int nbAdherents) {
		Adherent.nbAdherents = nbAdherents;
	}
	public Adherent(String nom, boolean cotisationAquitee,int derniereAnneeCotisee) {
		nbAdherents=nbAdherents+1;
		this.numero=nbAdherents;
		this.nom=nom;
		this.cotisationAquitee=cotisationAquitee;
		this.derniereAnneeCotisee=derniereAnneeCotisee;
	}

}
