package Expressions;

public class ExpressionComplexe extends Nombre{
	private Nombre a;
	private char op;
	private Nombre b;
	
	public ExpressionComplexe(Constante a, char op, Constante b){
		this.a=a;
		this.b=b;
		this.op=op;
	}
	
	public String toString(){
		return a.toString()+op+b.toString();
	}
	public double eval(){
		double res = 0;
		switch (op) {
		case '+':
			res=a.eval()+b.eval();
			break;
		case '-':
			res=a.eval()-b.eval();
			break;
		case '*':
			res=a.eval()*b.eval();
			break;
		case '/':
			res=a.eval()/b.eval();
			break;

		default:
			break;
		}
		return res;
	}

}
