package FeuilleSalaire;

import java.util.ArrayList;
import java.util.Iterator;

public class IteratorFeuilleSalaire implements Iterator<Object> {
//	private String employeur;
//	private String salarie;
//	private String convcollec;
//	private int nbHPayees;
//	private int prelevFisc;
//	private int netAPayer;
	
	private ArrayList<Object> listeFeuilles=new ArrayList<Object>();
	
	
	
	private int curseur=0;
	
	public IteratorFeuilleSalaire(){}
	
	public IteratorFeuilleSalaire(String employeur,String salarie,String convcollec, int nbHPayees,int prelevFisc,int netAPayer){
		
		listeFeuilles.add(employeur);
		listeFeuilles.add(salarie);
		listeFeuilles.add(convcollec);
		listeFeuilles.add(nbHPayees);
		listeFeuilles.add(prelevFisc);
		listeFeuilles.add(netAPayer);
	}
	
	public boolean hasNext(){
		return curseur<6;
	}
	
	public Object next(){
		Object res = "";
		if(hasNext()){
			res=listeFeuilles.get(curseur);
		}
		curseur++;
		return res;
	}
	
	public void remove() {
		throw new UnsupportedOperationException();
	}

}
