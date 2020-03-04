#include<iostream>
using namespace std;
class C1

{

private:

virtual void f1(){cout << "f1 de C1"<<endl;}

public:

virtual void f2(){this->f1();}

virtual void f3(){cout << "f3 de C1"; this->f1();}

};

class C2 : protected virtual C1

{

public:

virtual void f1(){cout << "f1 de C2"<<endl;}

private:

virtual void f3(){cout << "f3 de C2"; this->f1();}

};


int main()

{

C2 *pc2=new C2();

cout << "cest pour C2" << endl;

pc2->f2();

pc2->f3();

}