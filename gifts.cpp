#include <iostream>
using namespace std;


class Gift {
private:
	int nbitems;
	bool dist;
public:
	Gift(int);
	Gift(Gift*);
	~Gift();
	void print();
	void setnbitems(int);
	int getnbitems();
	bool confirm();
	void produce();
};


Gift::Gift(int u) {
	setnbitems(u);
	print();
}


Gift::Gift(Gift* A) {
	nbitems = A->getnbitems();
	print();
}

void Gift::print() {
	cout << "le cadeau sera de: " << nbitems;
}

Gift::~Gift() {
	cout << "destruction du cadeau de: " << nbitems;
}

void Gift::setnbitems(int a) {
	while (a <= 0) {
		cout << "redonner le nb d items: ";
		cin >> a;
	}
	nbitems = a;
}

int Gift::getnbitems() {
	return nbitems;
}

bool Gift::confirm() {
	if (dist == 1) {
		nbitems -= 1;
	}
	return dist;
}

void Gift::produce() {
	nbitems += 1;
}

//B
class distribution {
private:
	string name;
	int id;
	char gender;
	int age;
	string status;

public:
	distribution(string, int, char, int, string);
	distribution(distribution&);
	~distribution();

	void setname(string);
	void setid(int);
	void setgender(char);
	void setage(int);
	void setstatus(string);
	void setdist(string, int, char, int, string);
	void print();

	string getname();
	int getid();
	char getgender();
	int getage();
	string getstatus();

	int choosegift();

};

distribution::distribution(string r, int w, char e, int i, string h) {
	setdist(r, w, e, i, h);
	print();
}

distribution::distribution(distribution& t) {
	setdist(t.name, t.id, t.gender, t.age, t.status);
	print();
}

distribution::~distribution() {
	cout << "distruction de: ";
	print();
}

void distribution::setname(string a) {
	if (size(a) <= 1) {
		cout << "donner le nom";
		cin >> a;
	}
	name = a;
}

void distribution::setid(int a) {
	while (a <= 0) {
		cout << "redonner le id: ";
		cin >> a;
	}
	id = a;
}


void distribution::setage(int a) {
	while (a <= 0) {
		cout << "redonner le age: ";
		cin >> a;
	}
	age = a;
}

void distribution::setgender(char a) {
	while (a != 'F' && a != 'M') {
		cout << "redonner le genre: ";
		cin >> a;
	}
	gender = a;
}

void distribution::setstatus(string a) {
	status = a;
}

void distribution::setdist(string a, int d, char e, int r, string w) {
	setname(a);
	setid(d);
	setgender(e);
	setage(r);
	setstatus(w);
}

string distribution::getname() {
	return name;
}

int distribution::getid() {
	return id;
}

char distribution::getgender() {
	return gender;
}

int distribution::getage() {
	return age;
}

string distribution::getstatus() {
	return status;
}

int distribution::choosegift() {
	if (gender == 'F' && age < 10)return 1;
	if (gender == 'M' && age < 10)return 2;
	else return 3;
}

void distribution::print() {
	cout << endl << name << endl << id << endl << gender << endl << age << endl;
	if (status == "OK")cout << "accomplie\n";
	else cout << "pas accomplie\n";
}

//C
void distributegift(Gift* a, distribution& t) {
	if ((t.getstatus() != "OK") && (a->getnbitems() != 0)) {
		a->setnbitems(a->getnbitems() - 1);
		t.setstatus("OK");
	}
	if ((t.getstatus() != "OK") && (a->getnbitems() == 0)) {
		cout << "revenez demain";
	}
	if (t.getstatus() == "OK") cout << "t as eu un cadeau";

}

//D
void Checklist(distribution t[], int h) {
	for (int i = 0; i < h; i++) {
		if (t[i].getstatus() == "OK")cout << "HOHOHO MERRY CHRISTMAS " << t[i].getname();
		else cout << "PERE NOEL IL Y A QLQ UN QUI N A PAS EU SON CADEAU";
	}
}
//E
void main() {
	int w, r, e;
	cout << "donner le nb de dolls puis cars puis ipads:";
	cin >> w >> r >> e;
	Gift doll(w);
	Gift car(r);
	Gift ipad(e);
	distribution a("", 0, 'd', 1, "d");
	distribution t[2] = { a,a };
	//ou

	//distribution t[2];

	for (int i = 0; i < 2; i++) {

		if (t[i].choosegift() == 1) {
			distributegift(&doll, t[i]);
		}
		if (t[i].choosegift() == 2) {
			distributegift(&car, t[i]);
		}
		if (t[i].choosegift() == 3) {
			distributegift(&ipad, t[i]);
		}
	}
	Checklist(t, 10);

}