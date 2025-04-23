int main(){
  VT<double> x=VT<double>::Ones();
  std::cout.precision(15);
  std::cout << DifferentialInverse(x) << std::endl << E(x) << std::endl;
  return 0;
}
