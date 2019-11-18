package FeuilleSalaire;
import java.util.Iterator;


public class FeuilleSalaire implements Iterable<Object>{
	private String employeur;
	private String salarie;
	private String convcollec;
	private int nbHPayees;
	private int prelevFisc;
	private int netAPayer;
	
	public FeuilleSalaire(){}
	
	public FeuilleSalaire(String employeur,String salarie,String convcollec, int nbHPayees,int prelevFisc,int netAPayer){
		this.employeur=employeur;
		this.salarie=salarie;
		this.convcollec=convcollec;
		this.nbHPayees=nbHPayees;
		this.prelevFisc=prelevFisc;
		this.netAPayer=netAPayer;
	}
	
	public IteratorFeuilleSalaire iterator(){
		return new IteratorFeuilleSalaire(this.employeur,this.salarie,this.convcollec,this.nbHPayees,this.prelevFisc,this.netAPayer);
	}
	
	@Override
	public String toString() {
		return "FeuilleSalaire [employeur=" + employeur + ", salarie=" + salarie + ", convcollec=" + convcollec
				+ ", nbHPayees=" + nbHPayees + ", prelevFisc=" + prelevFisc + ", netAPayer=" + netAPayer + "]";
	}
}
