package Exercice6EntNat;

public class EntNat {
	
	private int nombre;
	
	public EntNat() {
		nombre = 0;
	}
	
	public EntNat(int nb) throws ErrConst {
		if(nb < 0) throw new ErrConst();
		nombre = nb;
	}
	
	public int getNombre() {
		return nombre;
	}
	
	public void setNombre(int nb) throws ErrModif {
		if(nb < 0) throw new ErrModif();
		nombre = nb;
	}
	
	public int incremente() {
		return ++nombre;
	}
	
	public int decremente() throws ErrModif {
		if(nombre == 0) throw new ErrModif();
		return --nombre;
	}
	
	public static EntNat decremente(EntNat e) throws ErrModif,ErrConst {
		if(e.nombre == 0 ) throw new ErrModif();
		e.setNombre(e.getNombre()-1);
		return e;
	}
	
	public static void main(String[] args) {
		try {
			EntNat e1 = new EntNat(-4);
			
			System.out.println(e1.decremente());
		}
		catch(ErrConst ec) {
			ec.printStackTrace();
		}
		catch(ErrModif em) {
			em.printStackTrace();
		}		
	}
}
