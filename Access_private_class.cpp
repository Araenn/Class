/* Defines a student class with private member variables.
Member functions to access and modify all member variables (accessors and mutators).
Method void inStudents() which allows to initialize an object by keyboard entries.
Method void show() which allows to display the attributes of an object.
main() creates a table of student objects of dimension 10, fills this table with the keyboard, then displays the list of ́étudiants and their attributes. */

#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

class Students {

private:
	char name[15];
	char firstname[15];
	int rank, age, average;

public:
	char* getName() {
		return name;
	}

	void setName(char *name) { /* mutator char[] */
		for (int i = 0; i < 15; i++) {
			this->name[i] = name[i];
		}
	}

	char* getFirstname() {
		return firstname;
	}

	void setFirstname(char *firstname) { /* mutator char[] */
		for (int i = 0; i < 15; i++) {
			this->firstname[i] = firstname[i];
		}
	}

	int getRank() {
		return rank;
	}

	void setRank(int rank) {
		this->rank = rank;
	}

	int getAge() {
		return age;
	}

	void setAge(int age) {
		this->age = age;
	}

	int getAverage() {
		return average;
	}

	void setAverage(int average) {
		this->average = average;
	}

	void inStudents() { /* creation input */
		char name[15];
		cout << "name: ";
		cin >> name;
		setName(name);
		cout << "name's initialisation is: " << name << endl;

		char firstname[15];
		cout << "firstname: ";
		cin >> firstname;
		setFirstname(firstname);
		cout << "firstname's intitialisation is: " << firstname << endl;

		int rank;
		cout << "rank: ";
		cin >> rank;
		setRank(rank);
		cout << "rank's initialisation is: " << rank << endl;

		int age;
		cout << "age: ";
		cin >> age;
		setAge(age);
		cout << "age's initialisation is: " << age << endl;

		int average;
		cout << "average: ";
		cin >> average;
		setAverage(average);
		cout << "average's initialisation is: " << average << endl;
	}

	void show() {

		printf("Name: ");
		for (unsigned int i = 0; i < strlen(getName()); i++) {
			cout << getName()[i];
		}
		printf("\n");

		printf("Firstname: ");
		for (unsigned int i = 0; i < strlen(getFirstname()); i++) {
			cout << getFirstname()[i];
		}
		printf("\n");

		printf("rank: %d\n", getRank());
		printf("age: %d\n", getAge());
		printf("average: %d", getAverage());
	}
};

int main() {

	Students liste[10]; /* create a tab*/

	for (int i = 0; i < 10; i++) { /* fill the tab*/
		Students s;
		s.inStudents();
		liste[i] = s;
	}

  for (int i = 0; i < 10; i++) { /* show elements */
		liste[i].show();
	}
}
