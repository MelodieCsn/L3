package ClasseGe;

public class FileAttentePrio<A extends ElementAvecPriorite> extends FileAttente<A> {

	public FileAttentePrio(){
		super();
	}

	public A sort(){
		A a=null;
		if(!contenu.isEmpty()) {
			a=lePlusPrio();
			contenu.remove(a);
		}
		return a;
	}
	
	private A lePlusPrio(){
		A a=null;
		int priorite= Integer.MAX_VALUE;
		for(A e : contenu){
			if(e.priorite()<priorite){
				priorite=e.priorite();
				a=e;
			}
		}
		return a;
	}
}

