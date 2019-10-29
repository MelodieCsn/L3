package Exercice1;

public class TestException {
	
	public void f1 ( ) { throw new Exc1 ( ) ; }
	public void f2 ( ) { try {
		throw new Exc2 ( ) ;
	} catch (Exc2 e) {
		// TODO Auto-generated catch block
		e.printStackTrace();
	} }

}
