#include "TMember.h"

using namespace Polynomial;

TMember::TMember() {
	this->FRatio = 0;
	this->FDegree = 0;
}

TMember::TMember(int ratio, int deg) {
	this->FRatio = ratio;
	this->FDegree = deg;
}

int TMember::get_degree()
{
	return this->FDegree;
}

int TMember::get_ratio()
{
	return this->FRatio;
}

void TMember::set_degree(int deg)
{
	this->FDegree = deg;
}

void TMember::set_ratio(int ratio)
{
	this->FRatio = ratio;
}

bool Polynomial::operator<(const TMember& c1, const TMember& c2)
{
	return !(c1.FDegree < c2.FDegree);
}

bool Polynomial::operator==(const TMember& c1, const TMember& c2)
{
	return (c1.FRatio == c2.FRatio &&
		c1.FDegree == c2.FDegree);
}

bool Polynomial::operator!= (const TMember& c1, const TMember& c2)
{
	return !(c1 == c2);
}

std::string Polynomial::TMember::to_string()
{
	if (this->FRatio == 0) {
		return std::to_string(this->FRatio);
	}
	if (this->FDegree == 0) {
		return std::to_string(this->FRatio);
	}

	if (this->FDegree == 1) {
		if (this->FRatio == 1) {
			return "x";
		}
		else {
			return std::to_string(this->FRatio) + "x";
		}

	}

	if (this->FRatio == 1) {
		return "x^" + std::to_string(this->FDegree);
	}
	else {
		return std::to_string(this->FRatio) + "x^" + std::to_string(this->FDegree);
	}
}

TMember TMember::diff()
{
	if (this->FDegree == 0) return TMember();

	int new_r = this->FRatio * this->FDegree;
	int new_deg = this->FDegree - 1;
	return TMember(new_r, new_deg);
}

double TMember::calc(int x) {
	return this->FRatio * pow(x, this->FDegree);
}