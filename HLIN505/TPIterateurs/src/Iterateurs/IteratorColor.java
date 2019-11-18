package Iterateurs;
import java.awt.Color;
import java.util.*;

public class IteratorColor implements Iterator<Color> {
	private Color[] tabColor;
	private int curseur =0;
	
	public IteratorColor(Color[] tabColor){
		this.tabColor=tabColor;
	}
	
	public boolean hasNext(){
		return true;
	}
	
	public Color next(){
		curseur++;
		if(curseur==3){
			curseur=0;
		}
		return tabColor[curseur];
	}
	
	public void remove() {
		throw new UnsupportedOperationException();
	}
}
