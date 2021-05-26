
#include"Include.h"
#include"Vector.h"
void main() 
{
	Vector<double> Vec;

	Vec.Push(1.2);
	Vec.Push(2.5);
	Vec.Push(3.0);
	Vec.Push(4);
	Vec.Push(5.5);
	Vec.Push(6.6);
	Vec.PrintAll();
	Vec.Insert(2, 99.0);
	//Vec.Insert(4, 88);
	Vec.PrintAll();
	Vec.Remove(2);
	Vec.PrintAll();
	/*
	Vec.Pop();
	Vec.Pop();
	Vec.Pop();
	Vec.Pop();
	Vec.Pop();
	Vec.Pop();
	*/
}