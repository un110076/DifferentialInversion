// naumann@stce.rwth-aachen.de

#include "Eigen/Dense"
#include "dco.hpp"
#include <iostream>

#include "F.h"
#include "Euler.h"
 
std::pair<VT<double>,MT<double>> E_dEdx(VT<double> x) {
  Eigen::Vector<typename dco::gt1v<double,DIM>::type,DIM> x_t;
  for (int i=0;i<DIM;i++) {
    x_t(i)=x(i);
    dco::derivative(x_t(i))[i]=1;
  }
  x_t=E(x_t);
  MT<double> E_x;
  for (int i=0;i<DIM;i++) {
    x(i)=dco::value(x_t(i));
    for (int j=0;j<DIM;j++)
      E_x(i,j)=dco::derivative(x_t(i))[j];
  }
  return std::make_pair(x,E_x);
}

VT<double> DifferentialInverse(const VT<double> &x) {
  std::pair<VT<double>,MT<double>> p=E_dEdx(x);
  return p.second.lu().solve(p.first);
}

#include "main.h"
