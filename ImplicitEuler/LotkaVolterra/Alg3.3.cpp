#include "Eigen/Dense"
#include <stack>
#include <iostream>

#include "F.h"
#include "Euler.h"

std::stack<MT<double>> tape;

template<>
VT<double> N(VT<double> x) {
  VT<double> x_prev=x,r=F(x,x_prev);
  do {
    x=x+dFdx(x).lu().solve(-r);
    r=F(x,x_prev);
  } while (r.norm()>R_PREC);
  tape.push(dFdx(x));
  return x;
}

VT<double> DifferentialInverse(VT<double> x) {
  x=E(x);
  while (!tape.empty()) { x=tape.top()*x; tape.pop(); }
  return x;
}

#include "main.h"
