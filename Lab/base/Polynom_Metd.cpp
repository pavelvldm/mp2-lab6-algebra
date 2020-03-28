//#include "List.h"
#include "Polynom.h"

//using namespace std;

void TransformStr(string &s)
{
	int i;

	while ((i = s.find(' ')) != string::npos)
	{
		s.erase(i, 1);
	}

	while ((i = s.find(',')) != string::npos)
	{
		s.replace(i, 1, ".");
	}

	if (s[0] != '-')
		s = '+' + s;

	s = s + '+';
}

int RetPowX(string &s, int &num, int &end)
{
	int Result = 0;
	int j = num + 1;

	if (j == end)
		return 1;

	if ((s[j] == 'y') || (s[j] == 'z'))
	{
		num = j;
		return 1;
	}

	if (s[j] == '^')
		while ((j < end) && (s[j] != 'y') && (s[j] != 'z'))
			j++;

	string c = s.substr(num + 2, j - num - 2);
	Result = stoi(c);

	num = j;

	return Result;
}

int RetPowY(string &s, int &num, int &end)
{
	int Result = 0;
	int j = num + 1;

	if (j == end)
		return 1;

	if ((s[j] == 'x') || (s[j] == 'z'))
	{
		num = j;
		return 1;
	}

	if (s[j] == '^')
		while ((j < end) && (s[j] != 'x') && (s[j] != 'z'))
			j++;

	string c = s.substr(num + 2, j - num - 2);
	Result = stoi(c);

	num = j;

	return Result;
}

int RetPowZ(string &s, int &num, int &end)
{
	int Result = 0;
	int j = num + 1;

	if (j == end)
		return 1;

	if ((s[j] == 'x') || (s[j] == 'y'))
	{
		num = j;
		return 1;
	}

	if (s[j] == '^')
		while ((j < end) && (s[j] != 'x') && (s[j] != 'y'))
			j++;

	string c = s.substr(num + 2, j - num - 2);
	Result = stoi(c);

	num = j;

	return Result;
}

int GetPowX(int &d)
{
	unsigned int i = d / 100;
	if (i)
		return i;
	else
		return 0;
}

int GetPowY(int &d)
{
	unsigned int i = d / 10 % 10;

	if (i)
		return i;
	else
		return 0;
}

int GetPowZ(int &d)
{
	int i = d % 10;

	if (i)
		return i;
	else
		return 0;
}

Polynom::Polynom()
{
}

Polynom::Polynom(const Polynom &polyOut)
{
	coef = polyOut.coef;
}

Polynom::Polynom(string &s)
{
	CreatePolynom(s);
}

Polynom::~Polynom()
{
}

void Polynom::CreatePolynom(string &s)
{
	if (s.size() == 0)
	{
		coef.push_back(0);
		return;
	}

	TransformStr(s);

	while (s.size() != 1)
	{
		int st, end, num = -1;
		double coeff;
		int degree;
		int powx = 0, powy = 0, powz = 0;

		// выделяем моном
		for (int i = 0; i < s.size(); i++)
			if ((s[i] == '+') || (s[i] == '-'))
			{
				st = i;
				break;
			}

		for (int i = st + 1; i < s.size(); i++)
			if ((s[i] == '+') || (s[i] == '-'))
			{
				end = i;
				break;
			}

		// выделяем коэффициент
		for (int i = st; i < end; i++)
			if ((s[i] == 'x') || (s[i] == 'y') || (s[i] == 'z'))
			{
				num = i;
				break;
			}

		if (num == -1)
		{
			string c = s.substr(st + 1, end - st - 1);
			coeff = stod(c);

			if (s[st] == '-')
				coeff = -1 * coeff;
		}
		else
			if (num - st == 1)
					coeff = 1;
			else
			{
				string c = s.substr(st + 1, num - st - 1);
				coeff = stod(c);
			}

		if (num == -1)
		{
			coef.push_back(coeff);
			s.erase(st, end - st);
			continue; 
		}

		bool f1 = false, f2 = false;

		// выделяем степени
		if ((s[num] == 'x') && (num < end) && (!f1))
		{
			powx = RetPowX(s, num, end);
			f1 = true;

			if ((num < end) && (s[num] == 'y') && (!f2))
			{
				powy = RetPowY(s, num, end);
				f2 = true;
				if ((num < end) && (s[num] == 'z'))
					powz = RetPowZ(s, num, end);
			}

			if ((num < end) && (s[num] == 'z') && (!f2))
			{
				powz = RetPowZ(s, num, end);
				f2 = true;
				if ((num < end) && (s[num] == 'y'))
					powy = RetPowY(s, num, end);
			}
		}

		if ((s[num] == 'y') && (num < end) && (!f1))
		{
			powy = RetPowY(s, num, end);
			f1 = true;

			if ((num < end) && (s[num] == 'x') && (!f2))
			{
				powx = RetPowX(s, num, end);
				f2 = true;
				if ((num < end) && (s[num] == 'z'))
					powz = RetPowZ(s, num, end);
			}

			if ((num < end) && (s[num] == 'z') && (!f2))
			{
				powz = RetPowZ(s, num, end);
				f2 = true;
				if ((num < end) && (s[num] == 'x'))
					powx = RetPowX(s, num, end);
			}
		}

		if ((s[num] == 'z') && (num < end) && (!f1))
		{
			powz = RetPowZ(s, num, end);
			f1 = true;

			if ((num < end) && (s[num] == 'y') && (!f2))
			{
				powy = RetPowY(s, num, end);
				f2 = true;
				if ((num < end) && (s[num] == 'x'))
					powx = RetPowX(s, num, end);
			}

			if ((num < end) && (s[num] == 'x') && (!f2))
			{
				powx = RetPowX(s, num, end);
				f2 = true;
				if ((num < end) && (s[num] == 'y'))
					powy = RetPowY(s, num, end);
			}
		}

		if ((powx >= MAX_POLYNOM_POW) || (powy >= MAX_POLYNOM_POW) || (powz >= MAX_POLYNOM_POW))
			throw 3;

		degree = powx * 100 + powy * 10 + powz;

		if (s[st] == '-')
			coeff = -1 * coeff;

		coef.push_back(coeff, degree);

		// удаляем обработанный моном
		s.erase(st, end - st);
	}

	coef.Sort();
}

Polynom& Polynom::operator+=(Polynom &polyOut)
{
	Polynom Result(polyOut);

	Node<double> *p = coef.GetHead();
	Node<double> *pp;

	if (p != nullptr)
	{
		if ((p->pNext == nullptr) && (p->data == 0))
		{
			*this = Result;
			return *this;
		}

		if (*this == polyOut*(-1))
		{
			polyOut*(-1);
			string tmps = "";
			Polynom tmp(tmps);
			*this = tmp;
			return *this;
		}

		polyOut*(-1);

		pp = Result.coef.FindDegr(p->degr);

		if (pp != nullptr)
			pp->data += p->data;
		else
			Result.coef.push_back(p->data, p->degr);

		while (p->pNext != nullptr)
		{
			p = p->pNext;

			pp = Result.coef.FindDegr(p->degr);

			if (pp != nullptr)
				pp->data += p->data;
			else
				Result.coef.push_back(p->data, p->degr);
		}

		Result.ClearZero();
		Result.coef.Sort();

		*this = Result;

		return *this;
	}
	else throw exception("smth goes wrong");
}

Polynom Polynom::operator+(const Polynom &polyOut)
{
	Polynom Result(polyOut);
	Result += *this;

	return Result;
}

Polynom& Polynom::operator*(const double &scal)
{
	Node<double> *p = coef.GetHead();

	if (scal == 0)
	{
		string s = "";
		Polynom Result(s);
		*this = Result;
		return *this;
	}

	if (p != nullptr)
	{
		p->data = scal * p->data;

		while (p->pNext != nullptr)
		{
			p = p->pNext;
			p->data = scal * p->data;
		}
	}

	return *this;
}

Polynom& Polynom::operator*=(Polynom &polyOut)
{
	Polynom Result;

	Result = (*this) * polyOut;
	(*this) = Result;

	return *this;
}

Polynom Polynom::operator*(Polynom &polyOut)
{
	Node<double> *p = coef.GetHead();
	Node<double> *pp = polyOut.coef.GetHead();

	int NewDeg;
	int x1, y1, z1;
	int x2, y2, z2;
	double NewC;
	Polynom Result;

	if ((p != nullptr) && (pp != nullptr))
	{
		if ((p->pNext == nullptr) && (p->data == 0))
		{
			Result.coef.push_back(0);
			return Result;
		}

		if ((pp->pNext == nullptr) && (pp->data == 0))
		{
			Result.coef.push_back(0);
			return Result;
		}

		x1 = GetPowX(p->degr);
		y1 = GetPowY(p->degr);
		z1 = GetPowZ(p->degr);

		x2 = GetPowX(pp->degr);
		y2 = GetPowY(pp->degr);
		z2 = GetPowZ(pp->degr);

		if (((x1 + x2) < MAX_POLYNOM_POW) && ((y1 + y2) < MAX_POLYNOM_POW) && ((z1 + z2) < MAX_POLYNOM_POW))
		{
			NewC = (p->data)*(pp->data);
			NewDeg = (p->degr) + (pp->degr);
			Node<double> *tmp = Result.coef.FindDegr(NewDeg);
			if (tmp != nullptr)
				tmp->data += NewC;
			else
				Result.coef.push_back(NewC, NewDeg);
		}
		else
			throw 2;

		while (pp->pNext != nullptr)
		{
			pp = pp->pNext;

			x2 = GetPowX(pp->degr);
			y2 = GetPowY(pp->degr);
			z2 = GetPowZ(pp->degr);

			if (((x1 + x2) < 10) && ((y1 + y2) < 10) && ((z1 + z2) < 10))
			{
				NewC = (p->data)*(pp->data);
				NewDeg = (p->degr) + (pp->degr);
				Node<double> *tmp = Result.coef.FindDegr(NewDeg);
				if (tmp != nullptr)
					tmp->data += NewC;
				else
					Result.coef.push_back(NewC, NewDeg);
			}
			else
				throw 2;
		}

		pp = polyOut.coef.GetHead();

		while (p->pNext != nullptr)
		{
			p = p->pNext;

			x1 = GetPowX(p->degr);
			y1 = GetPowY(p->degr);
			z1 = GetPowZ(p->degr);

			x2 = GetPowX(pp->degr);
			y2 = GetPowY(pp->degr);
			z2 = GetPowZ(pp->degr);

			if (((x1 + x2) < 10) && ((y1 + y2) < 10) && ((z1 + z2) < 10))
			{
				NewC = (p->data)*(pp->data);
				NewDeg = (p->degr) + (pp->degr);
				Node<double> *tmp = Result.coef.FindDegr(NewDeg);
				if (tmp != nullptr)
					tmp->data += NewC;
				else
					Result.coef.push_back(NewC, NewDeg);
			}
			else
				throw 2;

			while (pp->pNext != nullptr)
			{
				pp = pp->pNext;

				x2 = GetPowX(pp->degr);
				y2 = GetPowY(pp->degr);
				z2 = GetPowZ(pp->degr);

				if (((x1 + x2) < 10) && ((y1 + y2) < 10) && ((z1 + z2) < 10))
				{
					NewC = (p->data)*(pp->data);
					NewDeg = (p->degr) + (pp->degr);
					Node<double> *tmp = Result.coef.FindDegr(NewDeg);
					if (tmp != nullptr)
						tmp->data += NewC;
					else
						Result.coef.push_back(NewC, NewDeg);
				}
				else
					throw 2;
			}

			pp = polyOut.coef.GetHead();
		}
	}

	Result.coef.Sort();

	return Result;
}

double Polynom::ValuePoint(const double &x, const double &y, const double &z)
{
	double Result = 0;
	double tmp = 0;
	int powX, powY, powZ;

	Node<double> *p = coef.GetHead();

	if (p != nullptr)
	{
		tmp = p->data;
		
		powX = GetPowX(p->degr);
		powY = GetPowY(p->degr);
		powZ = GetPowZ(p->degr);

		if (powX)
			tmp = tmp * pow(x, powX);
		if (powY)
			tmp = tmp * pow(y, powY);
		if (powZ)
			tmp = tmp * pow(z, powZ);
	
		Result += tmp;

		while (p->pNext != nullptr)
		{
			p = p->pNext;

			tmp = p->data;
			powX = GetPowX(p->degr);
			powY = GetPowY(p->degr);
			powZ = GetPowZ(p->degr);

			if (powX)
				tmp = tmp * pow(x, powX);
			if (powY)
				tmp = tmp * pow(y, powY);
			if (powZ)
				tmp = tmp * pow(z, powZ);

			Result += tmp;
		}
	}

	return Result;
}

Polynom& Polynom::operator=(const Polynom &polyOut)
{
	if (this != &polyOut)
		coef = polyOut.coef;

	return *this;
}

bool Polynom::operator==(const Polynom &polyOut) const
{
	return coef == polyOut.coef;
}

bool Polynom::operator!=(const Polynom &polyOut) const
{
	return coef != polyOut.coef;
}

void Polynom::ClearZero()
{
	Node<double> *p = coef.GetHead();

	while (p->pNext != nullptr)
	{
		p = p->pNext;
		if (p->data == 0)
			p = coef.DelELem(p);
	}

	p = coef.GetHead();

	if (p->data == 0)
		p = coef.DelELem(p);

	p = coef.GetHead();
	int NewAmount = 1;

	while (p->pNext != nullptr)
	{
		p = p->pNext;
		NewAmount++;
	}

	coef.SetAmount(NewAmount);
}

string Polynom::CreateString()
{
	string Result;
	int powX, powY, powZ;

	Node<double> *p = coef.GetHead();

	if (p != nullptr)
	{
		powX = GetPowX(p->degr);
		powY = GetPowY(p->degr);
		powZ = GetPowZ(p->degr);

		if (p->data == -1)
			Result += '-';
		else
			if (p->data != 1)
				Result += to_string(p->data);

		if (powX)
			if (powX != 1)
				Result = Result + "x^" + to_string(powX);
			else
				Result += 'x';

		if (powY)
			if (powY != 1)
				Result = Result + "y^" + to_string(powY);
			else
				Result += 'y';

		if (powZ)
			if (powZ != 1)
				Result = Result + "z^" + to_string(powZ);
			else
				Result += 'z';

		while (p->pNext != nullptr)
		{
			p = p->pNext;

			powX = GetPowX(p->degr);
			powY = GetPowY(p->degr);
			powZ = GetPowZ(p->degr);

			if (p->data > 0)
				Result += '+';

			Result += to_string(p->data);

			if (powX)
				if (powX != 1)
					Result = Result + "x^" + to_string(powX);
				else
					Result += 'x';

			if (powY)
				if (powY != 1)
					Result = Result + "y^" + to_string(powY);
				else
					Result += 'y';

			if (powZ)
				if (powZ != 1)
					Result = Result + "z^" + to_string(powZ);
				else
					Result += 'z';
		}
	}

	return Result;
}

istream& operator>>(istream &in, Polynom &polyOut)
{
	string In;
	getline(cin, In);

	polyOut.CreatePolynom(In);

	return in;
}

ostream& operator<<(ostream &out, Polynom &polyOut)
{
	string Out = polyOut.CreateString();
	cout << Out << endl;

	return out;
}