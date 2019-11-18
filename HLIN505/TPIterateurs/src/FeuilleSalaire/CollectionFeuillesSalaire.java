package FeuilleSalaire;
import java.util.ArrayList;
import java.util.Iterator;


public class CollectionFeuillesSalaire {

		private ArrayList<FeuilleSalaire> list;
		private int curseur =0;
		
		public CollectionFeuillesSalaire(FeuilleSalaire f1,FeuilleSalaire f2,FeuilleSalaire f3){
			list.add(f1);
			list.add(f2);
			list.add(f3);
		}
		
		public void print(){
			list.stream().forEach(l -> System.out.println(l.toString()));
		}

}


