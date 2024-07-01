#include <iostream>
#include <cstring>
using namespace std;

class Human {
public:
    char* name;
    int age;

    Human() : Human("NoInfo", 0) {}

    Human(const char* n, int a) {
        size_t len = strlen(n) + 1;
        name = new char[len];
        strcpy_s(name, len, n);
        age = a;
    }

    Human(const Human& copy) {
        size_t len = strlen(copy.name) + 1;
        name = new char[len];
        strcpy_s(name, len, copy.name);
        age = copy.age;
    }

    ~Human()
    {
        delete[] name;
    }
};

class Apartment {
public:
    int countH;
    int sizeroom;
    Human* arrA;

    Apartment() : Apartment(3) {}

    Apartment(int sr)
    {
        sizeroom = sr;
        arrA = new Human[sr];
        countH = 0;
    }

    ~Apartment()
    {
        delete[] arrA;
    }

    void AddHuman(const Human& h) {
        if (countH<sizeroom)
        {
            arrA[countH++] = h;
        }
        else{
            cout << "room is full" << endl;
        }
    }
    void ShowHroom() {
        for (size_t i = 0; i < countH; i++)
        {
            cout <<"\t\t\t\t" << arrA[i].name << " " << arrA[i].age << endl;
        }
    }
};

class House {
public:
    Apartment* arrHo;
    int countA;

    House() :House(1) {} 

    House(int cA) {
        arrHo = new Apartment[cA];
        countA = cA;
    }

    void ShowRoom(int n) {
        if (n>0 && n<countA)
        {
            cout << "Room number " << n << " have this humans :" << endl;
            arrHo[n].ShowHroom();
        }
        else
        {
            cout << "Invalid number of room!" << endl;
        }
    }

    void ShowHouse() {
        for (int i = 0; i < countA; i++)
        {
            cout << "Room number " << i << " have this humans (count humans:" << arrHo[i].countH << ") (max humans:" << arrHo[i].sizeroom <<")   :" << endl;
            arrHo[i].ShowHroom();
            cout << endl;
        }
    }

    ~House()
    {
        delete[] arrHo;
    }
};

int main()
{
    Human h1("Oleksandr Ivanovych", 25);
    Human h2("Serhiy Viktorovych", 21);
    Human h3("Petro Romanovych", 32);
    Human h4("Bohdan Olehkovych", 27);

    House house1(3);
    House house2(2);

    house1.arrHo[0].AddHuman(h1);

    house2.arrHo[0].AddHuman(h4);
    house2.arrHo[0].AddHuman(h2);
    house2.arrHo[0].AddHuman(h2);
    house2.arrHo[0].AddHuman(h2);
    house2.arrHo[1].AddHuman(h3);

    house1.ShowHouse();
    house2.ShowHouse();
}
