package Exercice1;

import java.io.IOException;

public class TestException2 {
	
	public void f1 ( ) { throw new Exc1 ( ) ; }
	public void f2 ( ) throws IOException { throw new Exc2 ( ) ; }
	
	public void f3 ( ) { try {
		throw new Exc2 ( ) ;
	} catch (Exc2 e) {
		// TODO Auto-generated catch block
		e.printStackTrace();
	} }

}