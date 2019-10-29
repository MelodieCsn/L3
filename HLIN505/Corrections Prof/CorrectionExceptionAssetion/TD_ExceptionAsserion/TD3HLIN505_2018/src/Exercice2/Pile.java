package Exercice2;

	public class Pile { 
		private static final int TAILLE_MAX = 2;// taille maximum de la pile 
		private int t[]; // tableau stockant les elements de la pile 
		private int nb; // nombre d'elements dans la pile 
		public Pile() { 
			t = new int[TAILLE_MAX]; 
			nb = 0; 
		} 
		public boolean pileVide() {
			return nb == 0;
		} 
		
		public void empiler(int i) throws PilePleineException {
			if (nb == TAILLE_MAX) throw new PilePleineException(); 
			t[nb] = i; 
			nb++; 
			System.out.println("sortie de empiler"); 
		} 
		public int sommet() throws PileVideException { 
			if (nb == 0) throw new PileVideException(); 
			System.out.println("sortie de sommet"); 
			return t[nb-1]; 
		} 
		public void depiler() throws PileVideException { 
			if (nb == 0) throw new PileVideException(); 
			nb--; 
			System.out.println("sortie de dépiler"); 
		} 
		public void depilerTout() throws PileVideException { 
			if(pileVide()) throw new PileVideException();		
			while(!pileVide()) { 
				System.out.println(sommet()); 
				depiler(); 
			}
	        System.out.println("sortie du dépilerTout"); 
		} 
		
		public static void main(String[] args) { 
			Pile p = new Pile(); 
			try { 
				p.empiler(2); 
				p.empiler(4); 
				p.depilerTout(); 
				System.out.println(p.sommet()); 
			} 
			catch (PileVideException e) {
				System.out.println("Le main pense que la pile est vide");
			} 
			catch (PilePleineException e) {
				System.out.println("Le main pense que la pile est pleine");
			} 
			catch (Exception e) {
				System.out.println("Le main est passé par là");
			} 
			System.out.println("sortie du main"); 
		} 
		
	}
	
	/*
	 
	 //TAILLE_MAX = 0
	 Le main pense que la pile est pleine
     sortie du main
     
    //TAILLE_MAX = 1
    sortie de empiler
	Le main pense que la pile est pleine
	sortie du main
	
	
 //TAILLE_MAX = 1
sortie de empiler
sortie de empiler
sortie de sommet
4
sortie de dépiler
sortie de sommet
2
sortie de dépiler
sortie du dépilerTout
Le main pense que la pile est vide
sortie du main
	 
	 */
	