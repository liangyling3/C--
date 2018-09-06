1 // interface Iterator
2 class Iterator
3 {
4 public:
5 		virtual bool hasNext() = 0;
6 		virtual double next() = 0;
7 };
89
// interface Iterable
10 class Iterable
11 {
12 public:
13 		virtual Iterator * getIterator() = 0;
14 };
15
16 // polymorphism function
17 void writeToFile(const char filename[],Iterable & iterable) 
18 {
19 		Iterator * it = iterable.getIterator();
20 		ofstream out(filename);
21 		while ((*it).hasNext()) {
22 			double value = (*it).next();
23 			out << value << " ";
24 		}
25 		out.close();
26 		delete it;
27 }
28
29 // implementation of Iterable
30 class FixedLengthVector : public Iterable
31 {
32 private:
33 		int length;
34 		double * array;
35
36 public:
37 		FixedLengthVector(int length1) {
38 			length = length1;
39 		array = new double[length];
40 		}
41
42 ~FixedLengthVector() {
43 		delete [] array;
44 }
45
46 double & operator [] (int index) {
47 		return array[index];
48 }
49
50 private:
51
52 // implementation of Iterator
53 class Iterator1 : public Iterator
54 {
55 private:
56 FixedLengthVector * vector;
57 int nextIndex;
58
59 public:
60 Iterator1(FixedLengthVector * vector1) {
61 vector = vector1;
62 nextIndex = 0;
63 }
64
65 // overrides
66 bool hasNext() {
67 return (nextIndex < (*vector).length);
68 }
69
70 // overrides
71 double next() {
72 ++ nextIndex;
73 return (*vector).array[nextIndex - 1];
74 }
75 }; // end of inner-class
76
77 public:
78 // overrides
79 Iterator * getIterator() {
80 return new Iterator1(this);
81 }
82 };
83
84 int main() {
85 FixedLengthVector vector(10);
86 for (int i = 0; i < 10; ++ i) {
87 vector[i] = 1 + i;
88 }
89 writeToFile("1.txt", vector);
90 }
