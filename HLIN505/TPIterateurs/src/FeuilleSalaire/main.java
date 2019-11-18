package FeuilleSalaire;

import java.awt.Color;
import java.util.Iterator;

public class main {
	public static void main(String[] args) {
		FeuilleSalaire FS1= new FeuilleSalaire("Prunelle","Gaston","Spirou",10,5,50);
		Iterator<Object> it= FS1.iterator();
		XDWèèèèèèèèèèèèèèèèèèèèèèèèèèèèèèèèèèèèèèèèèèèè
		
//		for(int i=0; i<10;i++){
//			System.out.println(it.next());
//		}
		FeuilleSalaire FS2= new FeuilleSalaire("Prunelle","Gaston","Spirou",10,5,50);
		FeuilleSalaire FS3= new FeuilleSalaire("Prunelle","Gaston","Spirou",10,5,50);
		FeuilleSalaire FS4= new FeuilleSalaire("Prunelle","Gaston","Spirou",10,5,50);

		CollectionFeuillesSalaire l=new CollectionFeuillesSalaire(FS1,FS2,FS3);
		l.print();
	}
}
