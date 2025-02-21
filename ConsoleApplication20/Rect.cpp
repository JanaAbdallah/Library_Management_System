#include "Rect.h"
#include <iostream>
using namespace std;
Rect::Rect(float w, float l) : length(l), width(w) {
	cout << "hello" << endl;
}
Rect :: ~Rect() {
	cout << "THE END" <<endl;
}
 
float Rect::getlength() {
	return length;
}
float Rect ::getwidth() {
	return width;
}
void Rect:: setlength(float l) {
	length = l;
	if (l < 0) {
		cout << "please enter a +ve num" << endl;
	}
}
void Rect :: setwidth(float w) {
	width = w;
	if (w < 0) {
		cout << "please enter a +ve num" << endl;
	}
}
float Rect::getarea(){
	return length * width;
}
