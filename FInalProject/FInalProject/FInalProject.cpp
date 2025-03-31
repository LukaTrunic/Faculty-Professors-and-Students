#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Person {
public:
    virtual string getName() const = 0;
    virtual void setName(const string& name) = 0;
    virtual int getAge() const = 0;
    virtual void setAge(int age) = 0;
};

class Student : public Person {
public:
    string getName() const override { return Name; }
    void setName(const string& name) override { Name = name; }

    int getAge() const override { return Age; }
    void setAge(int age) override { Age = age; }

    string getMajor() const { return Major; }
    void setMajor(const string& major) { Major = major; }

    int getScore() const { return Score; }
    void setScore(int score) { Score = score; }

    bool operator==(const Student& s) const {
        return (Age == s.Age);
    }

private:
    string Name;
    int Age;
    string Major;
    int Score;
};

class Professor : public Person {
public:
    string getName() const override { return Name; }
    void setName(const string& name) override { Name = name; }

    int getAge() const override { return Age; }
    void setAge(int age) override { Age = age; }

    string getClass() const { return Class; }
    void setClass(const string& researchArea) { Class = researchArea; }

private:
    string Name;
    int Age;
    string Class;
};

class Course {
public:
    string getName() const { return Name; }
    void setName(const string& name) { Name = name; }

    Professor* getProfessor() const { return Professorr; }
    void setProfessor(Professor* professor) { Professorr = professor; }

    void saveToFile(const string& filename) const {
        ofstream outfile(filename);

        outfile << Name << endl;
        outfile << Professorr->getName() << endl;

        outfile.close();
    }

    void loadFromFile(const string& filename) {
        ifstream infile(filename);

        getline(infile, Name);
        infile.ignore();

        string professorName;
        getline(infile, professorName);
        Professor* professor = new Professor();
        professor->setName(professorName);
        Professorr = professor;

        infile.close();
    }

private:
    string Name;
    Professor* Professorr;
};

class Assignment {
public:
    Assignment() : Points(0) {}
    Assignment(const string& name, int points) : Name(name), Points(points) {}

    string getName() const { return Name; }
    void setName(const string& name) { Name = name; }

    int getPoints() const { return Points; }
    void setPoints(int points) { Points = points; }

private:
    string Name;
    int Points;
};

class myClass {
public:
    void run() {
        Student luka;
        luka.setName("Luka");
        luka.setAge(20);
        luka.setMajor("Computer Science");

        Student marko;
        marko.setName("Marko");
        marko.setAge(22);
        marko.setMajor("Mathematics");

        Student janko;
        janko.setName("Janko");
        janko.setAge(21);
        janko.setMajor("Physics");

        Professor milos;
        milos.setName("Milos");
        milos.setAge(55);
        milos.setClass("Computer Science");

        Professor milica;
        milica.setName("Milica");
        milica.setAge(40);
        milica.setClass("Data Science");

        vector<Person*> people = { &luka, &marko, &janko, &milos, &milica };

        sort(people.begin(), people.end(), [](Person* a, Person* b) {
            return a->getAge() < b->getAge();
            });
        for (const auto& person : people) {
            cout << person->getName() << " is " << person->getAge() << " years old." << endl;
        }

        cout << "\n";

        Course cs101;
        cs101.setName("Introduction to Computer Science");
        cs101.setProfessor(&milos);
        cs101.saveToFile("cs101.txt");

        Course cs102;
        cs102.loadFromFile("cs101.txt");
        cout << "Course Name: " << cs102.getName() << endl;
        cout << "Professor Name: " << cs102.getProfessor()->getName() << endl;

        cout << "\n";

        if (luka == marko) {
            cout << "Luka and Marko are same age." << endl;
        }
        else {
            cout << "Luka and Marko are different age." << endl;
        }

        cout << "\n";

        vector<Student*> students = { &luka, &marko, &janko };

        Assignment assignment;
        assignment.setName("OOP2");
        assignment.setPoints(100);
        luka.setScore(75);
        marko.setScore(40);
        janko.setScore(90);
        for (Student* student : students) {
            if (student->getScore() > 50 && student->getScore() < 100) {
                cout << student->getName() << " passed the " << assignment.getName() << " assignment." << endl;
            }
            else {
                cout << student->getName() << " did not pass the " << assignment.getName() << " assignment." << endl;
            }
        }
    }
};

int main() {
    myClass c;
    c.run();
    return 0;
}
