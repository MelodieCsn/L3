package Iterateurs;

import java.awt.Color;
import java.util.Iterator;

public class main {
	public static void main(String[] args) {
		FeuTricolore F = new FeuTricolore();
		Iterator<Color> it= F.iterator();
		
		for(int i=0; i<10;i++){
			System.out.println(it.next());
		}
	}

}
