#pragma once
#include <iostreamm>
#include <string>
#include <list>

class BigInteger {
public:
	BigInteger();
	BigInteger(const int &);
	BitInteger(const std::string &);
	~BigInteger();
	BigInteger(const BigInteger &);
public:
	BigInteger operator+(const BigInteger &) const;
	BigInteger operator-(const BigInteger &) const;
	BigInteger operator*(const BigInteger &) const;
	BigInteger operator/(const BigInteger &) const;

        BigInteger& operator+=(const BigInteger &);
        BigInteger& operator-=(const BigInteger &);
        BigInteger& operator*=(const BigInteger &);
        BigInteger& operator/=(const BigInteger &);

	BigInteger operator<<(const BigInteger &) const;
	BigInteger operator<<(const int &) const;
	BigInteger operator>>(const BigInteger &) const;
	BigInteger operator>>(const int &) const;
public:
	friend std::ostream& operator<<(std::ostream &, \
			const BigInteger &) const;
	friend std::istream& operator>>(std::istream &, \
			const BigInteger &) const;
private:
	std::list<int> intlist;
	int len;
	enum FLAG {
		pos = 1,
		nag = -1,
		zero = 0
	} flag;
};



