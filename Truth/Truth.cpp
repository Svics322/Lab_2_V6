#pragma once
#include"Truth.h"

using namespace std;

bool Truth::isEnded() {
	return this->p != true && this->q != true && this->r != true;
}

bool Truth::checkImplication(bool a, bool b) {
	return !a || b;
};

bool Truth::checkDisjunction(bool a, bool b) {
	return a || b;
}

bool Truth::getFirstImplication() {
	return !this->p || this->q;
}

bool Truth::getSecondImplication() {
	return !this->p || this->r;
}

bool Truth::getImplicationsDisjunction() {
	return checkImplication(getFirstImplication(), getSecondImplication());
}
void Truth::Display() {
	cout << R"(                 a       b    )" << endl;
	cout << "________________________________________" << endl;
	cout << "| p | q | r | p -> q | p -> r | a OR b |" << endl;
	cout << "|___|___|___|________|________|________|" << endl;

	for (int i = 7; i >= 0; i--) {
		this->p = i & 4;
		this->q = i & 2;
		this->r = i & 1;

		bool fImpl = checkImplication(p, q);
		bool sImpl = checkImplication(p, r);

		cout << "| " << p << " | " << q << " | " << r << " |";
		cout << "   " << fImpl << "    |    " <<  sImpl << "   |    ";
		cout << checkDisjunction(fImpl, sImpl) << "   |" << endl;

		cout << "|___|___|___|________|________|________|" << endl;
	}
}

Truth::Truth() {
	Display();
}

Truth::Truth(bool p, bool q, bool r) {
	this->p = p;
	this->q = q;
	this->r = r;
}