package ClasseGe;
import java.util.LinkedList;

public class CPile<A> implements IPile<A>{
	
	private LinkedList<A> pile;
	
	public CPile(){
		pile = new LinkedList<A>();
	}
	
	public boolean estvide(){
		return pile.isEmpty();
	}
	public void empile(A e){
		pile.add(e);
	}
	public A depile(){
		return pile.removeLast();
	}
	public int nbElements(){
		return pile.size();
	}
	public A sommet(){
		return pile.getLast();
	}
	
}
