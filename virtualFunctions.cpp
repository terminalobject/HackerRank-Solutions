/*
 This problem is to get you familiar with virtual functions. Create three classes Person, Professor and Student. The class Person should have data members name and age. The classes Professor and Student should inherit from the class Person.

The class Professor should have two integer members: publications and cur_id. There will be two member functions: getdata and putdata. The function getdata should get the input from the user: the name, age and publications of the professor. The function putdata should print the name, age, publications and the cur_id of the professor.

The class Student should have two data members: marks, which is an array of size  and cur_id. It has two member functions: getdata and putdata. The function getdata should get the input from the user: the name, age, and the marks of the student in  subjects. The function putdata should print the name, age, sum of the marks and the cur_id of the student.

For each object being created of the Professor or the Student class, sequential id's should be assigned to them starting from .

Solve this problem using virtual functions, constructors and static variables. You can create more data members if you want.
 */
class Person {
public:
    string name;
    int age;
    virtual void getdata() {
        cin >> this->name >> this->age;
    }
    virtual void putdata() {
        cout << this->name << " " << this->age << endl;
    }
};

class Professor : public Person {
public:
    Professor() {
        this->cur_id = ++id;
    }
    int publications;
    static int id;
    int cur_id;
    void getdata() {
        cin >> this->name >> this->age >> this->publications;
    }
    void putdata() {
        cout << this->name << " "
            << this->age << " "
            << this->publications << " "
            << this->cur_id << endl;
    }
};
int Professor::id = 0;

class Student : public Person {
#define NUM_OF_MARKS 6
public:
    Student() {
        this->cur_id = ++id;
    }
    int marks[NUM_OF_MARKS];
    static int id;
    int cur_id;
    void getdata() {
        cin >> this->name >> this->age;
        for (int i=0; i<NUM_OF_MARKS; i++) {
            cin >> marks[i];
        }
    }
    void putdata() {
        int marksSum = 0;
        for (int i=0; i<NUM_OF_MARKS; i++) {
            marksSum += marks[i];
        }
        cout << this->name << " "
            << this->age << " "
            << marksSum << " "
            << this->cur_id << endl;
    }
};
int Student::id = 0;
