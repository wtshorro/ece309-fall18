class IntInf{
public:
  int num;
  bool posInf;
  bool negInf;
  IntInf(int n = 0, bool Inf = false, bool nInf = false){
    num = n;
    posInf = Inf;
    negInf = nInf;
  }
  bool getPosInf() const;
  bool getNegInf() const;
  int getNum() const;
  IntInf& operator=(const int& rhs);
  IntInf& operator=(const IntInf& rhs);;
  bool operator>(const IntInf& rhs) const;
  bool operator<(const IntInf& rhs) const;
  bool operator==(const IntInf& rhs) const;
  IntInf operator/(const IntInf& rhs)const;
  IntInf operator*(const IntInf& rhs)const;
  IntInf operator+(const IntInf& rhs)const;
  IntInf operator-(const IntInf& rhs)const;
  void print();
};
