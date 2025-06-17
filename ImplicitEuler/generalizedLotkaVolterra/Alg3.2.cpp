// naumann@stce.rwth-aachen.de

#include "Eigen/Dense"
#include <iostream>

#include "F.h"
#include "Euler.h"
 
std::pair<VT<double>,MT<double>> E_dEdx(VT<double> x) {
  MT<double> E_x=MT<double>::Identity();
  for (int i=0;i<N_STEPS;i++) {
    x=N(x);
    E_x=dFdx(x).lu().solve(E_x);
  }
  return std::make_pair(x,E_x);
}

VT<double> DifferentialInverse(const VT<double> &x) {
  std::pair<VT<double>,MT<double>> p=E_dEdx(x);
  return p.second.lu().solve(p.first);
}

#include "main.h"
