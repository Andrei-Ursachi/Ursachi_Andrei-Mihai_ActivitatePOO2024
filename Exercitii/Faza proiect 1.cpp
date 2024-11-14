#include <iostream>
using namespace std;

//Andrei = Abecedar; Mihai = Manual ; Ursachi = Uniforma
//Proiect - Faza 1
//- Pentru cele trei obiecte realizați trei clase care să conțină atribute specifice fiecărui obiect în parte.
//- În cele trei clase trebuie să aveți atribute normale, atribute statice și atribute constante.
//- Atributele le definiți în zona publică a clasei.
//- În fiecare clasă trebuie să aveți cel puțin un pointer pentru care veți aloca spațiu in HEAP.
//- Realizați pentru fiecare clasă cel puțin 3 constructori cu număr diferit de parametri(în total vor fi 9 constructori).
//- În cadrul constructorilor inițializați toate atributele claselor.Aveți grija la inițializarea atributelor constante și a atributelor statice.
//- În fiecare clasă realizați câte o funcție statică pentru orice tip de procesare sau calcul.
//- În funcția main creați, inițializați și afișați câte trei obiecte de tipul fiecărei clase, astfel încât să apelați toți constructorii.
//- Realizati toate clasele in acelasi fisier CPP, una sub cealalta, iar in partea de final a fisierului cu
//  cod sursa implementati functia main in cadrul careia testati toti constructorii implementati pentru clasele implementate.

enum LimbaDisponibilia { Romana, Engleza, Franceza };

class Abecedar {
public:
	int bucatiVandute;
	const string titlu;
	static int nrPagini;
	string editura;
	float* pretAbecedar;
	LimbaDisponibilia limbaDisponibila;
	//constructor 1
	Abecedar(int bucatiVandute, string titluNou) : titlu(titluNou) {
		this->bucatiVandute = bucatiVandute;
		this->editura = "testName";
		this->pretAbecedar = new float(12.3);
		this->limbaDisponibila = Romana;
	}
	//constructor 2
	Abecedar() : titlu("Titlu constructor 2") {
		this->bucatiVandute = 0;
		this->editura = "Editura Litera";
		this->pretAbecedar = nullptr;
		this->limbaDisponibila = Engleza;
	}
	//constructor 3
	Abecedar(int bucati, string edituraNoua, string titluNou, float pret, LimbaDisponibilia limba) : titlu(titluNou) {
		this->bucatiVandute = bucati;
		this->editura = edituraNoua;
		this->pretAbecedar = new float(pret);
		this->limbaDisponibila = limba;
	}

	void afisare() {
		cout << "Titlu abecedar: " << this->titlu << ";" << "\n";
		cout << "Numele editurii: " << this->editura << "\n";
		cout << "Bucati vandute: " << this->bucatiVandute << "\n";
		if (this->pretAbecedar != nullptr) {
			cout << "Pret abecedar: " << *(this->pretAbecedar) << "\n";
		}
		else {
			cout << "Abecedarul nu are pret!" << "\n";
		}
		cout << "Limba abecedarului: " << this->limbaDisponibila << "\n";
		cout << "Numar pagini: " << nrPagini << "\n" << endl;
	}

	//destructor
	~Abecedar() {
		if (this->pretAbecedar != nullptr) {
			delete this->pretAbecedar;
			this->pretAbecedar = nullptr;
		}
	}

	//functie statica de calcul
	static void marirePret(Abecedar& abecedar) {
		if (abecedar.pretAbecedar == nullptr) return;
		int randomMarire = rand() % 20 + 1;
		*(abecedar.pretAbecedar) += *(abecedar.pretAbecedar) * (randomMarire / 100.0f);
		cout << "Pretul a crescut cu " << randomMarire << "% pentru " << abecedar.titlu << endl;
	}
};
int Abecedar::nrPagini = 100;

class Manual {
public:
	float* pretManual;
	static string autor;
	const string materie;
	int nrPagini;
	float greutate;
	LimbaDisponibilia limbaDisponibila2;
	//constructor 1 manual
	Manual() : materie("Biologie const1") {
		this->pretManual = pretManual;
		this->nrPagini = 5;
		this->greutate = 1.8;
		this->limbaDisponibila2 = Romana;
	}
	//constuctor 2
	Manual(float* pretManual, string materieNoua) : materie(materieNoua) {
		this->pretManual = pretManual;
		this->nrPagini = 5;
		this->greutate = 2.6;
		this->limbaDisponibila2 = Franceza;
	}
	//constructor 3
	Manual(string materieNoua, float greutateNoua, int nrPagini2, float* pretManual) : materie(materieNoua) {
		this->pretManual = pretManual;
		this->nrPagini = 5;
		this->greutate = 3.1;
		this->limbaDisponibila2 = Engleza;
	}
	void afisareManual() {
		cout << "Materia manualului: " << this->materie << ";" << "\n";
		cout << "Manualul are " << this->nrPagini << " pagini;" << "\n";
		cout << "Manualul cantareste " << this->greutate << " kg;" << "\n";
		cout << "Manualul este in limba " << this->limbaDisponibila2 << "." << "\n";
		cout << "Autorul manualului este " << this->autor << "\n";
		if (pretManual != nullptr) {
			cout << "Pretul manualului este " << *pretManual << "lei." << "\n";
		}
		else {
			cout << "Manualul nu are pret!" << "\n";
		}
		cout << endl;

	}

	~Manual() {
		if (pretManual != nullptr) {
			delete this->pretManual;
			pretManual = nullptr;
		}
	}

	static void marirePretManual(Manual& manual) {
		if (manual.pretManual != nullptr) {
			int randomMarire = rand() % 20 + 1;
			*(manual.pretManual) += *(manual.pretManual) * (randomMarire / 100.0f);
			cout << "Pretul a crescut cu " << randomMarire << "% pentru " << manual.materie << endl;
		}
	}
};
string Manual::autor = "Vlad Mircea";

class Uniforma {
public:
	string culoare;
	int marime;
	float* pretCostum;
	const int nrComponente;
	static string sezon;
	//contructor 1
	Uniforma() :nrComponente(7) {
		this->culoare = "rosu";
		this->marime = 12;
		this->pretCostum = NULL;
	}
	//constructor 2
	Uniforma(string culoare, int _marime, int nrNou) : nrComponente(nrNou) {
		this->culoare = culoare;
		this->marime = _marime;
		this->pretCostum = pretCostum;
	}
	//constructor 3
	Uniforma(string _culoare, int _marime, int nrNou, float* pretCostum) : nrComponente(nrNou) {
		this->culoare = _culoare;
		this->marime = _marime;
		this->pretCostum = pretCostum;
	}
	void afisareUniforma() {
		cout << "Uniforma are culoarea: " << this->culoare << "\n";
		cout << "Uniforma are marimea " << this->marime << "\n";
		cout << "Uniforma are " << this->nrComponente << " componente \n";
		cout << "Uniforma este pt. sezonul " << this->sezon << "\n";
		if (pretCostum != nullptr) {
			cout << "Pretul uniformei este " << *pretCostum << "lei." << "\n";
		}
		else {
			cout << "Uniforma nu are pret!" << "\n";
		}
		cout << endl;

	}

	static void marirePret(Uniforma& uniforma) {
		if (uniforma.pretCostum != nullptr) {
			int randomMarire = rand() % 20 + 1;
			*(uniforma.pretCostum) += *(uniforma.pretCostum) * (randomMarire / 100.0f);
			cout << "Pretul a crescut cu " << randomMarire << "% pentru " << uniforma.culoare << endl;
		}
	}

	~Uniforma() {
		if (pretCostum != nullptr) {
			delete this->pretCostum;
			pretCostum = nullptr;
		}
	}
};
string Uniforma::sezon = "Vara";


int main() {
	//obiect 1 Abecedar
	Abecedar abcd1(500, "Abecedar constructor 1");
	abcd1.afisare();

	Abecedar abcd2;
	abcd2.afisare();

	Abecedar abcd3(300, "Editura cevaTest", "Titlu Constructor3", 12.02, Engleza);
	abcd3.afisare();
	//apelez functia statica de marire si afisez
	Abecedar::marirePret(abcd3);
	abcd3.afisare();

	//obiect 2 Manual
	Manual man1;
	man1.autor;
	cout << man1.autor << '\n';
	man1.greutate;
	cout << man1.greutate << '\n';
	man1.afisareManual();

	float* pretManual2 = new float(122.3f);
	Manual man2(pretManual2, "Religie");
	man2.afisareManual();

	float* pretManual3 = new float(133.3f);
	Manual man3("Matematica", 12.3, 43, pretManual3);
	pretManual3 = nullptr;

	Manual::marirePretManual(man3);
	man3.afisareManual();

	//obiect 3 Uniforma
	Uniforma unif1;
	unif1.afisareUniforma();

	Uniforma unif2("albastru", 7, 5);
	unif2.afisareUniforma();

	float* pretUnif2 = new float(222.2f);
	Uniforma unif3("verde", 10, 10, pretUnif2);
	unif3.afisareUniforma();


	return 0;
}