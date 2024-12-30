#include<iostream>
#include<cmath>

template <typename T>
class Standard
{
private:
	T value;
public:
	Standard(T value) {
		this->value = value;
	}
	Standard& operator+(T x) {
		this->value = this->value + x;
		return *this;
	}
	Standard& operator-(T x) {
		this->value = this->value - x;
		return *this;
	}
	Standard& operator*(T x) {
		this->value = this->value * x;
		return *this;
	}
	Standard& operator/(T x) {
		if (x == 0)
		{
			throw "Деление на ноль запрещено";
		}
		else
		{
			this->value = this->value / x;
		}
		return *this;
	}

	void setValue(T value) {
		this->value = value;
	}
	T getValue() const {
		return this->value;
	}

};





