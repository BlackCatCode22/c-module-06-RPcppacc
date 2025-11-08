#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <iomanip>
using namespace std;


   // This program is my Zookeeper's Challenge.
//created by Roman Pena Finalized 11/8/25




// Base Class: Animal

class Animal {
private:
    // These variables hold the basic attributes that all animals share.
    string name;
    string sex;
    string species;
    string color;
    string origin;
    int age;
    int weight;

protected:
    // Static counter keeps track of how many total Animal objects exist.
    static int totalAnimals;

public:
    // Constructor initializes the animal with given data.
    Animal(string n, string s, string sp, string c, string o, int a, int w)
        : name(n), sex(s), species(sp), color(c), origin(o), age(a), weight(w) {
        totalAnimals++; // Every time an Animal (or subclass) is created, count increases.
    }

    // Virtual destructor ensures subclasses are properly cleaned up when deleted.
    virtual ~Animal() {}

    // Getter methods allow controlled access to private member variables.
    string getName() const { return name; }
    string getSex() const { return sex; }
    string getSpecies() const { return species; }
    string getColor() const { return color; }
    string getOrigin() const { return origin; }
    int getAge() const { return age; }
    int getWeight() const { return weight; }

    // Static function to return how many total animals have been created.
    static int getnumofanimals() { return totalAnimals; }
};

// Initialize static variable.
int Animal::totalAnimals = 0;



// Subclasses for each specific animal species



   // Each of these derived classes represents one species type.
    //They all inherit from Animal and maintain their own static counter
    //to keep track of how many individual animals of that species exist.


// -------- Hyena Class --------
class Hyena : public Animal {
private:
    static int hyenaCount; // Tracks how many Hyenas exist.

public:
    Hyena(string n, string s, string sp, string c, string o, int a, int w)
        : Animal(n, s, sp, c, o, a, w) {
        hyenaCount++; // Increment species-specific counter.
    }

    // Returns total Hyenas created so far.
    static int getCount() { return hyenaCount; }
};
int Hyena::hyenaCount = 0;


// -------- Lion Class --------
class Lion : public Animal {
private:
    static int lionCount;

public:
    Lion(string n, string s, string sp, string c, string o, int a, int w)
        : Animal(n, s, sp, c, o, a, w) {
        lionCount++;
    }

    static int getCount() { return lionCount; }
};
int Lion::lionCount = 0;


// -------- Tiger Class --------
class Tiger : public Animal {
private:
    static int tigerCount;

public:
    Tiger(string n, string s, string sp, string c, string o, int a, int w)
        : Animal(n, s, sp, c, o, a, w) {
        tigerCount++;
    }

    static int getCount() { return tigerCount; }
};
int Tiger::tigerCount = 0;


// -------- Bear Class --------
class Bear : public Animal {
private:
    static int bearCount;

public:
    Bear(string n, string s, string sp, string c, string o, int a, int w)
        : Animal(n, s, sp, c, o, a, w) {
        bearCount++;
    }

    static int getCount() { return bearCount; }
};
int Bear::bearCount = 0;



// Helper Function: Generate a Unique ID


  //  This function creates a unique ID for each animal.
    //It takes the first two letters of the species (capitalized)
   // and adds a two-digit sequential number (e.g. Hy01, Li02).

string genUniqueID(const string& species, int count) {
    string prefix = species.substr(0, 2); // Extract first 2 letters of species.
    prefix[0] = toupper(prefix[0]);      // Capitalize first letter.
    prefix[1] = tolower(prefix[1]);      // Lowercase second letter.
    stringstream ss;
    ss << prefix << setw(2) << setfill('0') << count; // Format number with 2 digits.
    return ss.str();
}



// Main Function

int main() {
    // A map to store animals by their unique IDs.
    unordered_map<string, Animal*> zooAnimals;

    // Attempt to open the input file that contains the animal list.
    ifstream infile("arrivingAnimals.txt");
    if (!infile.is_open()) {
        cerr << "Error: could not open arrivingAnimals.txt" << endl;
        return 1; // Exit program if file is missing.
    }

    string line;
    // Read file line by line until the end.
    while (getline(infile, line)) {
        // Each line describes one animal’s details, separated by commas.
        stringstream ss(line);
        string var1, var2, var3, var4, var5, var6, var7;
        getline(ss, var1, ','); // Age
        getline(ss, var2, ','); // Sex or description
        getline(ss, var3, ','); // Species
        getline(ss, var4, ','); // Color
        getline(ss, var5, ','); // Weight
        getline(ss, var6, ','); // Origin location (may include commas)
        getline(ss, var7, ','); // Extra field (if exists)

        // Trim spaces
        auto trim = [](string& str) {
            while (!str.empty() && isspace(str.front())) str.erase(str.begin());
            while (!str.empty() && isspace(str.back())) str.pop_back();
        };
        trim(var1); trim(var2); trim(var3); trim(var4); trim(var5); trim(var6);

        // Parse numeric data.
        int age = 0;
        int weight = 0;
        try {
            age = stoi(var1);
            weight = stoi(var5);
        }
        catch (...) {
            cout << "Warning: Could not parse numeric values on line: " << line << endl;
        }

        // Determine species and create the corresponding object.
        Animal* newAnimal = nullptr;
        string id;

        // These if statements check which species type matches and create an object accordingly.
        if (var3 == "hyena") {
            id = genUniqueID(var3, Hyena::getCount() + 1);
            newAnimal = new Hyena(var2, var2, var3, var4, var6, age, weight);
        }
        else if (var3 == "lion") {
            id = genUniqueID(var3, Lion::getCount() + 1);
            newAnimal = new Lion(var2, var2, var3, var4, var6, age, weight);
        }
        else if (var3 == "tiger") {
            id = genUniqueID(var3, Tiger::getCount() + 1);
            newAnimal = new Tiger(var2, var2, var3, var4, var6, age, weight);
        }
        else if (var3 == "bear") {
            id = genUniqueID(var3, Bear::getCount() + 1);
            newAnimal = new Bear(var2, var2, var3, var4, var6, age, weight);
        }
        else {
            cout << "Unknown species: " << var3 << endl;
            continue; // Skip any unknown species.
        }

        // Add the new animal to the zoo map using its unique ID as a key.
        zooAnimals[id] = newAnimal;

        // Print confirmation message to console for tracking.
        cout << id << ": " << newAnimal->getName() << " (" << newAnimal->getSpecies()
             << "), " << newAnimal->getAge() << " years, "
             << newAnimal->getColor() << ", from " << newAnimal->getOrigin()
             << ", " << newAnimal->getWeight() << " lbs" << endl;
    }

    infile.close(); // Close file when finished.


    // Final Summary Section


        //After reading all animals, this section prints a simple summary.


    cout << "\nSummary Report:" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Total Animals: " << Animal::getnumofanimals() << endl;
    cout << "Hyenas: " << Hyena::getCount() << endl;
    cout << "Lions: " << Lion::getCount() << endl;
    cout << "Tigers: " << Tiger::getCount() << endl;
    cout << "Bears: " << Bear::getCount() << endl;

    // Cleanup Section
    for (auto& pair : zooAnimals) {
        delete pair.second;
    }
    zooAnimals.clear();

    return 0; // End of program.
}
