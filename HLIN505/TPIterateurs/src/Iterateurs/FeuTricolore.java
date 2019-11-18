package Iterateurs;
import java.awt.Color;
import java.util.*;


public class FeuTricolore implements Iterable<Color>{
	
	private Color[] tabColor = {Color.red, Color.orange, Color.green};
	
	public FeuTricolore(){}
	
	public Iterator<Color> iterator(){
		return new IteratorColor(tabColor);
	}
	
	
}
