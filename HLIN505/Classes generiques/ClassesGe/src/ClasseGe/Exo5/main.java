package ClasseGe.Exo5;

public class main {
public static void main(String[] args) {
		
		CoupleConventionnel<Dauphin, Vache> cc = new CoupleConventionnel<>(new Dauphin(), new Vache());
		System.out.println(cc);
		CoupleEspece<Taureau, Vache> ce = new CoupleEspece<>(new Taureau(), new Vache());
		System.out.println(ce);
		//CoupleFertile<Bovin, Vache> cf = new CoupleFertile(new Taureau(), new Vache());
		//System.out.println(cf);
	}
}
