#include "TMember.h"
#include <iostream> 
#include <algorithm>
#include <map>

using namespace std;

namespace Polynomial
{
	class TPoly : private map<int, TMember>
	{
	public:
		TPoly()
		{
			//this->insert(make_pair(int(), TMember()));
		}

		TPoly(int coeff, int deg)
		{
			TMember member = TMember(coeff, deg);
			this->emplace(deg, member);
		}

		int find_degree()
		{
			int max = 0;
			for (auto& item : *this)
			{
				if (max < item.first)
					max = item.first;
			}
			return max;
		}

		int find_ratio(int deg)
		{
			if (this->find(deg) != this->end())
			{
				return this->at(deg).get_ratio();
			}
			else
			{
				return 0;
			}
		}

		TPoly add(TPoly Q)
		{
			TPoly newPoly;
			newPoly.clear();
			newPoly = *this;
			for (auto& item : Q)
			{
				if (this->find(item.first) != this->end())
				{
					TMember t(this->at(item.first).get_ratio() + item.second.get_ratio(), item.first);
					//прибавили к коэффициенту члена данной степени коэффициент при члене с той же степенью
					newPoly.erase(item.first);
					newPoly.emplace(item.first, t);

				}
				else
				{
					//если такой степени в полиноме нет, вставляем данный элемент в словарь 
					newPoly.emplace(item);
				}
			}
			return newPoly;
		}

		TPoly substract(TPoly Q)
		{
			TPoly newPoly;
			newPoly.clear();
			newPoly = *this;
			for (auto& item : Q)
			{
				if (this->find(item.first) != this->end())
				{
					//вычли из коэффициента члена данной степени коэффициент при члене с той же степенью
					if (this->at(item.first).get_ratio() != item.second.get_ratio())
					{
						TMember t(this->at(item.first).get_ratio() - item.second.get_ratio(), item.first);
						newPoly.erase(item.first);
						newPoly.emplace(item.first, t);
					}
				}
				else
				{
					//если такой степени в полиноме нет, вставляем данный элемент со знаком "-"
					item.second.set_ratio(-item.second.get_ratio());
					newPoly.emplace(item);
				}
			}
			return newPoly;
		}


		TPoly multiply(TPoly Q)
		{
			TPoly newPoly;
			newPoly.clear();
			for (auto& item : *this)
			{
				TPoly t;
				for (auto& item2 : Q)
				{
					TMember temp(item.second.get_ratio() * item2.second.get_ratio(), item.first + item2.first);
					t.emplace(item.first + item2.first, temp);
				}
				newPoly = newPoly.add(t);
			}
			return newPoly;
		}

		TPoly ChangeSign()
		{
			TPoly newPoly;
			newPoly.clear();
			for (auto& item : *this)
			{
				TMember t(-this->at(item.first).get_ratio(), item.first);
				newPoly.emplace(item.first, t);
			}
			return newPoly;
		}

		TPoly diff()
		{
			TPoly newPoly;
			newPoly.clear();
			for (auto& item : *this)
			{
				if (item.first != 0 || this->size()==1)
				{
					newPoly.emplace(item.second.get_degree() - 1, item.second.diff());
				}
			}
			return newPoly;
		}

		double calc(double i)
		{
			double sum = 0;
			for (auto& item : *this)
			{
				sum += item.second.calc(i);
			}
			return sum;
		}

		bool friend operator==(const TPoly& c1, const TPoly& c2)
		{
			if (c1.size() != c2.size()) return false;

			for (auto& item : c1)
			{
				//если во втором полиноме такой степени нет
				if (c2.end() == c2.find(item.first)) return false;
				//если коэффициенты не равны
				if (item.second != c2.at(item.first)) return false;
			}
			return true;
		}

		TPoly make_null()
		{
			this->clear();
			TMember res(0, 0);
			this->emplace(0, res);
			return *this;
		}

		TMember get_element(int i)
		{
			if (i < 0 || i >= this->size()) throw new exception("get_element: invalid index");
			int iter = 0;
			TMember res;
			for (auto& item : *this)
			{
				if (iter == i)
				{
					res = item.second;
					return res;
				}
				iter++;
			}
			return res;
		}

		string to_string()
		{
			string str = "";
			for (auto& item : *this)
			{
				if (item.second.get_ratio() > 0)
					str += ("+" + item.second.to_string());
				else
					str += item.second.to_string();
			}
			if (str[0] == '+') str.erase(0, 1);

			return str;
		}
	};
}
