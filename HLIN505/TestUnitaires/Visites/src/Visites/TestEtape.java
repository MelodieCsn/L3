package Visites;
import static org.junit.Assert.assertTrue;

import java.util.Arrays;
import java.util.Collection;

import org.junit.Before;
import org.junit.Test;
import org.junit.runners.Parameterized.Parameters;


public class TestEtape {
	
	private int dureeVisite;
	private NatureEtape type;
	private String nom;
	private String rue;
	
	Etape e1;
	Etape e2;
	
	@Parameters
	public static Collection data(){
		return Arrays.asList(new Object[][]{
			{"polonaise inversée","rue du langage formel", 5,NatureEtape.musee},
			{"polonaise pas ouf","rue de la Pologne", 0,NatureEtape.lieuInteretSansVisite}
		});
	}
	
	public TestEtape(String nom, String rue, int dureeVisite, NatureEtape type) {
		this.nom=nom;
		this.rue=rue;
		this.dureeVisite = dureeVisite;
		this.type = type;
	}
	
	@Before
	public void setUp() throws Exception{
		e1 = new Etape("polonaise inversée","rue du langage formel", 5,NatureEtape.musee);
		e2 = new Etape("polonaise pas ouf","rue de la Pologne", 0,NatureEtape.lieuInteretSansVisite);
	}
	
	@Test
	public void TestEtapeCorrecte(){
		assertTrue(e1.estCorrecte());
		assertTrue(e2.estCorrecte());
		
	}

}
