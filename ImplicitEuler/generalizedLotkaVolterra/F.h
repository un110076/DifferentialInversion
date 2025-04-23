// naumann@stce.rwth-aachen.de

#include "Eigen/Dense"
#include "dco.hpp"

template <typename T>
using VT=Eigen::Vector<T,DIM>;

template <typename T>
using MT=Eigen::Matrix<T,DIM,DIM>;

MT<double> A=MT<double>::Identity()+MT<double>::Random()/DIM;
VT<double> r=VT<double>::Random()/DIM-VT<double>::Ones();

template <typename T>
VT<T> G(const VT<T> &x)  {
  VT<T> y;
  for (int i=0;i<DIM;++i) 
    y(i)=x(i)*(r(i)+A.row(i).dot(x));
  return y;
}

template <typename T>
MT<T> dGdx(const VT<T> &x) {
  MT<T> G_x;
  for (int i=0;i<DIM;++i) 
    for (int j=0;j<DIM;++j) 
      if (i==j) 
        G_x(i,i)=r(i)+A.row(i).dot(x)+x(i)*A(i,i);
      else 
        G_x(i,j)=x(i)*A(i,j);
  return G_x;
}

template<typename T> 
VT<T> F(const VT<T> &x, const VT<T> &x_prev) {
  return x-x_prev-G(x)/N_STEPS;
}

template<typename T>
MT<T> dFdx(const VT<T> &x) {
  return MT<T>::Identity()-dGdx(x)/N_STEPS;
}
