#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
using namespace std;

//Videos list for references and ideas:
//https://www.youtube.com/watch?v=hAXI_5_kruo
//https://www.youtube.com/watch?v=SiBw7os-_zI&t=31s
//https://www.youtube.com/watch?v=j7y_d03Yl6A
//https://www.youtube.com/watch?v=-W-TYjL0aFE
//https://www.youtube.com/watch?v=0NwsayeOsd4
//https://www.youtube.com/watch?v=kiUGf_Z08RQ
//https://www.youtube.com/watch?v=iVLQeWbgbXs&t=594s



//creating the animal class to store common info
//stores caommon info that can apply to all animals
// doing it also makes resues the data for later
//https://www.w3schools.com/cpp/cpp_access_specifiers.asp

    class animal {
    private:
        string name;
        int age;
        string species;
        string gender;
        string birthDate;
        string color;
        double weight;
        string origin;

//crates a new animal with more details
    public:
        //Created for the animal object
        //Constructer created so that new aniamls canautomatically have its deatials.

        animal(string n, int a, string s, string g, string bd, string c, double w, string o) {
            name = n;
            age = a;
            species = s;
            gender = g;
            birthDate = bd;
            color = c;
            weight = w;
            origin = o;
        }
        //getters
        //lets other parts of the program read the pricate info
        //also part of encapsualtion.
        //https://www.w3schools.com/cpp/cpp_encapsulation.asp
        //https://www.youtube.com/watch?v=5_GQw06deQg
        string Name() { return name; }
        int Age() { return age; }
        string Species() { return species; }
        string Gender() { return gender; }
        string BirthDate() { return birthDate; }
        string Color() { return color; }
        double Weight() { return weight; }
        string Origin() { return origin; }

       //subclasses for each specie
//they get some info from animal class but info can be changed
        // this part of the program is supposed to let all animals be seens similarly  by the program.
        //while also species have unique attributes
//https://www.geeksforgeeks.org/cpp/virtual-function-cpp/
//https://www.geeksforgeeks.org/cpp/function-overriding-in-cpp/
class Hyena : public animal {
public:
            // supossed to let the constructor calls ther aprent constructor but sets the anme to hyena using inheritance
    Hyena(string n, int a, string s, string g, string bd, double w, string o)
    : animal(n, a, s, "Hyena", g, bd, w, o){}

            //
    void Info(ofstream &outfile) {
        outfile << "Hyena: ";
        animal::Info(outfile);
        outfile << endl;
    }
};
class Lion : public animal {
    public:
    Lion(string n, int a, string s, string g, string b, double w, string o)
        : animal(n, a, s, "Lion", g, b, w, o){}

};

class Tiger : public animal {
    public:
    Tiger(string n, int a, string s, string g, string b, double w, string o)
        : animal(n, a, s, "Tiger", g, b, w, o){}

};

class Bear : public animal {
    public:
    Bear(string n, int a, string s, string g, string b, double w, string o)
        : animal(n,a, s, "Bear", g, b, w, o){}

};

//The Main Program

int main() {



    return 0;
}