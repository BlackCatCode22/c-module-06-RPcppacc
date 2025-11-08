// zooKeeperChallengeRevised 11/5/25 by Roman Pena
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <unordered_map>

using namespace std;

class Animal {
private:
    static int numofanimals;
    string name;
    string id;
    string birthday;
    string sex;
    string species;
    string birthseason;
    string weight;
    string color;
    string location;
    string state;
    string arrivaldate;
    int age;

public:
    Animal(const string &name, const string &id, const string &birthday, const string &sex, const string &species,
           const string &birthseason, const string &weight, const string &color, const string &location, const string &state, int age) {
        this->name = name;
        this->id = id;
        this->birthday = birthday;
        this->sex = sex;
        this->species = species;
        this->birthseason = birthseason;
        this->weight = weight;
        this->color = color;
        this->location = location;
        this->state = state;
        this->age = age;

        numofanimals++;
    }

    void setName(const string &name) { this->name = name; }
    void setId(const string &id) { this->id = id; }
    void setbirthday(const string &birthday) { this->birthday = birthday; }
    void setsex(const string &sex) { this->sex = sex; }
    void setspecies(const string &species) { this->species = species; }
    void setbirthseason(const string &birthseason) { this->birthseason = birthseason; }
    void setweight(const string &weight) { this->weight = weight; }
    void setcolor(const string &color) { this->color = color; }
    void setlocation(const string &location) { this->location = location; }
    void setstate(const string &state) { this->state = state; }
    void setage(const int &age) { this->age = age; }

    string getName() const { return name; }
    string getId() const { return id; }
    string getBirthday() const { return birthday; }
    string getsex() const { return sex; }
    string getspecies() const { return species; }
    string getbirthseason() const { return birthseason; }
    string getweight() const { return weight; }
    string getcolor() const { return color; }
    string getlocation() const { return location; }
    string getstate() const { return state; }
    int getAge() const { return age; }

    static int getnumofanimals() { return numofanimals; }

    string tostring() const {
        stringstream ss;
        ss << "Animal information: \n"
           << "Name: " << name << "\n"
           << "ID: " << id << "\n"
           << "Birthday: " << birthday << "\n"
           << "Sex: " << sex << "\n"
           << "Species: " << species << "\n"
           << "Birthseason: " << birthseason << "\n"
           << "Weight: " << weight << "\n"
           << "Color: " << color << "\n"
           << "Location: " << location << "\n"
           << "State: " << state << "\n"
           << "Age: " << age << "\n"
           << "numofanimals: " << numofanimals << "\n";
        return ss.str();
    }
};
int Animal::numofanimals = 0;

class Hyena : public Animal {
private:
    static int numofHyena;
public:
    Hyena(const string &name, const string &id, const string &birthday, const string &sex,
          const string &birthseason, const string &weight, const string &color,
          const string &location, const string &state, int age)
        : Animal(name, id, birthday, sex, "Hyena", birthseason, weight, color, location, state, age) {
        numofHyena++;
    }

    static int getnumofHyena() { return numofHyena; }
};
int Hyena::numofHyena = 0;

class Lion : public Animal {
private:
    static int numoflion;
public:
    Lion(const string &name, const string &id, const string &birthday, const string &sex,
         const string &birthseason, const string &weight, const string &color,
         const string &location, const string &state, int age)
        : Animal(name, id, birthday, sex, "Lion", birthseason, weight, color, location, state, age) {
        numoflion++;
    }
    static int getnumoflion() { return numoflion; }
};
int Lion::numoflion = 0;

class Tiger : public Animal {
private:
    static int numofTiger;
public:
    Tiger(const string &name, const string &id, const string &birthday, const string &sex,
          const string &birthseason, const string &weight, const string &color,
          const string &location, const string &state, int age)
        : Animal(name, id, birthday, sex, "Tiger", birthseason, weight, color, location, state, age) {
        numofTiger++;
    }

    static int getnumofTiger() { return numofTiger; }
};
int Tiger::numofTiger = 0;

class Bear : public Animal {
private:
    static int numofBear;
public:
    Bear(const string &name, const string &id, const string &birthday, const string &sex,
         const string &birthseason, const string &weight, const string &color,
         const string &location, const string &state, int age)
        : Animal(name, id, birthday, sex, "Bear", birthseason, weight, color, location, state, age) {
        numofBear++;
    }

    static int getnumofBear() { return numofBear; }
};
int Bear::numofBear = 0;

int main() {
    unordered_map<string, Animal*> map;

    // ✅ File now opens correctly for a file named "arrivingAnimals" (no .txt)
    ifstream file1("arrivingAnimals.txt");
    if (!file1) {
        cout << "Error opening file." << endl;
        return 1;
    }

    string line;
    while (getline(file1, line)) {
        cout << line << endl;

        string arrivaldate = "";
        string name;
        string birthday;

        size_t pos = 0;
        string delimiter = ",";

        pos = line.find(delimiter);
        string var1 = line.substr(0, pos);
        line.erase(0, pos + delimiter.length());
        cout << "var1: " << var1 << endl;

        istringstream iss1(var1);
        int age;
        string year, old, sex, spcies;
        iss1 >> age >> year >> old >> spcies;

        pos = line.find(delimiter);
        string var2 = line.substr(0, pos);
        line.erase(0, pos + delimiter.length());
        cout << "var2: " << var2 << endl;

        string birthseason = "unknown";

        pos = line.find(delimiter);
        string color = line.substr(0, pos);
        line.erase(0, pos + delimiter.length());
        cout << "color: " << color << endl;

        pos = line.find(delimiter);
        string weight = line.substr(0, pos);
        line.erase(0, pos + delimiter.length());
        cout << "weight: " << weight << endl;

        pos = line.find(delimiter);
        string location = line.substr(0, pos);
        line.erase(0, pos + delimiter.length());
        cout << "location: " << location << endl;

        pos = line.find(delimiter);
        string state = line.substr(0, pos);
        cout << "state: " << state << endl;

        if (spcies == "Hyena") {
            string Hyenaid = "Hy0" + to_string(Hyena::getnumofHyena());
            auto* hyena = new Hyena(name, Hyenaid, birthday, sex, birthseason, weight, color, location, state, age);
            map[Hyenaid] = hyena;
        }
        if (spcies == "Lion") {
            string Lionid = "Li0" + to_string(Lion::getnumoflion());
            auto* lion = new Lion(name, Lionid, birthday, sex, birthseason, weight, color, location, state, age);
            map[Lionid] = lion;
        }
        if (spcies == "Tiger") {
            string Tigerid = "Ti0" + to_string(Tiger::getnumofTiger());
            auto* tiger = new Tiger(name, Tigerid, birthday, sex, birthseason, weight, color, location, state, age);
            map[Tigerid] = tiger;
        }
        if (spcies == "Bear") {
            string Bearid = "Be0" + to_string(Bear::getnumofBear());
            auto* bear = new Bear(name, Bearid, birthday, sex, birthseason, weight, color, location, state, age);
            map[Bearid] = bear;
        }
    }

    file1.close(); // ✅ properly close after reading

    unordered_map<string, bool> printed;
    for (auto &pair : map) {
        string spcies = pair.second->getspecies();
        if (!printed[spcies]) {
            cout << "\nTotal created animals: " << Animal::getnumofanimals() << endl;
            printed[spcies] = true;
        }
    }

    return 0;
}
