package FabriquePersos;

public abstract class Personnage {
	private String nom;
	private int nbPts;
	private int nbVies;
	
	public String getNom() {
		return nom;
	}
	public void setNom(String nom) {
		this.nom = nom;
	}
	public int getNbPts() {
		return nbPts;
	}
	public void setNbPts(int nbPts) {
		this.nbPts = nbPts;
	}
	public int getNbVies() {
		return nbVies;
	}
	public void setNbVies(int nbVies) {
		this.nbVies = nbVies;
	}
	
	public Personnage(String nom,int nbPts,int nbVies){
		this.nom=nom;
		this.nbPts=nbPts;
		this.nbVies=nbVies;
	}
	
	

}