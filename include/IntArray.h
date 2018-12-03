namespace ece309{
class IntArray {
private:
   int *array;
   int length;
public:
   IntArray(const char*);
   IntArray(int,int);
   int& operator[](int index);
   IntArray& operator+=(const IntArray &rhs);
   IntArray operator+(const IntArray &rhs) const;
   IntArray operator-(const IntArray &rhs) const;
   IntArray operator*(int x) const;
   IntArray operator/(int x) const;
   IntArray operator>>(int count) const;
   IntArray operator<<(int count) const;
   operator char*() const;
   operator int() const;
   int get(int);
   void set(int,int);
   int getLength();

};
}
