#include <iostream>
#include <chrono>
#include <cmath>
#include <iomanip>
#include <ctime>


using namespace std;

using func_t = bool(*)(bool,bool,bool,bool,bool,bool,bool,bool);

//# -- - - Agregando funcion para bit 0 
bool f_s0(bool a3, bool a2, bool a1, bool a0, bool b3, bool b2, bool b1, bool b0) { 
	return a0  or  ( not b0  and   not b1  and   not b2  and   not b3); 
} 
//# -- - - Agregando funcion para bit 1 
bool f_s1(bool a3, bool a2, bool a1, bool a0, bool b3, bool b2, bool b1, bool b0) { 
	return a1  and  b0  and  (a0  or   not b1)  and  (a0  or   not b2)  and  (a0  or   not b3); 
}
//# -- - - Agregando funcion para bit 2 

bool f_s2(bool a3, bool a2, bool a1, bool a0, bool b3, bool b2, bool b1, bool b0) { 
	return (a1  or  b0)  and  (b0  or  b1)  and  (a0  or   not b2)  and  (a0  or   not b3)  and  (a2  or   not b0)  and  (b0  or   not a0)  and  (a0  or   not b0  or   not b1); 
} 
//# -- - - Agregando funcion para bit 3 

bool f_s3(bool a3, bool a2, bool a1, bool a0, bool b3, bool b2, bool b1, bool b0) { 
	return (a0  or  b0)  and  (a3  or  b1)  and  (b0  or  b1)  and  (a0  or   not b2)  and  (a0  or   not b3)  and  (a1  or  a2  or  a3)  and  (a1  or  a2  or  b0)  and  (a0  or  a1  or   not b1)  and  (b0  or   not a1  or   not a2)  and  (a3  or   not a0  or   not a1  or   not a2)  and  (a1  or   not a2  or   not a3  or   not b0  or   not b1)  and  (a2  or   not a0  or   not a1  or   not a3  or   not b0  or   not b1); 
 } 
//# -- - - Agregando funcion para bit 4 

bool f_s4(bool a3, bool a2, bool a1, bool a0, bool b3, bool b2, bool b1, bool b0) { 
	return (b1  or  b2)  and  (a0  or   not b3)  and  (a0  or  a2  or  b2)  and  (a1  or  a2  or  a3)  and  (a1  or  a2  or  b1)  and  (a0  or  a1  or   not b0)  and  (a0  or  a1  or   not b2)  and  (a2  or  a3  or  b0  or  b2)  and  (a0  or   not b0  or   not b2)  and  (a0  or  b0  or   not a1  or   not b1)  and  (a1  or  a3  or   not b1  or   not b2)  and  (b1  or   not a0  or   not a1  or   not a2)  and  ( not a0  or   not a1  or   not a2  or   not a3)  and  ( not a1  or   not a3  or   not b1  or   not b2)  and  (a2  or  a3  or   not b0  or   not b1  or   not b2)  and  (b0  or  b2  or   not a0  or   not a2  or   not a3)  and  (a1  or   not a2  or   not b0  or   not b1  or   not b2); 
 } 
//# -- - - Agregando funcion para bit 5 

bool f_s5(bool a3, bool a2, bool a1, bool a0, bool b3, bool b2, bool b1, bool b0) { 
	return (a0  or  a1)  and  (a0  or   not b3)  and  (a0  or  b0  or  b1)  and  (a1  or  a2  or  a3)  and  (a1  or  a2  or  b2)  and  (b1  or  b2  or  b3)  and  (a2  or  a3  or  b0  or  b3)  and  (a0  or   not b1  or   not b2)  and  (a2  or  a3  or  b3  or   not b1)  and  (a0  or  b0  or   not a2  or   not a3)  and  (b1  or  b2  or   not a1  or   not a2)  and  (a1  or  a3  or  b0  or  b3  or   not b1)  and  (a1  or  a3  or  b1  or   not b2  or   not b3)  and  (a1  or  b2  or  b3  or   not a3  or   not b0)  and  (a3  or  b2  or  b3  or   not a1  or   not b0)  and  (a2  or  b2  or   not a3  or   not b1  or   not b3)  and  (b1  or  b3  or   not a0  or   not a2  or   not a3)  and  (b1  or   not a0  or   not a1  or   not a2  or   not a3)  and  (a2  or  a3  or  b1  or   not b0  or   not b2  or   not b3)  and  (a1  or  b0  or   not a2  or   not a3  or   not b1  or   not b3)  and  (a2  or  b0  or   not a1  or   not a3  or   not b2  or   not b3)  and  (a3  or  b0  or   not a1  or   not a2  or   not b1  or   not b2)  and  (a3  or  b2  or   not a2  or   not b0  or   not b1  or   not b3)  and  (a1  or   not a2  or   not b0  or   not b1  or   not b2  or   not b3)  and  (a2  or  b3  or   not a0  or   not a1  or   not a3  or   not b0  or   not b2); 
 } 
//# -- - - Agregando funcion para bit 6 

bool f_s6(bool a3, bool a2, bool a1, bool a0, bool b3, bool b2, bool b1, bool b0) { 
	return (a0  or   not b3)  and  (a0  or  a2  or  b1)  and  (a0  or  b0  or  b1)  and  (a1  or  a2  or  a3)  and  (b1  or  b2  or  b3)  and  (a0  or  a1  or   not b2)  and  (a2  or  a3  or  b0  or  b2)  and  (a3  or  b0  or  b2  or  b3)  and  (a0  or  a1  or  a2  or   not b0)  and  (a2  or  b1  or  b3  or   not a3)  and  (a1  or  a2  or   not b1  or   not b3)  and  (a1  or  a3  or   not b0  or   not b2)  and  (b1  or  b2  or   not a2  or   not a3)  and  (a0  or   not b0  or   not b1  or   not b2)  and  (a1  or  b0  or  b1  or   not a2  or   not a3)  and  (a1  or  b0  or  b3  or   not a2  or   not b1)  and  (a2  or  a3  or  b3  or   not b0  or   not b1)  and  (a2  or  b1  or   not a1  or   not a3  or   not b0)  and  (a2  or  b1  or   not a1  or   not a3  or   not b2)  and  (a1  or   not a3  or   not b0  or   not b1  or   not b3)  and  (b2  or   not a0  or   not a2  or   not a3  or   not b0)  and  (b2  or   not a1  or   not a2  or   not a3  or   not b0)  and  (a2  or  b2  or  b3  or   not a0  or   not a1  or   not b0)  and  (a3  or  b0  or  b3  or   not a0  or   not a2  or   not b1)  and  (a3  or  b1  or  b3  or   not a0  or   not a2  or   not b0)  and  (a3  or   not a1  or   not a2  or   not b0  or   not b1  or   not b3)  and  (b0  or   not a0  or   not a1  or   not a3  or   not b1  or   not b2)  and  (a3  or  b0  or  b1  or   not a1  or   not a2  or   not b2  or   not b3); 
 } 
//# -- - - Agregando funcion para bit 7 

bool f_s7(bool a3, bool a2, bool a1, bool a0, bool b3, bool b2, bool b1, bool b0) { 
	return (a0  or   not b3)  and  (a0  or  a1  or  a2)  and  (a0  or  a3  or  b1)  and  (a1  or  a2  or  a3)  and  (a1  or  a3  or  b3)  and  (b1  or  b2  or  b3)  and  (a0  or  b0  or   not b2)  and  (a0  or  a2  or  a3  or  b2)  and  (a2  or  b0  or  b2  or  b3)  and  (a3  or  b0  or  b1  or  b3)  and  (a3  or  b0  or  b2  or  b3)  and  (a2  or  b1  or  b2  or   not a3)  and  (a1  or  b0  or  b1  or  b2  or   not a3)  and  (a1  or  b1  or  b3  or   not a2  or   not b0)  and  (a2  or  b0  or  b3  or   not a1  or   not a3)  and  (a3  or  b0  or  b1  or   not a2  or   not b2)  and  (a3  or  b1  or  b2  or   not a2  or   not b0)  and  (a1  or  b3  or   not b0  or   not b1  or   not b2)  and  (a2  or  b2  or   not a3  or   not b0  or   not b3)  and  (b2  or  b3  or   not a0  or   not a1  or   not b0)  and  (a3  or   not a1  or   not b1  or   not b2  or   not b3)  and  (b0  or   not a1  or   not a2  or   not b2  or   not b3)  and  (a1  or  a2  or  b0  or   not b1  or   not b2  or   not b3)  and  (a2  or  b1  or   not a0  or   not a1  or   not a3  or   not b0)  and  (a1  or   not a2  or   not a3  or   not b0  or   not b1  or   not b3)  and  (b0  or   not a1  or   not a2  or   not a3  or   not b1  or   not b3)  and  (b3  or   not a0  or   not a1  or   not a2  or   not a3  or   not b0); 
 } 
//# -- - - Agregando funcion para bit 8 

bool f_s8(bool a3, bool a2, bool a1, bool a0, bool b3, bool b2, bool b1, bool b0) { 
	return (a0  or  a1  or  a2)  and  (a1  or  a2  or  a3)  and  (a1  or  b2  or  b3)  and  (a2  or  a3  or  b3)  and  (b1  or  b2  or  b3)  and  (a0  or  a1  or   not b1)  and  (a0  or  a1  or   not b3)  and  (a0  or  b0  or   not b1)  and  (a0  or  b1  or   not b0)  and  (a0  or   not b1  or   not b3)  and  (a0  or   not b2  or   not b3)  and  (a0  or  b2  or  b3  or   not a2)  and  (a1  or  b1  or  b3  or   not b0)  and  (a0  or  a2  or   not b1  or   not b2)  and  (b0  or  b2  or   not a1  or   not b1)  and  (a2  or  a3  or  b1  or  b2  or   not b0)  and  (b0  or   not a1  or   not a3  or   not b1)  and  (a1  or  a2  or  b2  or   not b0  or   not b1)  and  (a3  or  b2  or   not a2  or   not b1  or   not b3)  and  (b0  or  b3  or   not a2  or   not a3  or   not b1)  and  (a1  or  a3  or  b0  or  b1  or   not a0  or   not b2)  and  (a1  or  b0  or  b1  or  b2  or   not a2  or   not a3)  and  (a3  or   not a1  or   not a2  or   not b2  or   not b3)  and  (b1  or   not a1  or   not a2  or   not a3  or   not b0)  and  (a2  or  b0  or  b1  or   not a3  or   not b2  or   not b3)  and  (a0  or  b0  or   not a1  or   not a2  or   not a3  or   not b2)  and  (a2  or  b1  or   not a1  or   not a3  or   not b2  or   not b3)  and  (a3  or  b0  or   not a0  or   not a1  or   not a2  or   not b3)  and  (a1  or   not a3  or   not b0  or   not b1  or   not b2  or   not b3)  and  (a3  or   not a0  or   not a1  or   not b0  or   not b1  or   not b2); 
 } 
//# -- - - Agregando funcion para bit 9 

bool f_s9(bool a3, bool a2, bool a1, bool a0, bool b3, bool b2, bool b1, bool b0) { 
	return (a1  or  a2  or  a3)  and  (b0  or  b2  or  b3)  and  (b1  or  b2  or  b3)  and  (a0  or  a1  or   not b2)  and  (a0  or  a1  or   not b3)  and  (a0  or  b0  or   not b3)  and  (a0  or  a2  or  a3  or  b3)  and  (a0  or   not b2  or   not b3)  and  (a1  or  b1  or  b2  or   not a2)  and  (a0  or  a3  or   not b0  or   not b1)  and  (a1  or  a3  or   not b1  or   not b2)  and  (a3  or  b3  or   not a0  or   not b0)  and  (b2  or  b3  or   not a0  or   not a2)  and  (a1  or  a2  or  b0  or  b1  or   not b2)  and  (a2  or  a3  or  b1  or  b2  or   not a0)  and  (a3  or  b0  or  b1  or  b3  or   not a1)  and  (a0  or  b0  or   not a2  or   not a3  or   not b1)  and  (a1  or  a2  or   not b0  or   not b1  or   not b3)  and  (a1  or  b0  or   not a2  or   not a3  or   not b3)  and  (a2  or  b3  or   not a0  or   not a1  or   not a3)  and  (b1  or  b2  or   not a0  or   not a3  or   not b0)  and  (a1  or   not a2  or   not a3  or   not b2  or   not b3)  and  (a3  or   not a1  or   not a2  or   not b0  or   not b1)  and  (b2  or   not a1  or   not a3  or   not b1  or   not b3)  and  (a0  or  b1  or   not a2  or   not a3  or   not b0  or   not b2)  and  (b0  or  b1  or   not a0  or   not a1  or   not a2  or   not b2)  and  (a3  or   not a0  or   not a1  or   not a2  or   not b0  or   not b2)  and  (a2  or  b1  or   not a1  or   not a3  or   not b0  or   not b2  or   not b3); 
 } 
//# -- - - Agregando funcion para bit 10 

bool f_s10(bool a3, bool a2, bool a1, bool a0, bool b3, bool b2, bool b1, bool b0) { 
	return (a0  or  a1  or  a2)  and  (a0  or  a1  or  b0)  and  (a1  or  a2  or  a3)  and  (b0  or  b2  or  b3)  and  (b1  or  b2  or  b3)  and  (a0  or  a1  or   not b3)  and  (a2  or  a3  or   not b2)  and  (a0  or  b0  or  b1  or  b2)  and  (a0  or   not b2  or   not b3)  and  (a0  or  a2  or  b2  or   not b0)  and  (a2  or  b0  or  b3  or   not a0)  and  (a1  or  a3  or   not b2  or   not b3)  and  (a2  or  a3  or   not b0  or   not b1)  and  (a3  or  b3  or   not a0  or   not a1)  and  (a2  or  b0  or  b1  or  b2  or   not a1)  and  (a1  or  a3  or  b3  or   not b0  or   not b1)  and  (a1  or  b0  or  b1  or   not b2  or   not b3)  and  (a3  or  b0  or  b1  or   not a0  or   not b2)  and  (a0  or  b2  or   not a1  or   not b0  or   not b1)  and  (a1  or  b2  or   not a0  or   not a3  or   not b0)  and  (a2  or  b0  or   not a1  or   not b1  or   not b2)  and  (b0  or  b1  or   not a2  or   not a3  or   not b3)  and  (a2  or   not a0  or   not b0  or   not b1  or   not b2)  and  (b1  or   not a1  or   not b0  or   not b2  or   not b3)  and  (b2  or   not a3  or   not b0  or   not b1  or   not b3)  and  (a2  or  b0  or  b2  or   not a0  or   not a3  or   not b1)  and  (a3  or  b0  or  b2  or   not a0  or   not a2  or   not b1)  and  (a0  or   not a2  or   not a3  or   not b0  or   not b1  or   not b2)  and  (b0  or   not a1  or   not a2  or   not a3  or   not b2  or   not b3)  and  (a1  or  b1  or  b3  or   not a0  or   not a2  or   not a3  or   not b0)  and  (b3  or   not a1  or   not a2  or   not a3  or   not b0  or   not b1  or   not b2); 
 } 
//# -- - - Agregando funcion para bit 11 

bool f_s11(bool a3, bool a2, bool a1, bool a0, bool b3, bool b2, bool b1, bool b0) { 
	return (a0  or  b0)  and  (a0  or  a1  or  a3)  and  (a0  or  a1  or  b2)  and  (a1  or  a2  or  a3)  and  (a2  or  b2  or  b3)  and  (b0  or  b2  or  b3)  and  (b1  or  b2  or  b3)  and  (a0  or  a2  or   not b2)  and  (a2  or  a3  or  b0  or  b3)  and  (a0  or  a3  or  b1  or   not b3)  and  (a1  or  b0  or  b2  or   not a2)  and  (a1  or  b1  or  b2  or   not a3)  and  (a2  or  b1  or  b3  or   not b0)  and  (a1  or  a3  or  b0  or  b1  or  b3)  and  (a3  or  b0  or  b1  or  b2  or   not a2)  and  (a1  or  a3  or  b0  or   not b1  or   not b3)  and  (a2  or  a3  or  b1  or   not b0  or   not b2)  and  (a2  or  a3  or  b2  or   not a0  or   not b1)  and  (a2  or  b0  or  b2  or   not a1  or   not b1)  and  (a3  or  b3  or   not a2  or   not b0  or   not b1)  and  (b1  or  b3  or   not a0  or   not a1  or   not b0)  and  (b1  or  b3  or   not a1  or   not a2  or   not a3)  and  (b1  or   not a2  or   not a3  or   not b2  or   not b3)  and  (a1  or  a3  or  b1  or   not b0  or   not b2  or   not b3)  and  ( not a1  or   not b0  or   not b1  or   not b2  or   not b3)  and  ( not a2  or   not a3  or   not b0  or   not b2  or   not b3)  and  (a1  or  b3  or   not a2  or   not a3  or   not b1  or   not b2)  and  (b0  or  b1  or   not a1  or   not a3  or   not b2  or   not b3); 
 } 
//# -- - - Agregando funcion para bit 12 

bool f_s12(bool a3, bool a2, bool a1, bool a0, bool b3, bool b2, bool b1, bool b0) { 
	return (b2  or  b3)  and  (a0  or  b0  or  b2)  and  (a1  or  a2  or  a3)  and  (a2  or  a3  or  b3)  and  (a0  or  a1  or   not b0)  and  (a0  or  a1  or   not b3)  and  (a3  or  b0  or  b1  or  b3)  and  (a0  or  a2  or  b0  or   not b1)  and  (a1  or  a3  or  b2  or   not b0)  and  (a1  or  b1  or  b3  or   not b0)  and  (a3  or  b1  or  b3  or   not a0)  and  (a0  or  a2  or   not b1  or   not b3)  and  (a0  or  b1  or   not b0  or   not b3)  and  (a1  or  b2  or   not a2  or   not b1)  and  (a0  or  a2  or  b1  or  b3  or   not a1)  and  (a2  or  a3  or  b0  or  b2  or   not b1)  and  (a0  or  a3  or  b3  or   not b0  or   not b1)  and  (a2  or  b1  or  b2  or   not a1  or   not b0)  and  (a0  or  b0  or   not a1  or   not a3  or   not b1)  and  (b0  or  b2  or   not a2  or   not a3  or   not b1)  and  (b0  or  b3  or   not a0  or   not a1  or   not b1)  and  (b0  or  b3  or   not a0  or   not a2  or   not a3)  and  (a3  or   not a2  or   not b1  or   not b2  or   not b3)  and  (a1  or  b0  or   not a0  or   not a2  or   not a3  or   not b1)  and  (a1  or  b1  or   not a2  or   not a3  or   not b0  or   not b2)  and  (a2  or  b0  or   not a1  or   not a3  or   not b1  or   not b2)  and  (a3  or  b0  or   not a0  or   not a2  or   not b2  or   not b3)  and  (b0  or  b1  or   not a0  or   not a1  or   not a2  or   not b2)  and  ( not a1  or   not a2  or   not b0  or   not b1  or   not b2  or   not b3); 
 } 
//# -- - - Agregando funcion para bit 13 

bool f_s13(bool a3, bool a2, bool a1, bool a0, bool b3, bool b2, bool b1, bool b0) { 
	return (a0  or  a1)  and  (b2  or  b3)  and  (a2  or  a3  or  b3)  and  (a3  or  b1  or  b3)  and  (a0  or  a2  or  a3  or  b2)  and  (a1  or  a2  or  b0  or  b2)  and  (a1  or  a2  or  b0  or  b3)  and  (a0  or  a2  or  b3  or   not b0)  and  (a0  or  b1  or  b2  or   not b0)  and  (a1  or  b1  or  b2  or   not b0)  and  (a2  or  a3  or  b1  or   not a0)  and  (a3  or  b0  or  b1  or   not b2)  and  (a1  or  a3  or   not b1  or   not b3)  and  (a2  or  b3  or   not a1  or   not b1)  and  (a3  or  b3  or   not a1  or   not b0)  and  (a0  or   not b1  or   not b2  or   not b3)  and  (b3  or   not a0  or   not a1  or   not a2)  and  (a0  or  b0  or  b2  or   not a2  or   not a3)  and  (b0  or  b1  or  b2  or   not a0  or   not a3)  and  (a3  or  b2  or   not a2  or   not b0  or   not b1)  and  (b0  or  b1  or   not a1  or   not a2  or   not b2)  and  (b0  or  b1  or   not a1  or   not b2  or   not b3)  and  (b0  or   not a2  or   not b1  or   not b2  or   not b3)  and  ( not a0  or   not a1  or   not a3  or   not b0  or   not b1)  and  (b1  or   not a0  or   not a2  or   not a3  or   not b0  or   not b3); 
 } 
//# -- - - Agregando funcion para bit 14 

bool f_s14(bool a3, bool a2, bool a1, bool a0, bool b3, bool b2, bool b1, bool b0) { 
	return (b2  or  b3)  and  (a1  or  a2  or  a3)  and  (a2  or  a3  or  b3)  and  (a0  or  a1  or   not b3)  and  (a0  or  a2  or  a3  or  b2)  and  (a0  or  a3  or  b0  or  b2)  and  (a0  or  a3  or  b0  or  b3)  and  (a0  or  a3  or  b1  or  b3)  and  (a2  or  a3  or  b0  or  b1)  and  (a3  or  b0  or  b1  or  b3)  and  (a1  or  a3  or  b3  or   not a0)  and  (a1  or  b0  or  b3  or   not b1)  and  (a2  or  b0  or  b1  or   not b2)  and  (a0  or  a2  or   not b0  or   not b2)  and  (a1  or  a2  or  b1  or  b2  or   not b0)  and  (a0  or  b0  or  b1  or   not a1  or   not b2)  and  (a0  or  b2  or   not a2  or   not a3  or   not b0)  and  (a3  or  b2  or   not a0  or   not a2  or   not b1)  and  (b0  or  b2  or   not a0  or   not a2  or   not a3)  and  (b0  or  b2  or   not a0  or   not a3  or   not b1)  and  (b2  or   not a0  or   not a1  or   not a2  or   not b0)  and  (b2  or   not a0  or   not a1  or   not b0  or   not b1)  and  (a1  or  b1  or  b3  or   not a0  or   not a2  or   not b0)  and  ( not a0  or   not a1  or   not a2  or   not a3  or   not b3)  and  ( not a0  or   not a1  or   not a2  or   not b0  or   not b1)  and  (a2  or  b0  or   not a0  or   not a1  or   not a3  or   not b1)  and  (b1  or  b3  or   not a1  or   not a2  or   not a3  or   not b0)  and  ( not a0  or   not a2  or   not a3  or   not b1  or   not b2  or   not b3)  and  ( not a1  or   not a2  or   not b0  or   not b1  or   not b2  or   not b3); 
 } 
//# -- - - Agregando funcion para bit 15 

bool f_s15(bool a3, bool a2, bool a1, bool a0, bool b3, bool b2, bool b1, bool b0) { 
	return (b2  or  b3)  and  (a2  or  a3  or  b1)  and  (a2  or  a3  or  b3)  and  (a2  or  b0  or  b3)  and  (a3  or  b1  or  b3)  and  (a0  or  a1  or   not b3)  and  (a1  or  a3  or   not b1)  and  (a1  or  a3  or   not b2)  and  (a0  or  a2  or  a3  or  b2)  and  (a0  or  a1  or  a2  or   not b1)  and  (a0  or  a3  or  b1  or   not b2)  and  (a1  or  a2  or  b0  or   not b1)  and  (a3  or  b0  or  b1  or   not b2)  and  (a0  or  b0  or   not b2  or   not b3)  and  (a2  or  b3  or   not a0  or   not a1)  and  (a1  or  b0  or  b1  or   not a2  or   not a3)  and  (a0  or  b3  or   not a1  or   not a2  or   not b0)  and  (a1  or  a2  or   not b0  or   not b2  or   not b3)  and  (a1  or  b0  or   not b1  or   not b2  or   not b3)  and  (a1  or  b2  or   not a2  or   not b0  or   not b1)  and  (a2  or  b0  or   not a3  or   not b1  or   not b2)  and  (a2  or  b1  or   not a0  or   not a1  or   not b0)  and  (a3  or  b0  or  b2  or   not a0  or   not a2  or   not b1)  and  (a1  or  b3  or   not a0  or   not a2  or   not b0  or   not b1)  and  (b1  or  b2  or   not a0  or   not a1  or   not a3  or   not b0)  and  ( not a0  or   not a1  or   not a2  or   not a3  or   not b0  or   not b1); 
 } 
//# -- - - Agregando funcion para bit 16 

bool f_s16(bool a3, bool a2, bool a1, bool a0, bool b3, bool b2, bool b1, bool b0) { 
	return (a2  or  a3)  and  (b2  or  b3)  and  (a1  or  a2  or  b0)  and  (b0  or  b1  or  b3)  and  (a1  or  a2  or   not b2)  and  (a0  or  a3  or  b0  or   not b1)  and  (a0  or  a1  or   not b0  or   not b3)  and  (a0  or  a1  or   not b1  or   not b3)  and  (a0  or  a1  or   not b2  or   not b3)  and  (a0  or  b2  or   not a3  or   not b0)  and  (a0  or  b3  or   not a1  or   not a2)  and  (a0  or  b3  or   not b0  or   not b1)  and  (a2  or  b1  or   not a0  or   not b2)  and  (a3  or  b1  or   not b0  or   not b2)  and  (a3  or  b3  or   not a1  or   not b0)  and  (a2  or   not b0  or   not b1  or   not b3)  and  (a1  or  a3  or  b0  or   not b1  or   not b2)  and  (a1  or  b0  or  b1  or   not a3  or   not b2)  and  (a0  or  b0  or   not b1  or   not b2  or   not b3)  and  (a0  or  b1  or   not a1  or   not a2  or   not a3)  and  (b1  or   not a1  or   not b0  or   not b2  or   not b3)  and  (b2  or   not a1  or   not a3  or   not b0  or   not b1)  and  (b0  or  b1  or  b2  or   not a0  or   not a1  or   not a3)  and  (b0  or   not a0  or   not a1  or   not a2  or   not b1  or   not b3); 
 } 
//# -- - - Agregando funcion para bit 17 

bool f_s17(bool a3, bool a2, bool a1, bool a0, bool b3, bool b2, bool b1, bool b0) { 
	return (a3  or  b3)  and  (b2  or  b3)  and  (a0  or  a1  or  a2)  and  (a0  or  a1  or  b0)  and  (a0  or  a2  or  a3)  and  (a1  or  a2  or  a3)  and  (a1  or  a3  or  b0)  and  (a1  or  a3  or  b2)  and  (a2  or  a3  or  b0)  and  (a2  or  a3  or  b1)  and  (b0  or  b1  or  b3)  and  (a0  or  a1  or   not b3)  and  (a1  or  b2  or   not b1)  and  (a1  or  b3  or   not a0)  and  (a0  or  a2  or  b0  or  b1)  and  (a0  or  a3  or  b1  or  b2)  and  (a1  or  a2  or  b0  or  b1)  and  (a0  or  b3  or   not a1  or   not b0)  and  (a2  or  b3  or   not b0  or   not b1)  and  (b0  or  b3  or   not a0  or   not a2)  and  (a1  or   not a2  or   not b1  or   not b3)  and  (a2  or  b0  or  b2  or   not a0  or   not b1)  and  (a0  or  a3  or   not b0  or   not b1  or   not b2)  and  (a3  or  b1  or   not a0  or   not a1  or   not b2)  and  (b0  or  b1  or   not a0  or   not a1  or   not b2)  and  (b2  or   not a2  or   not a3  or   not b0  or   not b1)  and  (a0  or  b0  or   not a2  or   not a3  or   not b1  or   not b2  or   not b3)  and  (a0  or  b1  or   not a2  or   not a3  or   not b0  or   not b2  or   not b3); 
 } 
//# -- - - Agregando funcion para bit 18 

bool f_s18(bool a3, bool a2, bool a1, bool a0, bool b3, bool b2, bool b1, bool b0) { 
	return (a2  or  a3)  and  (b2  or  b3)  and  (a1  or  a3  or  b3)  and  (a3  or  b0  or  b3)  and  (b0  or  b1  or  b3)  and  (a2  or  b3  or   not a0)  and  (b1  or  b3  or   not a1)  and  (a0  or  a1  or  b0  or  b1)  and  (a0  or  a1  or  b1  or   not b2)  and  (a0  or  a2  or  b1  or   not b0)  and  (a0  or  b0  or  b2  or   not b1)  and  (a1  or  a2  or  b0  or  b1  or  b2)  and  (a0  or  a1  or   not b1  or   not b3)  and  (a0  or  b3  or   not a3  or   not b0)  and  (a1  or  a2  or   not b0  or   not b2)  and  (a3  or  b1  or   not b0  or   not b2)  and  (a0  or  a3  or  b1  or  b2  or   not a1)  and  (a0  or  a2  or  b0  or   not b1  or   not b3)  and  (a0  or  b0  or  b3  or   not a1  or   not a2)  and  (a2  or  b1  or  b2  or   not a1  or   not b0)  and  (a3  or  b2  or   not a0  or   not b0  or   not b1)  and  (b0  or  b1  or   not a0  or   not a1  or   not b2)  and  (a0  or  b0  or  b1  or   not a2  or   not a3  or   not b2)  and  (a1  or  b0  or   not a0  or   not a2  or   not a3  or   not b1)  and  (a0  or   not a2  or   not a3  or   not b0  or   not b1  or   not b2)  and  (b0  or   not a0  or   not a1  or   not a2  or   not a3  or   not b3)  and  (b2  or   not a0  or   not a1  or   not a2  or   not b0  or   not b1)  and  (a1  or  b1  or   not a0  or   not a2  or   not a3  or   not b0  or   not b3); 
 } 
//# -- - - Agregando funcion para bit 19 

bool f_s19(bool a3, bool a2, bool a1, bool a0, bool b3, bool b2, bool b1, bool b0) { 
	return (b2  or  b3)  and  (a0  or  a1  or  a2)  and  (a0  or  a1  or  a3)  and  (a0  or  a2  or  a3)  and  (a1  or  a2  or  a3)  and  (a1  or  a3  or  b3)  and  (a2  or  a3  or  b2)  and  (a2  or  a3  or  b3)  and  (a2  or  b1  or  b3)  and  (a3  or  b0  or  b3)  and  (a3  or  b1  or  b3)  and  (a2  or  b0  or  b1  or  b2)  and  (a0  or  b0  or  b1  or   not a3)  and  (a3  or  b0  or  b2  or   not a0)  and  (a0  or  a1  or   not b0  or   not b2)  and  (a1  or  b1  or   not b0  or   not b2)  and  (b2  or   not a3  or   not b0  or   not b1)  and  (a0  or  a2  or   not b0  or   not b2  or   not b3)  and  (a0  or  a3  or   not b0  or   not b1  or   not b2)  and  (a1  or  b0  or   not a3  or   not b1  or   not b3)  and  (a1  or  b1  or   not a0  or   not a3  or   not b0)  and  (a1  or  b1  or   not a2  or   not a3  or   not b2)  and  (b0  or  b1  or   not a0  or   not a1  or   not a2)  and  (b1  or  b2  or   not a0  or   not a1  or   not a2)  and  (a0  or  b0  or   not a1  or   not a2  or   not a3  or   not b2)  and  (a2  or   not a1  or   not a3  or   not b0  or   not b1  or   not b3)  and  ( not a0  or   not a1  or   not a2  or   not a3  or   not b2  or   not b3)  and  ( not a0  or   not a1  or   not a2  or   not b0  or   not b1  or   not b2  or   not b3); 
 } 
//# -- - - Agregando funcion para bit 20 

bool f_s20(bool a3, bool a2, bool a1, bool a0, bool b3, bool b2, bool b1, bool b0) { 
	return (a3  or  b3)  and  (b1  or  b3)  and  (b2  or  b3)  and  (a0  or  a1  or  b1)  and  (a0  or  a2  or  a3)  and  (a1  or  a2  or  a3)  and  (a1  or  a2  or  b3)  and  (a2  or  a3  or  b2)  and  (a0  or  a1  or   not b0)  and  (a0  or  a1  or   not b2)  and  (a0  or  a2  or  b0  or  b3)  and  (a1  or  a3  or  b0  or  b1)  and  (a1  or  a3  or  b0  or   not b2)  and  (a1  or  b1  or   not b0  or   not b2)  and  (b0  or  b3  or   not a0  or   not a2)  and  (a0  or  a2  or  b0  or  b2  or   not b1)  and  (b3  or   not a1  or   not a2  or   not b0)  and  (a1  or  a3  or  b2  or   not b0  or   not b1)  and  (a3  or  b1  or   not a0  or   not a2  or   not b2)  and  (b0  or  b1  or   not a1  or   not a3  or   not b2)  and  (b1  or  b2  or   not a0  or   not a1  or   not a3)  and  (b1  or  b2  or   not a0  or   not a1  or   not b0)  and  (b2  or   not a1  or   not a2  or   not a3  or   not b1)  and  (a2  or  b0  or   not a0  or   not a1  or   not b2  or   not b3)  and  (b0  or  b2  or   not a0  or   not a2  or   not a3  or   not b1)  and  (a2  or   not a0  or   not a1  or   not a3  or   not b0  or   not b1)  and  (a2  or   not a3  or   not b0  or   not b1  or   not b2  or   not b3); 
 } 
//# -- - - Agregando funcion para bit 21 

bool f_s21(bool a3, bool a2, bool a1, bool a0, bool b3, bool b2, bool b1, bool b0) { 
	return (a2  or  a3)  and  (a3  or  b3)  and  (b1  or  b3)  and  (b2  or  b3)  and  (a0  or  a3  or  b2)  and  (a2  or  b0  or  b3)  and  (a1  or  b0  or   not a0)  and  (a0  or  a1  or  a2  or   not b3)  and  (a1  or  b1  or  b2  or   not b0)  and  (a2  or  b1  or  b2  or   not a0)  and  (a2  or  b1  or  b2  or   not b0)  and  (a0  or  a1  or   not b2  or   not b3)  and  (a1  or  a2  or   not a0  or   not b2)  and  (a3  or  b1  or   not a0  or   not b2)  and  (a3  or  b2  or   not a1  or   not b1)  and  (b0  or  b2  or   not a0  or   not a2)  and  (a0  or  a2  or  b0  or  b2  or   not b1)  and  (a0  or   not a2  or   not a3  or   not b2  or   not b3)  and  (a1  or   not a2  or   not a3  or   not b1  or   not b3)  and  (a2  or   not b0  or   not b1  or   not b2  or   not b3)  and  (a0  or  b0  or   not a2  or   not b1  or   not b2  or   not b3)  and  (a0  or   not a1  or   not a3  or   not b0  or   not b1  or   not b2); 
 } 
//# -- - - Agregando funcion para bit 22 

bool f_s22(bool a3, bool a2, bool a1, bool a0, bool b3, bool b2, bool b1, bool b0) { 
	return (a3  or  b3)  and  (b2  or  b3)  and  (a0  or  a1  or  a2)  and  (a0  or  a2  or  a3)  and  (a1  or  a2  or  a3)  and  (a1  or  b0  or  b1)  and  (a1  or  b1  or  b2)  and  (a2  or  a3  or  b2)  and  (a0  or  a1  or   not b2)  and  (a1  or  b1  or   not a3)  and  (a2  or  b3  or   not a1)  and  (b3  or   not a0  or   not a1)  and  (a0  or  a3  or  b2  or   not a1)  and  (a0  or  b0  or  b1  or   not b2)  and  (a1  or  a2  or  b0  or   not b2)  and  (a1  or  b0  or  b2  or   not a2)  and  (a2  or  b1  or  b2  or   not b0)  and  (a0  or  a2  or  b0  or  b2  or   not b1)  and  (a3  or  b1  or   not a0  or   not a1  or   not b2)  and  (a0  or   not a2  or   not a3  or   not b2  or   not b3)  and  (a1  or   not a2  or   not a3  or   not b0  or   not b2)  and  (b1  or   not a2  or   not a3  or   not b0  or   not b2)  and  (b2  or   not a0  or   not a2  or   not a3  or   not b1)  and  (a3  or   not a1  or   not a2  or   not b0  or   not b1  or   not b2)  and  (b0  or   not a0  or   not a1  or   not a2  or   not b1  or   not b2); 
 } 
//# -- - - Agregando funcion para bit 23 

bool f_s23(bool a3, bool a2, bool a1, bool a0, bool b3, bool b2, bool b1, bool b0) { 
	return (a3  or  b3)  and  (b1  or  b3)  and  (b2  or  b3)  and  (a0  or  a1  or  a2)  and  (a0  or  a1  or  a3)  and  (a0  or  a2  or  a3)  and  (a1  or  a2  or  a3)  and  (a1  or  b0  or  b3)  and  (a2  or  a3  or  b2)  and  (a0  or  a1  or   not b2)  and  (a0  or  b3  or   not a2)  and  (a2  or  b3  or   not a0)  and  (a3  or  b0  or  b1  or  b2)  and  (a0  or  a2  or  b0  or   not b1)  and  (a0  or  a2  or  b2  or   not b1)  and  (a1  or  a2  or  b0  or   not b2)  and  (a0  or  b1  or   not b0  or   not b2)  and  (a1  or  b1  or   not a3  or   not b2)  and  (a3  or  b1  or   not a0  or   not a1)  and  (a0  or   not a2  or   not b0  or   not b2)  and  (a1  or  b2  or   not a0  or   not a3  or   not b0)  and  (a3  or  b0  or   not a0  or   not a1  or   not b2)  and  (b1  or  b2  or   not a0  or   not a2  or   not b0)  and  (b0  or  b1  or   not a0  or   not a2  or   not a3  or   not b2)  and  (b0  or  b2  or   not a0  or   not a2  or   not a3  or   not b1)  and  (b1  or  b2  or   not a1  or   not a2  or   not a3  or   not b0)  and  ( not a0  or   not a1  or   not a3  or   not b0  or   not b1  or   not b2); 
 } 
//# -- - - Agregando funcion para bit 24 

bool f_s24(bool a3, bool a2, bool a1, bool a0, bool b3, bool b2, bool b1, bool b0) { 
	return (a2  or  a3)  and  (b0  or  b3)  and  (b1  or  b3)  and  (b2  or  b3)  and  (a1  or  a2  or  b3)  and  (a1  or  a3  or  b2)  and  (a3  or  b1  or  b2)  and  (a0  or  a2  or   not b2)  and  (b3  or   not a1  or   not a2)  and  (a0  or  a1  or  a2  or   not b0)  and  (a0  or  a3  or  b1  or   not b0)  and  (a1  or  a3  or  b1  or   not a0)  and  (a3  or  b0  or  b2  or   not a0)  and  (a0  or  a1  or   not b0  or   not b2)  and  (a0  or  b2  or   not a3  or   not b1)  and  (b0  or  b1  or   not a0  or   not a3)  and  (a0  or   not a3  or   not b0  or   not b1)  and  (a0  or  a3  or  b0  or   not b1  or   not b2)  and  (a1  or  a2  or  b2  or   not b0  or   not b1)  and  (a1  or  b1  or  b2  or   not a0  or   not a2)  and  (a2  or  b1  or  b2  or   not a0  or   not a1)  and  (b0  or  b1  or   not a1  or   not a3  or   not b2)  and  (a3  or   not a0  or   not b0  or   not b1  or   not b2)  and  (a1  or   not a2  or   not a3  or   not b1  or   not b2  or   not b3); 
 } 
//# -- - - Agregando funcion para bit 25 

bool f_s25(bool a3, bool a2, bool a1, bool a0, bool b3, bool b2, bool b1, bool b0) { 
	return (a2  or  a3)  and  (a2  or  b3)  and  (a3  or  b3)  and  (b0  or  b3)  and  (b1  or  b3)  and  (b2  or  b3)  and  (a0  or  a1  or  a2)  and  (a0  or  a2  or  b0)  and  (a0  or  a2  or   not b1)  and  (a0  or  a1  or  b0  or  b1)  and  (a0  or  a3  or  b1  or  b2)  and  (a1  or  a3  or  b0  or  b2)  and  (a2  or   not a0  or   not a1)  and  (a1  or  a3  or  b1  or   not b0)  and  (a0  or  a1  or   not b2  or   not b3)  and  (a0  or  a3  or   not b0  or   not b1)  and  (b0  or  b1  or   not a0  or   not a1)  and  (b0  or  b1  or   not a1  or   not b2)  and  (a3  or   not a0  or   not a1  or   not b1)  and  (a0  or  b2  or   not a1  or   not a3  or   not b1)  and  (a1  or  b2  or   not a0  or   not a2  or   not a3)  and  ( not a0  or   not a1  or   not a3  or   not b2  or   not b3)  and  ( not a0  or   not a1  or   not b0  or   not b1  or   not b3)  and  (a1  or  b0  or   not a0  or   not a2  or   not a3  or   not b1); 
 } 
//# -- - - Agregando funcion para bit 26 

bool f_s26(bool a3, bool a2, bool a1, bool a0, bool b3, bool b2, bool b1, bool b0) { 
	return (a2  or  a3)  and  (a2  or  b3)  and  (a3  or  b3)  and  (b1  or  b3)  and  (b2  or  b3)  and  (a0  or  a1  or  a2)  and  (a0  or  a1  or  b0)  and  (a1  or  a3  or   not b1)  and  (a0  or  a1  or  b1  or  b2)  and  (a1  or   not b1  or   not b2)  and  (a0  or  a2  or  b2  or   not b0)  and  (a0  or  a3  or  b1  or   not a1)  and  (a1  or  b0  or  b1  or   not a3)  and  (a1  or  a3  or   not a0  or   not b0)  and  (a2  or  b1  or   not a0  or   not b2)  and  (a3  or  b0  or   not a0  or   not a1)  and  (b0  or  b2  or   not a2  or   not b1)  and  (b1  or  b2  or   not a0  or   not a2)  and  ( not a0  or   not a2  or   not b1  or   not b2)  and  ( not a0  or   not a3  or   not b0  or   not b2)  and  (a0  or  b0  or   not a3  or   not b1  or   not b2)  and  (b0  or  b2  or   not a0  or   not a1  or   not b1)  and  ( not a2  or   not b0  or   not b1  or   not b2  or   not b3); 
 } 
//# -- - - Agregando funcion para bit 27 

bool f_s27(bool a3, bool a2, bool a1, bool a0, bool b3, bool b2, bool b1, bool b0) { 
	return (a1  or  b3)  and  (a2  or  a3)  and  (a3  or  b2)  and  (a3  or  b3)  and  (b1  or  b3)  and  (b2  or  b3)  and  (a0  or  a1  or  a3)  and  (a0  or  a2  or  b0)  and  (a0  or  a1  or  a2  or   not b1)  and  (a0  or  a1  or  a2  or   not b2)  and  (a0  or  b0  or  b1  or   not a1)  and  (a1  or  a2  or  b1  or   not a0)  and  (a0  or   not a3  or   not b1  or   not b2)  and  (a2  or   not a0  or   not b0  or   not b2)  and  (a1  or  b0  or  b1  or   not a0  or   not a3)  and  (a1  or  b0  or   not a2  or   not a3  or   not b2)  and  (a0  or  a1  or  b1  or  b2  or   not a2  or   not b0)  and  (a3  or   not a0  or   not a1  or   not b0  or   not b1)  and  (b0  or   not a1  or   not a3  or   not b1  or   not b2)  and  (a1  or  b2  or   not a0  or   not a2  or   not b0  or   not b1)  and  (b1  or  b2  or   not a0  or   not a1  or   not a2  or   not b0)  and  (b0  or   not a0  or   not a1  or   not a2  or   not a3  or   not b1); 
 } 
//# -- - - Agregando funcion para bit 28 

bool f_s28(bool a3, bool a2, bool a1, bool a0, bool b3, bool b2, bool b1, bool b0) { 
	return b3  and  (a2  or  a3)  and  (a0  or  a1  or  a2)  and  (a0  or  a3  or  b1)  and  (a1  or  a3  or  b2)  and  (a3  or  b1  or  b2)  and  (a3  or  b1  or   not b0)  and  (a0  or  a3  or  b0  or  b2)  and  (a2  or  b0  or  b1  or  b2)  and  (a2  or   not a0  or   not b1)  and  (a2  or   not b0  or   not b1)  and  (a0  or  a1  or   not b0  or   not b2)  and  (a0  or  a2  or   not b0  or   not b2)  and  (a1  or  b0  or   not a0  or   not b2)  and  (a2  or  b2  or   not a0  or   not a1)  and  (a0  or  a1  or  b0  or  b2  or   not b1)  and  (a1  or   not a0  or   not a3  or   not b0  or   not b1)  and  (a3  or   not a0  or   not a1  or   not b1  or   not b2)  and  (b0  or   not a0  or   not a2  or   not a3  or   not b2)  and  (b2  or   not a0  or   not a1  or   not a3  or   not b1)  and  (a0  or  b1  or  b2  or   not a1  or   not a2  or   not b0); 
 } 
//# -- - - Agregando funcion para bit 29 

bool f_s29(bool a3, bool a2, bool a1, bool a0, bool b3, bool b2, bool b1, bool b0) { 
	return b3  and  (a2  or  a3)  and  (a0  or  a1  or  a3)  and  (a0  or  a2  or  b0)  and  (a3  or  b1  or  b2)  and  (a1  or  a2  or   not b0)  and  (a1  or  a3  or   not b0)  and  (b0  or  b2  or   not a1)  and  (a0  or  b0  or  b1  or  b2)  and  (a2  or  b1  or  b2  or   not a0)  and  (a0  or  a1  or   not b1  or   not b2)  and  (a0  or  b1  or   not a1  or   not b2)  and  (a0  or  b2  or   not a1  or   not b1)  and  (a1  or  b1  or   not a0  or   not b2)  and  (a1  or  b2  or   not a0  or   not b1)  and  (b1  or   not a2  or   not b0  or   not b2)  and  (a0  or   not a1  or   not a2  or   not a3  or   not b0)  and  ( not a0  or   not a1  or   not a2  or   not a3  or   not b1  or   not b2); 
 } 
//# -- - - Agregando funcion para bit 30 

bool f_s30(bool a3, bool a2, bool a1, bool a0, bool b3, bool b2, bool b1, bool b0) { 
	return b3  and  (a2  or  a3)  and  (a0  or  a3  or  b1)  and  (a0  or  a3  or  b2)  and  (a1  or  a3  or  b2)  and  (a2  or  b1  or  b2)  and  (a3  or  b0  or  b1)  and  (a3  or  b0  or  b2)  and  (a3  or  b1  or   not a1)  and  (a0  or  a1  or  a2  or  b1)  and  (a0  or  a1  or  b1  or  b2)  and  (a0  or  a1  or  a2  or   not b0)  and  (b0  or  b1  or  b2  or   not a0)  and  (a0  or  a2  or   not b1  or   not b2)  and  (a0  or  b0  or   not b1  or   not b2)  and  (a1  or  b0  or  b2  or   not a0  or   not a2)  and  (a2  or  b0  or  b1  or   not a0  or   not a1)  and  (a2  or  b0  or  b2  or   not a0  or   not a1)  and  (a0  or  b1  or   not a1  or   not a2  or   not b2)  and  (a1  or  a3  or   not a0  or   not b0  or   not b1)  and  (a1  or  b1  or   not a0  or   not a2  or   not a3  or   not b2); 
 } 
//# -- - - Agregando funcion para bit 31 

bool f_s31(bool a3, bool a2, bool a1, bool a0, bool b3, bool b2, bool b1, bool b0) { 
	return b3  and  (a1  or  a3)  and  (a2  or  a3)  and  (a3  or  b2)  and  (a0  or  a1  or  a2)  and  (a0  or  a2  or  b2)  and  (a1  or  b1  or  b2)  and  (a0  or  a3  or   not b1)  and  (a2  or  b0  or  b2  or   not a1)  and  (a3  or  b0  or  b1  or   not a0)  and  (a0  or  b1  or   not b0  or   not b2)  and  (a2  or  b0  or   not b1  or   not b2)  and  (a2  or  b2  or   not b0  or   not b1)  and  (b0  or  b2  or   not a2  or   not b1)  and  (a1  or   not a0  or   not a2  or   not b0  or   not b1)  and  (a0  or  b0  or  b1  or   not a1  or   not a2  or   not a3)  and  ( not a0  or   not a1  or   not b0  or   not b1  or   not b2); 
 } 
//# -- - - Agregando funcion para bit 32 

bool f_s32(bool a3, bool a2, bool a1, bool a0, bool b3, bool b2, bool b1, bool b0) { 
	return b3  and  (a2  or  a3)  and  (a3  or  b2)  and  (a0  or  a1  or  a3)  and  (a0  or  a2  or  b1)  and  (a0  or  a3  or  b0)  and  (a1  or  b0  or  b2)  and  (a2  or  b0  or  b2)  and  (b0  or  b2  or   not a0)  and  (b1  or  b2  or   not a0)  and  (a1  or  a2  or  b0  or   not b1)  and  (a0  or  a1  or   not b0  or   not b1)  and  (a0  or  a2  or   not b0  or   not b2)  and  (a1  or  b1  or   not a0  or   not a2)  and  (a2  or  b2  or   not a0  or   not a1)  and  (a3  or  b1  or   not a0  or   not b0)  and  (b0  or  b1  or   not a1  or   not a3)  and  (a0  or  b2  or   not a1  or   not a2  or   not b0)  and  ( not a0  or   not a2  or   not a3  or   not b0  or   not b1  or   not b2); 
 } 
//# -- - - Agregando funcion para bit 33 

bool f_s33(bool a3, bool a2, bool a1, bool a0, bool b3, bool b2, bool b1, bool b0) { 
	return b3  and  (a2  or  a3)  and  (a3  or  b2)  and  (a0  or  a1  or  a3)  and  (a0  or  b1  or  b2)  and  (a1  or  a3  or  b1)  and  (a2  or  b1  or  b2)  and  (a1  or  a2  or  b0  or  b2)  and  (a0  or  a1  or  a2  or   not b2)  and  (a0  or  b0  or  b1  or   not a1)  and  (a1  or  b0  or  b1  or   not a0)  and  (a0  or  a3  or   not b0  or   not b1)  and  (a1  or  b0  or   not a0  or   not a2)  and  (a3  or  b0  or   not a0  or   not b1)  and  (b1  or   not a1  or   not a2  or   not a3)  and  (b1  or   not a1  or   not a3  or   not b0)  and  (a1  or  b2  or   not a2  or   not b0  or   not b1)  and  ( not a0  or   not a1  or   not a2  or   not b0  or   not b1)  and  (a2  or  b0  or   not a0  or   not a1  or   not b1  or   not b2)  and  (a1  or   not a0  or   not a3  or   not b0  or   not b1  or   not b2); 
 } 
//# -- - - Agregando funcion para bit 34 

bool f_s34(bool a3, bool a2, bool a1, bool a0, bool b3, bool b2, bool b1, bool b0) { 
	return b3  and  (a2  or  a3)  and  (a3  or  b2)  and  (b0  or  b1)  and  (a0  or  a1  or  a2)  and  (a0  or  a2  or  b1)  and  (a0  or  a3  or  b0)  and  (a1  or  a3  or  b0)  and  (a1  or  a3  or  b1)  and  (a1  or  b1  or  b2)  and  (b1  or  b2  or   not a0)  and  (a1  or  a2  or  b0  or  b2)  and  (a0  or  b0  or  b2  or   not a1)  and  (a0  or  b1  or   not a1  or   not b2)  and  (a1  or  b2  or   not a0  or   not a2)  and  (a2  or  b0  or   not a1  or   not b2)  and  (a0  or  a1  or   not b0  or   not b1  or   not b2)  and  (a1  or  a2  or   not b0  or   not b1  or   not b2)  and  (a2  or  b2  or   not a0  or   not a1  or   not b0)  and  (a3  or   not a0  or   not a1  or   not b0  or   not b1)  and  (a0  or   not a2  or   not a3  or   not b0  or   not b1  or   not b2); 
 } 
//# -- - - Agregando funcion para bit 35 

bool f_s35(bool a3, bool a2, bool a1, bool a0, bool b3, bool b2, bool b1, bool b0) { 
	return b3  and  (a1  or  a3)  and  (a2  or  a3)  and  (a2  or  b2)  and  (a3  or  b2)  and  (a0  or  a1  or  a2)  and  (a0  or  a3  or  b0)  and  (a0  or  b1  or  b2)  and  (a1  or  b2  or   not a0)  and  (b0  or  b2  or   not a1)  and  (a1  or  a2  or  b0  or  b1)  and  (a3  or   not a0  or   not b0)  and  (a0  or  b1  or   not a1  or   not a2)  and  (a1  or  a2  or   not b0  or   not b1)  and  (a1  or  b1  or   not a0  or   not a2)  and  (a2  or  b0  or   not a1  or   not b1)  and  (b0  or  b1  or   not a1  or   not a2)  and  (a1  or  b0  or   not a2  or   not b1  or   not b2)  and  (a2  or  b1  or   not a0  or   not a1  or   not b0); 
 } 
//# -- - - Agregando funcion para bit 36 

bool f_s36(bool a3, bool a2, bool a1, bool a0, bool b3, bool b2, bool b1, bool b0) { 
	return b3  and  (a1  or  a3)  and  (a2  or  a3)  and  (a3  or  b2)  and  (b0  or  b2)  and  (b1  or  b2)  and  (a3  or  b0  or  b1)  and  (a0  or  a3  or   not b0)  and  (a0  or  b2  or   not a2)  and  (a1  or  a2  or   not a0)  and  (a1  or  a2  or   not b1)  and  (a1  or   not a0  or   not b1)  and  (a2  or   not a0  or   not b0)  and  (a2  or   not a0  or   not b1)  and  (a0  or  a1  or  b1  or   not b0)  and  (a0  or  a2  or  b0  or  b1  or   not a1)  and  (b0  or   not a1  or   not a2  or   not a3  or   not b1)  and  (b1  or   not a1  or   not a2  or   not a3  or   not b0)  and  ( not a0  or   not a1  or   not a2  or   not a3  or   not b2); 
 } 
//# -- - - Agregando funcion para bit 37 

bool f_s37(bool a3, bool a2, bool a1, bool a0, bool b3, bool b2, bool b1, bool b0) { 
	return b3  and  (a1  or  a2)  and  (a1  or  a3)  and  (a2  or  a3)  and  (a2  or  b2)  and  (a3  or  b1)  and  (a3  or  b2)  and  (b1  or  b2)  and  (a3  or   not a0)  and  (a0  or  a1  or  b1)  and  (a0  or  b0  or  b2)  and  (b0  or   not a1  or   not a2)  and  (b2  or   not a0  or   not a1)  and  (a0  or  a2  or  b1  or   not b0)  and  (a2  or  b0  or  b1  or   not a0)  and  (a1  or   not a0  or   not b1  or   not b2)  and  (b1  or   not a0  or   not a1  or   not a2)  and  (a0  or   not a2  or   not a3  or   not b0  or   not b1  or   not b2); 
 } 
//# -- - - Agregando funcion para bit 38 

bool f_s38(bool a3, bool a2, bool a1, bool a0, bool b3, bool b2, bool b1, bool b0) { 
	return b3  and  (a1  or  a3)  and  (a1  or  b2)  and  (a2  or  a3)  and  (a3  or  b0)  and  (a3  or  b1)  and  (a3  or  b2)  and  (b1  or  b2)  and  (a0  or  a1  or  a2)  and  (a0  or  a2  or  b2)  and  (a0  or  a1  or   not b1)  and  (a0  or  b2  or   not b0)  and  (a1  or  b0  or   not a2)  and  (b0  or  b1  or   not a2)  and  (b0  or  b2  or   not a0)  and  (a0  or  a2  or  b1  or   not b0)  and  ( not a0  or   not a1  or   not a2  or   not a3  or   not b0  or   not b2)  and  ( not a0  or   not a1  or   not a3  or   not b0  or   not b1  or   not b2); 
 } 
//# -- - - Agregando funcion para bit 39 

bool f_s39(bool a3, bool a2, bool a1, bool a0, bool b3, bool b2, bool b1, bool b0) { 
	return b3  and  (a0  or  a3)  and  (a2  or  a3)  and  (a2  or  b2)  and  (a3  or  b2)  and  (b1  or  b2)  and  (a0  or  b0  or  b2)  and  (a1  or  b0  or  b1)  and  (a1  or  b1  or   not a2)  and  (a2  or   not a1  or   not b0)  and  (b1  or   not a0  or   not a2)  and  (a0  or  a1  or  a2  or   not b1)  and  ( not a0  or   not b0  or   not b2)  and  (a1  or  b0  or   not a0  or   not a2)  and  (a2  or   not a0  or   not a1  or   not b1)  and  (a0  or   not a1  or   not a2  or   not b1  or   not b2); 
 } 
//# -- - - Agregando funcion para bit 40 

bool f_s40(bool a3, bool a2, bool a1, bool a0, bool b3, bool b2, bool b1, bool b0) { 
	return a3  and  b3  and  (a2  or  b2)  and  (b0  or  b2)  and  (b1  or  b2)  and  (a1  or  a2  or  b0)  and  (a1  or  a2  or  b1)  and  (a2  or  b0  or  b1)  and  (a0  or  a1  or  b0  or  b1)  and  (a0  or  a1  or   not b0  or   not b1)  and  (a0  or  b0  or   not a1  or   not b1)  and  ( not a0  or   not a1  or   not a2  or   not b2)  and  ( not a1  or   not a2  or   not b1  or   not b2); 
 } 
//# -- - - Agregando funcion para bit 41 

bool f_s41(bool a3, bool a2, bool a1, bool a0, bool b3, bool b2, bool b1, bool b0) { 
	return a3  and  b3  and  (a2  or  b2)  and  (b0  or  b2)  and  (b1  or  b2)  and  (a0  or  a1  or  a2)  and  (a0  or  a2  or  b1)  and  (a1  or  b0  or  b1)  and  (a1  or  b0  or   not a0)  and  (a0  or   not b0  or   not b2)  and  (a2  or  b0  or   not a0  or   not b1)  and  (a1  or   not a2  or   not b0  or   not b1); 
 } 
//# -- - - Agregando funcion para bit 42 

bool f_s42(bool a3, bool a2, bool a1, bool a0, bool b3, bool b2, bool b1, bool b0) { 
	return b3  and  (a0  or  a3)  and  (a0  or  b1)  and  (a0  or  b2)  and  (a2  or  a3)  and  (a2  or  b2)  and  (a3  or  b0)  and  (a3  or  b2)  and  (b0  or  b2)  and  (a1  or  a2  or  b1)  and  (a1  or  a2  or   not b0)  and  (a2  or  b0  or   not a1)  and  (a0  or   not a1  or   not a2)  and  (a1  or   not a0  or   not b0)  and  (b1  or   not a2  or   not b0); 
 } 
//# -- - - Agregando funcion para bit 43 

bool f_s43(bool a3, bool a2, bool a1, bool a0, bool b3, bool b2, bool b1, bool b0) { 
	return a3  and  b2  and  b3  and  (a0  or  a1  or  a2)  and  (a1  or  a2  or  b0)  and  (a1  or  b1  or   not a0)  and  (a1  or  b1  or   not b0)  and  (b0  or  b1  or   not a1)  and  (a0  or   not a1  or   not a2  or   not b0)  and  (b0  or   not a0  or   not a1  or   not a2)  and  ( not a0  or   not a1  or   not b0  or   not b1); 
 } 
//# -- - - Agregando funcion para bit 44 

bool f_s44(bool a3, bool a2, bool a1, bool a0, bool b3, bool b2, bool b1, bool b0) { 
	return a3  and  b2  and  b3  and  (a0  or  a1  or  b0)  and  (a0  or  a1  or  b1)  and  (a1  or  a2  or  b1)  and  (a2  or  b0  or  b1)  and  (a0  or  a2  or   not b0)  and  (b1  or   not a0  or   not a1  or   not a2  or   not b0); 
 } 
//# -- - - Agregando funcion para bit 45 

bool f_s45(bool a3, bool a2, bool a1, bool a0, bool b3, bool b2, bool b1, bool b0) { 
	return a3  and  b2  and  b3  and  (a2  or  b0)  and  (a2  or  b1)  and  (a2  or   not a1)  and  (a0  or  a1  or  b0)  and  (a1  or  b0  or  b1)  and  (a0  or  b1  or   not a1  or   not b0)  and  (a1  or   not a0  or   not a2  or   not b0); 
 } 
//# -- - - Agregando funcion para bit 46 

bool f_s46(bool a3, bool a2, bool a1, bool a0, bool b3, bool b2, bool b1, bool b0) { 
	return a3  and  b2  and  b3  and  (a1  or  a2)  and  (a2  or  b1)  and  (a0  or  b0  or  b1)  and  (a0  or  a1  or   not b1)  and  (a1  or  b1  or   not a0)  and  (a0  or   not b0  or   not b1)  and  ( not a0  or   not a1  or   not a2  or   not b1); 
 } 
//# -- - - Agregando funcion para bit 47 

bool f_s47(bool a3, bool a2, bool a1, bool a0, bool b3, bool b2, bool b1, bool b0) { 
	return a3  and  b2  and  b3  and  (a1  or  b1)  and  (a2  or  b0)  and  (a2  or  b1)  and  (b0  or  b1)  and  (a0  or  a1  or  a2)  and  (a0  or  b0  or   not a1); 
 } 
//# -- - - Agregando funcion para bit 48 

bool f_s48(bool a3, bool a2, bool a1, bool a0, bool b3, bool b2, bool b1, bool b0) { 
	return a3  and  b2  and  b3  and  (a0  or  a1)  and  (a1  or  a2)  and  (b0  or  b1)  and  (b1  or   not a1)  and  (a0  or  a2  or  b0)  and  (a0  or   not a2  or   not b0)  and  (a2  or   not a0  or   not b0); 
 } 
//# -- - - Agregando funcion para bit 49 

bool f_s49(bool a3, bool a2, bool a1, bool a0, bool b3, bool b2, bool b1, bool b0) { 
	return a3  and  b2  and  b3  and  (a1  or  a2)  and  (a1  or  b0)  and  (a1  or  b1)  and  (a2  or  b0)  and  (a2  or  b1)  and  (b0  or  b1)  and  (a1  or   not a0)  and  (a0  or   not a1  or   not a2  or   not b0  or   not b1); 
 } 
//# -- - - Agregando funcion para bit 50 

bool f_s50(bool a3, bool a2, bool a1, bool a0, bool b3, bool b2, bool b1, bool b0) { 
	return a3  and  b2  and  b3  and  (a1  or  a2)  and  (a1  or  b1)  and  (a2  or  b0)  and  (a2  or  b1)  and  (b0  or  b1)  and  (a0  or   not a1  or   not b0)  and  ( not a1  or   not a2  or   not b0  or   not b1); 
 } 
//# -- - - Agregando funcion para bit 51 

bool f_s51(bool a3, bool a2, bool a1, bool a0, bool b3, bool b2, bool b1, bool b0) { 
	return a3  and  b1  and  b2  and  b3  and  (a0  or  a2)  and  (a0  or  b0)  and  (a2  or  b0)  and  (a1  or   not b0)  and  ( not a0  or   not a1  or   not a2); 
 } 
//# -- - - Agregando funcion para bit 52 

bool f_s52(bool a3, bool a2, bool a1, bool a0, bool b3, bool b2, bool b1, bool b0) { 
	return a2  and  a3  and  b0  and  b1  and  b2  and  b3  and  (a0  or   not a1); 
 } 
//# -- - - Agregando funcion para bit 53 

bool f_s53(bool a3, bool a2, bool a1, bool a0, bool b3, bool b2, bool b1, bool b0) { 
	return a2  and  a3  and  b1  and  b2  and  b3  and  (a1  or  b0)  and  ( not a0  or   not a1  or   not b0); 
 } 
//# -- - - Agregando funcion para bit 54 

bool f_s54(bool a3, bool a2, bool a1, bool a0, bool b3, bool b2, bool b1, bool b0) { 
	return a0  and  a1  and  a2  and  a3  and  b1  and  b2  and  b3  and   not b0; 
 } 
//# -- - - Agregando funcion para bit 55 

bool f_s55(bool a3, bool a2, bool a1, bool a0, bool b3, bool b2, bool b1, bool b0) { 
	return a0  and  a2  and  a3  and  b0  and  b1  and  b2  and  b3  and   not a1; 
 } 
//# -- - - Agregando funcion para bit 56 

bool f_s56(bool a3, bool a2, bool a1, bool a0, bool b3, bool b2, bool b1, bool b0) { 
	return 0; 
 } 
//# -- - - Agregando funcion para bit 57 

bool f_s57(bool a3, bool a2, bool a1, bool a0, bool b3, bool b2, bool b1, bool b0) { 
	return a1  and  a2  and  a3  and  b0  and  b1  and  b2  and  b3; 
 } 
//# -- - - Agregando funcion para bit 58 

bool f_s58(bool a3, bool a2, bool a1, bool a0, bool b3, bool b2, bool b1, bool b0) { 
	return a0  and  a1  and  a2  and  a3  and  b0  and  b1  and  b2  and  b3; 
 }

uint64_t traduce(int base, int expo, func_t* funciones) {

	bool a3 = ((base >> 3) & 1);
	bool a2 = ((base >> 2) & 1);
	bool a1 = ((base >> 1) & 1);
	bool a0 = ((base >> 0) & 1);

	bool b3 = ((expo >> 3) & 1);
	bool b2 = ((expo >> 2) & 1);
	bool b1 = ((expo >> 1) & 1);
	bool b0 = ((expo >> 0) & 1);
	uint64_t resultado = 0;

	//Que trucazo prro sabiendo el numero de bits no siempre se ejecuta todo el modelo :) 
	// LOG28(a ** b) = b * log2(a)
	//float NUM_BITS = ceilf(expo * std::log2f(base));
	//

	/*Optimizacion del proceso mismo JsJS*/
	/*Valido solo en la exponenciacion*/

	auto n_bits = 59;//Aqui calculamos la cuota superior de bits jsjs


	//Formula original para calcular el numero de bits de la exponenciacion 
	//n_bits = log2(base ** expo)
	//por propiedades de los logartimos se hace asi
	//log2(base ** expo) = expo ** log2(base)
	// se reduce el consumo computacional de tal forma asi 
	// expo * binlen(expo)
	// expo * L 
	// se traduce a shifts
	//Ejemplo de calculo en python https://www.online-python.com/xznTyhpv0D



	if (a3) {// Cuando longitud es 4 = 100
		n_bits = (expo << 2);
	} else if (a2) {// Cuando longitud es 3 = 11
		n_bits = (expo << 1) + (expo << 0);
	} else if (a1) {// Cuando longitud es 2 = 10
		n_bits = (expo << 1);
	} else if (a0) {// Cuando longitud es 1 = 1
		n_bits = (expo << 0);
	} else { //siempre se calcula el 1 = 0
		n_bits = 1;
	}

	if (n_bits > 59) {
		n_bits = 59;
	}
	





	/*Valido solo en la exponenciacion*/
	/*Optimizacion del proceso mismo JsJS*/



	for (int i = 0; i < n_bits; i++) {
    	bool r = funciones[i](a3,a2,a1,a0,b3,b2,b1,b0);
    	resultado |= (uint64_t(r) << i);
	}
	return resultado;

}

int main() {

	auto inicio_global = std::chrono::system_clock::now();

std::time_t inicio_time =
    std::chrono::system_clock::to_time_t(inicio_global);

cout << "Inicio: "
     << std::put_time(std::localtime(&inicio_time),
                      "%Y-%m-%d %H:%M:%S")
     << endl;


	func_t funciones[59] = {
		f_s0, 
		f_s1, f_s2, f_s3, f_s4, f_s5, 
		f_s6, f_s7, f_s8, f_s9, f_s10, 
		f_s11, f_s12, f_s13, f_s14, f_s15, 
		f_s16, f_s17, f_s18, f_s19, f_s20, 
		f_s21, f_s22, f_s23, f_s24, f_s25, 
		f_s26, f_s27, f_s28, f_s29, f_s30, 
		f_s31, f_s32, f_s33, f_s34, f_s35, 
		f_s36, f_s37, f_s38, f_s39, f_s40, 
		f_s41, f_s42, f_s43, f_s44, f_s45, 
		f_s46, f_s47, f_s48, f_s49, f_s50, 
		f_s51, f_s52, f_s53, f_s54, f_s55, 
		f_s56, f_s57, f_s58
	};	


/*
	for (int base = 0; base <= 15; base ++) {
		for (int expo =0;  expo <= 15; expo ++) {
			uint64_t pow = std::pow(base, expo);
			uint64_t powb = traduce(base, expo, funciones);
			bool eq = pow == powb;
			cout << "Math.Pow base exponente = a ** b, " << base << " ** " << expo << " = " << powb << ", " << pow << (eq ? " - SI -":"- NO -")<< endl;
		}
	}
	return 0;
*/
	const int N = 1000; // 
    std::vector<long long> phantom(N);
    std::vector<long long> original(N);
    std::vector<long long> diff(N); // aquí guardaremos las diferencias


    cout << "Operacion, base ** expo = resultadoPhantom = std::pow, Iguales" << endl;
	for (int a = 0; a < N; a++ ) {
		//cout << "vuelta "<< a << endl;
		//cout << "Inicio de Phantom" << endl;
		auto inicio = chrono::high_resolution_clock::now();
		for (int base = 0; base <= 15; base ++) {
			for (int expo =0;  expo <= 15; expo ++) {
				//uint64_t powb = std::pow(base, expo);
				volatile uint64_t powb = traduce(base, expo, funciones);
				//powb += 1;
				//bool eq = pow == powb;
				//cout << "a**b, " << base << " ** " << expo << " = " << powb << endl;
				//cout << "a**b, " << base << " ** " << expo << " = " << powb << " = " << pow << (eq ? " - Si - " : " - No - ") << endl;
			}
		}

		auto fin = chrono::high_resolution_clock::now();
    	auto duracion = chrono::duration_cast<chrono::nanoseconds>(fin - inicio);
    	phantom[a] = duracion.count();


    	/*
    	cout << "Inicio de Math.pow" << endl;
    	auto inicio2 = chrono::high_resolution_clock::now();
		for (int base = 0; base <= 15; base ++) {
			for (int expo =0;  expo <= 15; expo ++) {
				uint64_t pow = std::pow(base, expo);
				//uint64_t powb = traduce(base, expo);
				//bool eq = pow == powb;
				cout << "Math.Pow base exponente = a**b, " << base << " ** " << expo << " = " << pow << endl;
			}
		}

		auto fin2 = chrono::high_resolution_clock::now();
		auto duracion2 = chrono::duration_cast<chrono::nanoseconds>(fin2 - inicio2);
		cout << " New : " << duracion.count() << " ns " << endl;
		cout << " Old : " << duracion2.count() << " ns " << endl;

        phantom[a] = duracion.count();
        original[a] = duracion2.count();

        diff[a] = original[a] - phantom[a]; // diferencia
        */

}



long long min = LLONG_MAX;
long long max = LLONG_MIN;
long long suma = 0;
//auto promedio = 0;

for(int i= 0; i < N ; i++) {
	
		suma +=  phantom[i];
	
	
	//double perc = (original[i] - phantom[i]) / (double)original[i] * 100.0;

	if (min > phantom[i] ) {
		min = phantom[i];
	}

	if (max < phantom[i] ) {
		max = phantom[i];	
	}

	//cout << "Ejecucion : " << i << ": Phantom : " << phantom[i] << endl; 
	/*
	cout << "Ejecucion " << i << " Phantom: " << phantom[i] 
     << " Original: " << original[i]  
     << " Diff: " << diff[i] 
     << ", % " << perc 
     << endl;
     */
}

cout << "Minimo : " << min << ": Maximo : " << max << endl; 


double promedio = static_cast<double>(suma) / N;

cout << "Promedio : " << (promedio) << endl; 

// SEGUNDO FOR → Se usa el promedio para stddev
double suma_diff = 0.0;
for (int i = 0; i < N; i++) {
    double diff = phantom[i] - promedio;
    suma_diff += diff * diff;
}

double stddev = sqrt(suma_diff / N);


/*Calculo de la median*/
vector<long long> copia = phantom;
sort(copia.begin(), copia.end());
double mediana = (N % 2 == 0)
    ? (copia[N/2 - 1] + copia[N/2]) / 2.0
    : copia[N/2];

cout << "Mediana : " << mediana << endl; 

double cv = stddev / promedio;

cout << "Desviación estándar: " << stddev << endl;
cout << "Coeficiente de variación: " << cv << endl;


/*cosas aleatorias*/
/*Calculo de la mediana*/




cout << "P90 : " << copia[(int)(N * 0.90)] << endl;
cout << "P95 : " << copia[(int)(N * 0.95)] << endl;
cout << "P99 : " << copia[(int)(N * 0.99)] << endl;


auto fin_global = std::chrono::system_clock::now();

std::time_t fin_time =
    std::chrono::system_clock::to_time_t(fin_global);

cout << "Fin: "
     << std::put_time(std::localtime(&fin_time),
                      "%Y-%m-%d %H:%M:%S")
     << endl;

cout << "Compilador   : Apple Clang " << __clang_major__ << "." << __clang_minor__ << endl;

    return 0;
}
