package Exercice1;

public class TestException3 {

	public void f3 ( ) throws Exc3 {
	System.out.println  ( " debut f3 " ) ;
	try {
		f4 ( ) ;
		}
	catch ( Exc31 e ) {System.out.println  ( e. getClass( ). getName ( ) ) ; }
	finally {System.out.println  ( " finally f3 " ) ; }
	
	System.out.println  ( " suite f3 " ) ;
	}

public void f4 ( ) throws Exc3 {
	System.out.println  ( " debut  f4 " ) ;
	try {
		f5 ( ) ;
		}
	catch ( Exc321 e ){ System.out.println  ( e.getClass ( ). getName ( ) ) ; }
	catch ( Exc32 e ){ System.out.println  ( e.getClass ( ). getName ( ) ) ; }
	finally { System.out.println  ( " finally f4 " ) ; }

	System.out.println  ( " suite f4 " ) ;
}

public void f5 ( ) throws Exc3 {
	System.out.println  ( " debut  f5 " ) ;
	Exc3 e = new  Exc321();
	throw e ;
	}

public static void main ( String [ ] args ) throws Exc3 {
	TestException3 t= new TestException3 ( ) ;
	t.f3 ( ) ;


/* 
 
 
 //cas Exc3 e = new  Exc3();
 
debut  f5 
 finally f4 
 finally f3 
Exception in thread "main" Exercice1.Exc3



// Cas Exc3 e = new  Exc31();

ddebut f3 
 debut  f4 
 debut  f5 
 finally f4 
Exercice1.Exc31
 finally f3 
 suite f3
 
// Cas Exc3 e = new  Exc311();
  debut f3 
 debut  f4 
 debut  f5 
 finally f4 
Exercice1.Exc311
 finally f3 
 suite f3 
 
 // Cas Exc3 e = new  Exc32();
  debut f3 
 debut  f4 
 debut  f5 
Exercice1.Exc32
 finally f4 
 suite f4 
 finally f3 
 suite f3 
 
 // Cas Exc3 e = new  Exc321();
  debut f3 
 debut  f4 
 debut  f5 
Exercice1.Exc321
 finally f4 
 suite f4 
 finally f3 
 suite f3 

*/
}
}

