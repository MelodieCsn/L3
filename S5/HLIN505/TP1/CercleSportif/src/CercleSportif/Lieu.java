package CercleSportif;
import java.util.*;

public enum Lieu {
	Piscine("piscine olympique"),
	SalleDeSport1("salle de danse"),
	SalleDeSport2("salle de musculation"),
	Stade("stade d'athlétisme");
	
	private String nom;

	private Lieu(String nom) {
		this.nom= nom;
	}
	
	private ArrayList<Creneau> creneauDispo = new ArrayList<Creneau>();
	
	public void ajoutCreneau(Creneau c) {
		creneauDispo.add(c);
	}
	public boolean estDispoPendant(Creneau c) {
		boolean res=true;
		for (Creneau cr:creneauDispo){
			if(c.estInclusDans(cr)) res=false;
		}
		return res;
	}
}
