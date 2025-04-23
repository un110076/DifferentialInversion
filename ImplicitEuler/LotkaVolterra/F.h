#include "Eigen/Dense"

const int n=2;

template<typename T>
using VT=Eigen::Vector<T,n>;

template<typename T>
using MT=Eigen::Matrix<T,n,n>;

template<typename T>
VT<T> G(const VT<T> &x) {
  VT<T> r;
  r(0)=1.1*x(0)-0.5*x(0)*x(1); // prey
  r(1)=-0.75*x(1)+0.25*x(0)*x(1); // predators
  return r;
}

template<typename T>
MT<T> dGdx(const VT<T> &x) {
  MT<T> Gx;
  Gx(0,0)=1.1-0.5*x(1); 
  Gx(0,1)=-0.5*x(0); 
  Gx(1,0)=0.25*x(1); 
  Gx(1,1)=-0.75+0.25*x(0); 
  return Gx;
}

template<typename T>
VT<T> F(const VT<T> &x, const VT<T> &x_prev) {
  return x-x_prev-G(x)/N_STEPS;
}

template<typename T>
MT<T> dFdx(const VT<T> &x) {
  return MT<T>::Identity()-dGdx(x)/N_STEPS;
}

