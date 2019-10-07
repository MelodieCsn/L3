package CercleSportif;

public class Creneau {
	
	private Lieu lieu;
	private Jour jour;
	private HeureSimple hDeb;
	private HeureSimple hFin;

	public HeureSimple gethDeb() {
		return hDeb;
	}

	public void sethDeb(HeureSimple hDeb) {
		this.hDeb = hDeb;
	}

	public HeureSimple gethFin() {
		return hFin;
	}

	public void sethFin(HeureSimple hFin) {
		this.hFin = hFin;
	}

	public Jour getJ() {
		return jour;
	}

	public void setJ(Jour j) {
		this.jour = j;
	}

	public Lieu getL() {
		return lieu;
	}

	public void setL(Lieu l) {
		this.lieu = l;
	}
	public String toString() {
		return jour.toString()+" "+hDeb.toString()+" - "+hFin.toString();
	}
	public Creneau(Lieu lieu, Jour jour, HeureSimple hDeb, HeureSimple hFin) {
		this.lieu=lieu;
		this.jour=jour;
		this.hDeb=hDeb;
		this.hFin=hFin;
	}
	

	
	public boolean chevauche(Creneau c) {
		boolean res=false;
		if(jour==c.jour && lieu==c.lieu) {
			if((c.hDeb.estStrictementAvant(hDeb) && hDeb.estStrictementAvant(c.hFin)) || (hDeb.estStrictementAvant(c.hDeb) && hFin.estStrictementAvant(c.hFin))) {
				res = true;
			}
		}
		return res;
	}
	
	public boolean estInclusDans(Creneau c) {
		boolean res=false;
		if(jour==c.jour && lieu==c.lieu) {
			if(c.hDeb.estStrictementAvant(hDeb) && (hFin.estStrictementAvant(c.hFin))){
				res=true;
			}
		}
		return res;
	}
	
	
	
	
}
