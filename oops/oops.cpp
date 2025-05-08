#include <iostream>
#include <string>

using namespace std;

class Teacher
{
private:
    double salary;

public:
    string name;
    string dept;
    string subject;
    // non-parametrized constructor
    Teacher()
    {
        cout << "Hi I m a Teacher\n";
    }
    // parametrized constructor
    Teacher(string name, string dept, string subject, double salary)
    {
        this->name = name;
        this->dept = dept;
        this->subject = subject;
        this->salary = salary;
    }
    // copy constructor
    Teacher(Teacher &obj)
    {
        this->name = obj.name;
        this->dept = obj.dept;
        this->subject = obj.subject;
        this->salary = obj.salary;
    }

    void changeDept(string newDept)
    {
        dept = newDept;
    }
    // member functions
    // setter
    void setSalary(double _salary)
    {
        salary = _salary;
    }
    // getter
    double getSalary()
    {
        return salary;
    }
    // getter function
    void getInfo()
    {
        cout << "Name " << name << endl;
        cout << "Subject " << subject << endl;
    }
};

class Account
{
private: // data hiding
    double balance;
    string accountId;

public:
    string accountName;
};

class Student
{
public:
    string name;
    double *cgpaPtr;

    Student(string name, double cgpa)
    {
        this->name = name;
        cgpaPtr = new double;
        *cgpaPtr = cgpa;
    }
    Student(Student &s)
    {
        this->name = s.name;
        cgpaPtr = new double; // deep copy
        *cgpaPtr = *(s.cgpaPtr);
    }
    // Destructor
    ~Student()
    {
        cout << "Hi I m destructor\n";
        delete cgpaPtr;
    }
    void getInfo()
    {
        cout << "Name: " << name << endl;
        cout << "CGPA: " << (*cgpaPtr) << endl;
    }
};

class Person
{
public:
    string name;
    int age;

    Person()
    {
        cout << "Hi I m parent constructor\n";
    }
    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }

    ~Person()
    {
        cout << "Hi I m parent destructor\n";
    }
};

class Intern : public Person
{
public:
    int internId;
    Intern()
    {
        cout << "Hi I m child constructor\n";
    }
    Intern(string name, int age, int internId) : Person(name, age)
    {
        this->internId = internId;
    }
    ~Intern()
    {
        cout << "Hi I m child destructor\n";
    }
    void getInfo()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Roll Number: " << internId << endl;
    }
};

class Calculator
{
public:
    int add(int a, int b)
    {
        return a + b;
    }
    // function overloading
    int add(int a, int b, int c)
    {
        return a + b + c;
    }
    // function to add double
    // function overloading
    double add(double a, double b)
    {
        return a + b;
    }
};

class Animal
{
public:
    virtual void makeSound()
    {
        cout << "Animal makes a sound.\n";
    }
};

class Dog : public Animal
{
public:
    void makeSound()
    {
        cout << "Dog barks.\n";
    }
};

class Cat : public Animal
{
public:
    void makeSound()
    {
        cout << "Cat Meows.\n";
    }
};

class Shape
{
public:
    // Virtual function to calculate area
    virtual void area()
    {
        cout << "Area of shape cannot be determined" << endl;
    }
};

// Derived class Circle
class Circle : public Shape
{
private:
    double radius;

public:
    // Constructor to initialize radius
    Circle(double r)
    {
        radius = r;
    }

    // Overriding area() function
    void area()
    {
        cout << "Area of Circle: " << M_PI * radius * radius << endl;
    }
};

// Derived class Rectangle
class Rectangle : public Shape
{
private:
    double length, width;

public:
    // Constructor to initialize length and width
    Rectangle(double l, double w)
    {
        length = l;
        width = w;
    }

    // Overriding area() function
    void area()
    {
        cout << "Area of Rectangle: " << length * width << endl;
    }
};

void func()
{
    static int x = 0;
    cout << "x " << x << endl;
    x = x + 1;
}

class ABC
{
public:
    ABC()
    {
        cout << "constructor\n";
    }
    ~ABC()
    {
        cout << "destructor\n";
    }
};
int main()
{
    // Teacher t1("Aman", "CS", "C++", 25002);
    //  t1.getInfo();
    // Teacher t2(t1); // copy constructor
    //  t2.getInfo();
    //  Student s1("Rahul", 8.92);
    //  Student s2(s1);
    //  s2.name = "Neha";
    //  s1.getInfo();
    //  *(s2.cgpaPtr) = 9.2;
    //  s2.getInfo();
    // Intern i1("AMAN", 25, 112);
    // i1.getInfo();
    // Calculator calc;
    // cout << calc.add(1, 2) << endl;
    // cout << calc.add(1.1, 2.2) << endl;
    // Animal *animalPtr;
    // Dog d1;
    // animalPtr = &d1;
    // animalPtr->makeSound();
    // Cat c1;
    // animalPtr = &c1;
    // animalPtr->makeSound();
    // Shape *shapePtr;
    // Circle c1(5.0);
    // shapePtr = &c1;
    // shapePtr->area();
    // Rectangle r1(4.0, 6.0);
    // shapePtr = &r1;
    // shapePtr->area();
    // func();
    // func();
    // func();
    if (true)
    {
        static ABC obj;
    }
    cout << "end of main program\n";
}