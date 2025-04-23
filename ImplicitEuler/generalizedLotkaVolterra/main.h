// naumann@stce.rwth-aachen.de

int main(){
  VT<double> x=VT<double>::Random().cwiseAbs();
  std::cout.precision(15);
  std::cout << DifferentialInverse(x).norm() << std::endl;
  return 0;
}



