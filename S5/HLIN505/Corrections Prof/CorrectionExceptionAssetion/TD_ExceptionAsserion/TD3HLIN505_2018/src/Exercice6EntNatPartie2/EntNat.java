package Exercice6EntNatPartie2;

public class EntNat {
	
	private int nombre;
	
	public EntNat() {
		nombre = 0;
	}
	
	public EntNat(int nb) throws ErrConst {
		if(nb < 0) throw new ErrConst(nb);
		nombre = nb;
	}
	
	public int getNombre() {
		return nombre;
	}
	
	public void setNombre(int nb) throws ErrModif {
		if(nb < 0) throw new ErrModif(nb);
		nombre = nb;
	}
	
	public int incremente() {
		return ++nombre;
	}
	
	public int decremente() throws ErrModif {
		if(nombre == 0) throw new ErrModif(nombre-1);
		return --nombre;
	}
	
	public static EntNat decremente(EntNat e) throws ErrModif,ErrConst {
		if(e.nombre == 0 ) throw new ErrModif(e.getNombre()-1);
		e.setNombre(e.getNombre()-1);
		return e;
	}
	
	public static void main(String[] args) {
		try {
			EntNat e1 = new EntNat(1);
			System.out.println(e1.decremente());
			System.out.println(e1.decremente());
		}
		catch(ErrConst ec) {
			System.err.println("Exception levée avec le nombre : "+ec.getNombreExcep());
			ec.printStackTrace();
		}
		catch(ErrModif em) {
			System.err.println("Exception levée avec le nombre : "+em.getNombreExcep());
			em.printStackTrace();
		}		
	}
}

