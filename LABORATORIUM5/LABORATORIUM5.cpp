#include <iostream>
#include <string>

class Student
{
protected:
	std::string imie;
	std::string nazwisko;
	int semestr;
	std::string numerIndeksu;
	int id;
public:
	Student()
	{
		this->id = 0;
	}
	Student(std::string imie, std::string nazwisko, int semestr, std::string numerIndeksu, int id = 0)
	{
		this->imie = imie;
		this->nazwisko = nazwisko;
		this->semestr = semestr;
		this->numerIndeksu = numerIndeksu;
		this->id = id;
	}

	virtual std::string info() {
		return "Student nie jest przypisany do zadnego kierunku";
	}

	virtual int daneDodatkowe() = 0;

	friend std::ostream& operator << (std::ostream& out, Student & s)
	{
		out << "Imie: " << s.imie << std::endl;
		out << "Naziwsko: " << s.nazwisko << std::endl;
		out << "Semestr: " << s.semestr << std::endl;
		out << s.info() << std::endl;
		out << "Numer indeksu: " << s.numerIndeksu << std::endl;
		return out;
	}

	std::string getImie()
	{
		return imie;
	}


	void setImie(std::string imie)
	{
		this->imie = imie;
	}

	int getId()
	{
		return id;
	}

	virtual ~Student() {}


	friend std::istream& operator >> (std::istream& in, Student &s)
	{
		in >> s.imie;
		in >> s.nazwisko;
		in >> s.semestr;
		in >> s.numerIndeksu;
		return in;
	}

};

class GeniuszMatematyczny
{
private:
	int iq = 0;
	int liczbaWygranychOlimpiad = 0;
	int wynikMaturalnyZMatematyki = 0;

public:

	int getIq()
	{
		return iq;
	}
	void setIq(int iq)
	{
		this->iq = iq;
	}
	int getLiczbaWygranychOlimpiad()
	{
		return liczbaWygranychOlimpiad;
	}
	void setLiczbaWygranychOlimpiad(int liczbaWygranychOlimpiad)
	{
		this->liczbaWygranychOlimpiad = liczbaWygranychOlimpiad;
	}
	int getWynikMaturalnyZMatematyki()
	{
		return wynikMaturalnyZMatematyki;
	}
	void setWynikMaturalnyZMatematyki(int wynikMaturalnyZMatematyki)
	{
		this->wynikMaturalnyZMatematyki = wynikMaturalnyZMatematyki;
	}

	friend std::ostream& operator << (std::ostream& out, GeniuszMatematyczny &gm)
	{
		if (gm.iq) out << "IQ studenta wynosi: " << gm.iq << std::endl;
		if (gm.liczbaWygranychOlimpiad) out << "Wygral " << gm.liczbaWygranychOlimpiad << " olimpiad matematycznych" <<
			std::endl;
		if (gm.wynikMaturalnyZMatematyki) out << "Na maturze uzyskal wynik " << gm.wynikMaturalnyZMatematyki << "%." <<
			std::endl;
		return out;
	}

};

class PrzyjacielZwierzat
{
private:
	bool maPsaLubKota;
	int liczbaZnanychGatunkow;
	double wydatkiNaPokarm;

public:

	bool getMaPsaLubKota()
	{
		return maPsaLubKota;
	}

	void setMaPsaLubKota(bool maPsaLubKota)
	{
		this->maPsaLubKota = maPsaLubKota;
	}

	int getliczbaZnanychGatunkow()
	{
		return liczbaZnanychGatunkow;
	}

	void setliczbaZnanychGatunkow(int liczbaZnanychGatunkow)
	{
		this->liczbaZnanychGatunkow = liczbaZnanychGatunkow;
	}

	double getwydatkiNaPokarm()
	{
		return wydatkiNaPokarm;
	}

	void setwydatkiNaPokarm(double wydatkiNaPokarm)
	{
		this->wydatkiNaPokarm = wydatkiNaPokarm;
	}

	friend std::ostream& operator << (std::ostream& out, PrzyjacielZwierzat &pz)
	{
		if (pz.maPsaLubKota) out << "Ta osoba posiada psa lub kota" << std::endl;
		else out << "Ta osoba nie posiada psa ani kota" << std::endl;
		if (pz.liczbaZnanychGatunkow) out << "Ta osoba zna: " << pz.liczbaZnanychGatunkow << " gatunkow." << std::endl;
		if (pz.wydatkiNaPokarm) out << "Jej wydatki miesieczne na pokarm wynosza " << pz.wydatkiNaPokarm << " zl." << std::endl;
		return out;
	}
};

class StudentInformatyki : public Student, public GeniuszMatematyczny
{
private:
	bool znaCpp;
	int id;

public:
	StudentInformatyki()
	{
		this->id = 1;
	}

	StudentInformatyki(std::string imie, std::string nazwisko, int semestr, std::string numerIndeksu, bool znaCpp, int id = 1) :
		Student(imie, nazwisko, semestr, numerIndeksu, 1)
	{
		this->znaCpp = znaCpp;
	}


	bool isZnaCpp()
	{
		return znaCpp;
	}

	void setZnaCpp(bool znaCpp)
	{
		this->znaCpp = znaCpp;
	}

	int daneDodatkowe()
	{
		return znaCpp;
	}

	void modyfikujNumerIndeksu()
	{
		if (numerIndeksu[0] != 'I') numerIndeksu = 'I' + numerIndeksu;
	}

	std::string info() {
		return "Student kierunku Informatyka";
	}

	friend std::ostream& operator << (std::ostream& out, StudentInformatyki & s)
	{
		out << static_cast<Student &>(s);
		if (s.daneDodatkowe()) out << "Zna C++";
		else out << "Dopiero sie uczy w C++";
		out << std::endl;
		out << static_cast<GeniuszMatematyczny &>(s) << std::endl;
		return out;
	}

	friend std::istream& operator >> (std::istream& in, StudentInformatyki &si)
	{
		in >> static_cast<Student &>(si);
		in >> si.znaCpp;
		return in;
	}



};

class StudentBiologi : public Student, public PrzyjacielZwierzat
{
private:
	int id;
public:
	StudentBiologi()
	{
		this->id = 3;
	}
	StudentBiologi(std::string imie, std::string nazwisko, int semestr, std::string numerIndeksu) :
		Student(imie, nazwisko, semestr, numerIndeksu, 3) {}


	std::string info() {
		return "Student kierunku Biologia";
	}




	friend std::ostream& operator << (std::ostream& out, StudentBiologi &sb)
	{
		out << static_cast<Student &>(sb);
		out << static_cast<PrzyjacielZwierzat &>(sb)  << std::endl;
		return out;
	}

	friend std::istream& operator >> (std::istream& in, StudentBiologi &sb)
	{
		in >> static_cast<Student &>(sb);
		return in;
	}

};

class StudentPolonistyki : public Student
{
private:
	int liczbaPrzeczytanychKsiazek;
	int id;

public:
	StudentPolonistyki()
	{
		this->id = 2;
	}
	StudentPolonistyki(std::string imie, std::string nazwisko, int semestr, std::string numerIndeksu, int liczbaPrzeczytanychKsiazek) :
		Student(imie, nazwisko, semestr, numerIndeksu, 2)
	{
		this->liczbaPrzeczytanychKsiazek = liczbaPrzeczytanychKsiazek;
		modyfikujIndeks();
	}

	int getLiczbaPrzeczytanychKsiazek()
	{
		return liczbaPrzeczytanychKsiazek;
	}

	int setLiczbaPrzeczytanychKsiazek(int liczbaPrzeczytanychKsiazek)
	{
		this->liczbaPrzeczytanychKsiazek = liczbaPrzeczytanychKsiazek;
	}

	int daneDodatkowe()
	{
		return liczbaPrzeczytanychKsiazek;
	}

	void modyfikujIndeks()
	{
		if (numerIndeksu[0] != 'M') numerIndeksu = 'M' + numerIndeksu;
	}

	std::string info() {
		return "Student kierunku Polonistyka";
	}


	friend std::ostream& operator << (std::ostream& out, StudentPolonistyki &sp)
	{
		out << static_cast<Student &>(sp);
		if (sp.daneDodatkowe() > 100) out << "Przeczytal kilka ksiazek";
		else out << "Slaby czytelnik - chyba nie skonczy studiow";
		out << std::endl;
		return out;
	}

	friend std::istream& operator >> (std::istream& in, StudentPolonistyki &sp)
	{
		in >> static_cast<Student &>(sp);
		in >> sp.liczbaPrzeczytanychKsiazek;
		return in;
	}


};

class Uczelnia
{
private:
	std::string nazwa;
	Student *listaStudentow[100];
	int liczbaStudentow = 0;

public:
	Uczelnia() {}
	Uczelnia(std::string nazwa)
	{
		this->nazwa = nazwa;
		std::cout << "Utworzono uczelnie " << nazwa << std::endl;
	}

	std::string getNazwa()
	{
		return nazwa;
	}

	int getLiczbaStuentow()
	{
		return liczbaStudentow;
	}

	/*Student getLista(int i)
	{
		return *listaStudentow[i];

	}*/

	~Uczelnia() {}

	void dodajStudenta(Student *s)
	{
		listaStudentow[liczbaStudentow] = s;
		liczbaStudentow++;
	}

	
	int znajdzStudenta(Student *s)
	{
		for (int i = 0; i < liczbaStudentow; i++)
		{
			if (s == listaStudentow[i])
			{
				std::cout << "Student znajduje sie na liscie pod numerem " << i << std::endl;
				return 1;
			}
		}
		std::cout << "Student nie znajduje sie na liscie" << std::endl;
		return 0;
	}

	friend std::ostream& operator << (std::ostream& out, Uczelnia & u)
	{
		int i;
		if (u.liczbaStudentow > 0)
		{
			out << std::endl << "Oto lista studentow:" << std::endl;
			for (i = 0; i < u.liczbaStudentow; i++)
			{
				{
					out << std::endl << "Oto dane #" << i + 1 << " studenta:" << std::endl << std::endl;
					switch (u.listaStudentow[i]->getId())
					{
					case 0:
						out << *u.listaStudentow[i];
						break;
					case 1:
						out << *static_cast<StudentInformatyki *>(u.listaStudentow[i]);
						break;
					case 2:
						out << *static_cast<StudentPolonistyki *>(u.listaStudentow[i]);
						break;
					case 3:
						out << *static_cast<StudentBiologi *>(u.listaStudentow[i]);
						break;
					default:
						out << "Obiekt nieznanej klasy" << std::endl;
						break;
					}
					out << typeid(*u.listaStudentow[i]).name() << std::endl;
					out << std::endl;
				}
			}
		}
		else out << "Na tej uczelni nie ma jeszcze studentow." << std::endl;

		return out;
	}

	friend std::istream& operator >>(std::istream& in, Uczelnia &u)
	{
		in >> u.nazwa;
		return in;
	}

};

class ZlyUlamek
{
public:
	ZlyUlamek() {}
	friend std::ostream& operator << (std::ostream& out, ZlyUlamek &zu)
	{
		out << "WYJATEK: zly ulamek - w mianowniku nie moze byc zera" << std::endl;
		return out;
	}
};

class ProbaObliczeniaPierwKwadrat
{
public:
	ProbaObliczeniaPierwKwadrat() {}

	friend std::ostream& operator <<(std::ostream& out, ProbaObliczeniaPierwKwadrat & popk)
	{
		out << "WYJATEK: proba obliczenia pierwiastka kwadratowego z liczby ujemnej!" << std::endl;
		return out;
	}
};

class DzieleniePrzezZero
{
public:
	DzieleniePrzezZero() {}
	
	friend std::ostream& operator << (std::ostream& out, DzieleniePrzezZero &dpz)
	{
		out << "WYJATEK: proba dzielenia przez 0" << std::endl;
		return out;
	}
};

class Ulamek
{
private:
	int mianownik;
	int licznik;
public:
	Ulamek() {}
	Ulamek(int licznik, int mianownik )
	{
		this->licznik = licznik;
		if (mianownik == 0) throw ZlyUlamek();
		this->mianownik = mianownik;
	}

	friend std::ostream& operator << (std::ostream& out, Ulamek &u)
	{
		out << u.licznik << "/" << u.mianownik << std::endl;
		return out;
	}

	friend std::istream& operator >> (std::istream& in, Ulamek &u)
	{
		in >> u.licznik;
		in >> u.mianownik;
		return in;
	}

	Ulamek operator / (Ulamek a) {
		if (a.licznik == 0) throw DzieleniePrzezZero();
		Ulamek wynik(licznik*a.mianownik, mianownik*a.licznik);
		return wynik;
	}



};

class UlamekPierwiastek
{
private:
	double x;
	double y;
public:
	UlamekPierwiastek(double x,double y)
	{
		if (sqrt(x) - sqrt(y) == 0) throw DzieleniePrzezZero();
		if (x < 0 || y < 0) throw ProbaObliczeniaPierwKwadrat();
		this->x = x;
		this->y = y;
	}

	friend std::ostream& operator << (std::ostream& out, UlamekPierwiastek & up)
	{
		out << "pierw(" << up.x + up.y << ")/pierw(" << up.x << ")-pierw(" << up.y << ")" << std::endl;
		return out;
	}

	friend std::istream& operator >> (std::istream& in, UlamekPierwiastek & up)
	{
		in >> up.x;
		in >> up.y;
		return in;
	}

};

class Wyrazenie
{
private:
	int a;
	int b;
public:
	Wyrazenie() {}

};
int main(int argc, char *argv[])
{
	//ZAD1
	/*
	double x, y;
	std::cout << "Podaj x: ";
	std::cin >> x;
	std::cout << "Podaj y: ";
	std::cin >> y;

	try
	{
		UlamekPierwiastek up(x, y);
		std::cout << up;
	}

	catch (DzieleniePrzezZero dpz)
	{
		std::cout << dpz;
	}
	
	catch (ProbaObliczeniaPierwKwadrat popk)
	{
		std::cout << popk;
	}*/

	StudentInformatyki si("Maciej", "Reszke", 5, "123131", true);

	std::cout << si;

	system("pause");
	return 0;	
}
