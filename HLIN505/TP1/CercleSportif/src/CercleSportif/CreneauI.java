package CercleSportif;

public class CreneauI {
	private Lieu lieu;
	private Jour jour;
	private HeureSimple hDeb;
	private HeureSimple hFin;
	
	public static class HeureSimple {
		private static int granularite = 5;
		private static int heureMax = 22;
		private static int heureMin = 7;
		private int heure;
		private int minute;
		
		public int getHeure() {
			return heure;
		}
		public void setHeure(int heure) {
			this.heure = heure;
		}
		public int getMinute() {
			return minute;
		}
		public void setMinute(int minute) {
			this.minute = minute;
		}
		public boolean heureCorrecte(int h){
			return (h>heureMin && h<heureMax);
		}
		public boolean minuteCorrecte(int m){
			return (m<60 && m%granularite==0);	
					}
		public boolean tempsCorrect(int h, int m){
			return (heureCorrecte(h) && minuteCorrecte(m));	
					}
		public HeureSimple(int heure, int minute) {
			this.heure=heure;
			this.minute=minute;
		}
		
		public boolean estStrictementAvant(HeureSimple h) {
			boolean res=false;
			if(heure<h.getHeure()) {
				res=true;
			}
			else if(heure==h.getHeure()) {
				if(minute<h.getMinute()) {
					res=true;
				}
			}
			return res;
		}
		
		public String toString(){
			String h=Integer.toString(heure);
			String m=Integer.toString(minute);
			if(tempsCorrect(heure,minute)) {
				if(heure<10) h="0"+h;
				if(minute<10) m="0"+m;
			return h+":"+m;
			}
			else {
				return "ERROR";
			}
		}
	}

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
	public CreneauI(Lieu lieu, Jour jour, HeureSimple hDeb, HeureSimple hFin) {
		this.lieu=lieu;
		this.jour=jour;
		this.hDeb=hDeb;
		this.hFin=hFin;
	}
	

	
	public boolean chevauche(CreneauI c) {
		boolean res=false;
		if(jour==c.jour && lieu==c.lieu) {
			if((c.hDeb.estStrictementAvant(hDeb) && hDeb.estStrictementAvant(c.hFin)) || (hDeb.estStrictementAvant(c.hDeb) && hFin.estStrictementAvant(c.hFin))) {
				res = true;
			}
		}
		return res;
	}
	
	public boolean estInclusDans(CreneauI c) {
		boolean res=false;
		if(jour==c.jour && lieu==c.lieu) {
			if(c.hDeb.estStrictementAvant(hDeb) && (hFin.estStrictementAvant(c.hFin))){
				res=true;
			}
		}
		return res;
	}

}
