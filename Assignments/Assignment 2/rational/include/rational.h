#ifndef _6S096_RATIONAL_H
#define _6S096_RATIONAL_H

#include <cstdint>
#include <iosfwd>
#include <stdexcept>

class Rational {
  intmax_t _num, _den;
public:
  enum sign_type { POSITIVE, NEGATIVE };

  Rational() : _num{0}, _den{1} {}
  Rational( intmax_t numer ) : _num{numer}, _den{1} {}
  Rational( intmax_t numer, intmax_t denom ) : _num{numer}, _den{denom} { normalize(); }

  inline intmax_t num() const { return _num; }
  inline intmax_t den() const { return _den; }

  // You should implement all of these functions in rational.cpp
  void normalize();
  float to_float() const;
  double to_double() const;
  sign_type sign() const;
  const Rational inverse() const;
};

std::ostream& operator<<( std::ostream &os, const Rational &ratio );

inline bool operator==( const Rational &lhs, const Rational &rhs ) {
  // You should implement
}

inline bool operator<( const Rational &lhs, const Rational &rhs ) {
  // You should implement
}

// This one is completed for you. We multiply two Rationals
// by creating a new Rational as shown:
//
//  a.num()   b.num()   a.num() * b.num()
//  ------- * ------- = -----------------
//  a.den()   b.den()   a.den() * b.den()
//
// Our constructor should automatically reduce it to lowest terms,
// e.g. 1/2 * 2/3 = 1/3 automatically.
inline Rational operator*( const Rational &a, const Rational &b ) {
  return Rational{ a.num() * b.num(), a.den() * b.den() };
}

inline Rational operator+( const Rational &a, const Rational &b ) {
  // You should implement
}

inline Rational operator-( const Rational &a, const Rational &b ) {
  // You should implement
}

inline Rational operator/( const Rational &a, const Rational &b ) {
  // You should implement
}

class bad_rational : public std::domain_error {
public:
  explicit bad_rational() : std::domain_error( "Bad rational: zero denominator" ) {}
};

#endif // _6S096_RATIONAL_H
