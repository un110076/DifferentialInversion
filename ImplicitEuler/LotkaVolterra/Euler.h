template<typename T>
VT<T> N(VT<T> x) {
  VT<T> x_prev=x,r=F(x,x_prev);
  do {
    x=x+dFdx(x).lu().solve(-r);
    r=F(x,x_prev);
  } while (r.norm()>R_PREC);
  return x;
}

template<typename T>
VT<T> E(VT<T> x) { 
  for (int i=0;i<N_STEPS;i++) x=N(x); 
  return x;
}

