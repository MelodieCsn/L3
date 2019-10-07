package Expressions;

public class Constante extends Nombre{
	private double nb;
	
	public Constante(double nb){
		this.nb=nb;
	}
	public String toString(){
		return nb+"";
	}
	
	public double getNb() {
		return nb;
	}
	public void setNb(double nb) {
		this.nb = nb;
	}
	
	public double eval(){
		return nb;
	}

}
