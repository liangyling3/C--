1 class Student
2 {
3 public:
4 int id;
5 string name;
6 double GPA; // grade point average
7 };
8
9 // interface
10 class Comparator
11 {
12 public:
13 virtual bool isLarger(Student &, Student &)
14 const = 0;
15 };
16
17 // polymorphism function
18 void sort(vector<Student> & students,
19 const Comparator & comparator) {
20 int size = students.size();
21 for (int i = size - 1; i > 0; -- i) {
22 for (int j = 0; j < i; ++ j) {
23 Student & s1 = students[j];
24 Student & s2 = students[j + 1];
25 if (comparator.isLarger(s1, s2)) {
26 Student temp = s1;
27 s1 = s2;
28 s2 = temp;
29 }
30 }
31 }
32 }
33
34 // implementation 1
35 class IdComparator : public Comparator
36 {
37 // overrides
38 bool isLarger(Student & s1, Student & s2) const {
39 return s1.id > s2.id;
40 }
41 };
42
43 // implementation 2
44 class NameComparator : public Comparator45 {
46 bool isLarger(Student & s1, Student & s2) const {
47 return s1.name > s2.name;
48 }
49 };
50
51 // implementation 3
52 class GPAComparator : public Comparator
53 {
54 bool isLarger(Student & s1, Student & s2) const {
55 return s1.GPA > s2.GPA;
56 }
57 };
58
59 void print(vector<Student> & students) {
60 cout << "students = " << endl;
61 for (int i = 0; i < students.size(); ++ i) {
62 cout << students[i].id << " " <<
63 students[i].name << " " <<
64 students[i].GPA << endl;
65 }
66 }
67
68 int main() {
69 vector<Student> students;
70 for (int i = 0; i < 10; ++ i) {
71 Student s;
72 s.id = (5 + i) % 10 + 1;
73 s.name = "name0";
74 s.name[4] += 9 - i;
75 s.GPA = 3 + 0.05 * (i % 3);
76 students.push_back(s);
77 }
78 print(students);
79
80 sort(students, IdComparator());
81 print(students);
82
83 sort(students, NameComparator());
84 print(students);
85
86 sort(students, GPAComparator());
87 print(students);
88 }
