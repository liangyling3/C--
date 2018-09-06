1 class A // an abstract class
2 {
3 public:
4 // a pure virtual function
5 virtual void print() const = 0;
6 };
78
void task1(const A & reference) {
9 reference.print(); // late binding
10 }
11
12 class B : public A // B implements A
13 {
14 public:
15 // overrides A::print2()
16 virtual void print() const {
17 cout << "B::print()" << endl;
18 }
19 };
20
21 // C also implements A
22 class C : public A
23 {
24 public:
25 // overrides A::print2()
26 virtual void print() const {
27 cout << "C::print()" << endl;
28 }
29 };
30
31 int main() {
32 A a;
33 task1(B());
34 task1(C());
35 }
