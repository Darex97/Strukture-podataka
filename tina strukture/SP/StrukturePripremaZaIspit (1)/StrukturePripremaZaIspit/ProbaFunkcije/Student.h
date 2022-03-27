#pragma once
#include <iostream>
using namespace std;
class Student {
private:
	string ime;
	string prezime;
	int index;
public:
	Student(string ime, string prezime,int index) {
		this->ime = ime;
		this->prezime = prezime;
		this->index = index;
	}
	Student() { ime = prezime = ""; index = 0; }
	~Student() { }
	unsigned int getIndex() { return index; }
	Student& operator=(const Student& s) {
		ime = s.ime;
		prezime = s.prezime;
		index = s.index;
		return *this;
	}
	bool operator==(const Student& s) {
		return s.index == index;
	}
	friend ostream&  operator<<(ostream& ispis, Student const& s){
		ispis << s.ime << " " << s.prezime << " " << s.index;
		return ispis;
	}
};