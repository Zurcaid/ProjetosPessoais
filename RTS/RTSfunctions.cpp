#include "RTSconstants.h"
#include "RTSfunctions.h"

using namespace std;
#include <iostream>
#include <vector>
#include <cstdlib>
#include <limits>
#include <math.h>
#include <algorithm>

string player_input, input1, input2, input3;

vector<vector<King>> kings = {{NoviceKing, ProphesiedKing, KingOfKings, Conqueror, GodEmperor, BringerOfLight, Tyrant, Wise, Undying, IronFist, Golden, Exiled, MadKing, DragonBorn, TheJust, Cruel, YoungLion, OldOak, Bloodstained, Saint, SeaLord}};

vector<vector<Champions>> commanders = {{MiyamotoMusashi, Spartacus}};

vector<vector<Troops>> soldier = {{Knight_1, Archer_1, Shielder_1, Horse_1}};

vector<vector<Troops>> medieval_troops = {{}, {}, {}, {}};
vector<vector<Buildings>> medieval_buildings = {{}, {}, {}};

vector<vector<Buildings>> constructions = {{}, {}, {}, {}, {}, {}, {}, {}};

vector<Civilization> allCivilizations;
vector<BotIA> botManagement;

// Funcoes relativas ao gerenciamento da cidade
// a=kind,b=king;c=dist_x;d=dist_y
Civilization::Civilization(int a, int b, int c, int d)
{
	kind = a;
	king = b;

	raw_food = 50 + (rand() % 50);
	stone = 50 + (rand() % 50);
	wood = 50 + (rand() % 50);
	money = 50 + (rand() % 50);
	chemicals = 50 + (rand() % 50);

	dist_x = c;
	dist_y = d;
	identifier = rand() % std::numeric_limits<unsigned int>::max();
	alignment = 50; // kings.at(a).at(b).alignment;
}

Civilization *findCivilization(int id)
{
	for (int i = 0; i < allCivilizations.size(); i++)
	{
		if (allCivilizations.at(i).identifier == id)
		{
			return &allCivilizations.at(i);
		}
	}
	return nullptr;
}

void Civilization::setTroops(int x, int k, int n)
{
	// troops.push_back(x);
	// troops_kind.push_back(k);
	// troops_num.push_back(n);
	int size = troops.size();
	int pos = size - 1;
	int flag = 0;
	for (int i = 0; i < size; i++)
	{
		if ((troops.at(i) == x) and (troops_kind.at(i) == k))
		{
			troops_num.at(pos) = troops_num.at(pos) + n;
			return;
		}
	}
	troops.push_back(x);
	troops_kind.push_back(k);
	troops_num.push_back(n);
}

void Civilization::buildingsMonthlyUpdates()
{
	int size = buildings.size();
	for (int i = 0; i < size; i++)
	{
		buildings.at(i).monthlyUpdate(*this);
	}
}

void Civilization::championsMonthlyUpdates()
{
	int size = champions.size();
	for (int i = 0; i < size; i++)
	{
		champions.at(i).monthlyUpdate(*this);
	}
}

void Civilization::civilWar()
{
}

void Civilization::monthlyUpdates()
{

	aproval = 0;
	if (population <= 4)
		alive = 0;
	if (!alive)
		return;
	int storage1 = 0, storage2 = 0;
	health_increase = 0;
	education_increase = 0;
	buildingsMonthlyUpdates();
	championsMonthlyUpdates();

	lvl = 1 + sqrt(population / 20) + (xp / 100);

	health = health_increase / (population + 1);
	education = education_increase / (population + 1);

	if (education > 1)
		education = 1.0;
	if (health > 1)
		health = 1.0;

	float prev_population = population;
	if ((food - population) < 0)
	{
		storage1 = population - (food * 2);
		food = 0;
		if (((raw_food)-storage1) < 0)
		{
			storage2 = storage1 - (raw_food);
			raw_food = 0;
			aproval -= 50;
			population -= storage2 / 2;
		}
		else
		{
			raw_food -= storage1;
			if (population > 2)
			{
				population += population * health / (2 + (rand() % 4));
				aproval += 50;
			}
		}
	}
	else
	{
		food -= population;
		if (population > 2)
		{
			aproval += 50;
			population += population * health / (2 + (rand() % 4));
		}
	}

	growing_rate = prev_population / population;
	// cout << prev_population << "\t" << population << endl;

	if (education <= 0)
		education = 0.001;
	if (health <= 0)
		health = 0.001;

	int troop_qnt = 0;
	for (int i = 0; i < troops.size(); i++)
		troop_qnt += troops_num.at(i);

	storage1 = criminal;
	criminal = (population * lvl / 10) / (troop_qnt * education + 1);
	population -= (criminal - storage1);

	aproval += 50 * education;
	aproval += 50 * health;
	aproval = aproval * (1 - (criminal / (abs(population) + 1)));
	if (aproval < 0)
		aproval = 0;
	if (aproval > 100)
		aproval = 100;

	if (aproval <= 10)
		civil_war_chance += 5 + ((10 - aproval) * 10);
	if (aproval >= 70)
		civil_war_chance -= 5;
	if (civil_war_chance >= 100)
	{
		civilWar();
	}
	storage1 = kings.at(kind).at(king).lvl;
	moral += storage1 / 10;
	addNationKnown();
}

void Civilization::defineEmperor()
{
	// emperor_titles.push_back(kings.at(kind).at(king));
}

void Civilization::addEmperorTitle(int index)
{
	emperor_titles.push_back(kings.at(0).at(index));
}

void Civilization::exploreDirection(int a)
{
	if (a == 1)
	{
		explored_n += 200;
	}
	else if (a == 2)
	{
		explored_s += 200;
	}
	else if (a == 3)
	{
		explored_e += 200;
	}
	else if (a == 4)
	{
		explored_w += 200;
	}
}

void Civilization::addNationKnown()
{
	int size = nations_unknown.size();
	int found_x, found_y;
	int min_x = distance(nations_unknown_x.begin(), lower_bound(nations_unknown_x.begin(), nations_unknown_x.end(), -explored_w));
	int max_x = distance(nations_unknown_x.begin(), upper_bound(nations_unknown_x.begin(), nations_unknown_x.end(), explored_e));

	for (int i = min_x; i < max_x; i++)
	{
		if ((nations_unknown_y.at(i) >= -explored_s) && (nations_unknown_y.at(i) <= explored_n))
		{
			nations_known.push_back(nations_unknown.at(i));
			nations_unknown.erase(nations_unknown.begin() + i);
			nations_unknown_x.erase(nations_unknown_x.begin() + i);
			nations_unknown_y.erase(nations_unknown_y.begin() + i);
			i--;
			max_x--;
		}
	}
}

void Civilization::setNationsUnknown()
{
	vector<int> ordering_array;
	int flag = 0;
	ordering_array.push_back(0);
	for (int i = 1; i < allCivilizations.size(); i++)
	{
		flag = 0;
		if (allCivilizations.at(i).identifier == identifier)
		{
			continue;
		}
		for (int j = ordering_array.size(); j > 0; j--)
		{
			if ((allCivilizations.at(i).dist_x > allCivilizations.at(ordering_array.at(j - 1)).dist_x))
			{
				if (j == ordering_array.size())
				{
					ordering_array.push_back(i);
					flag = 1;
					break;
				}
				ordering_array.insert(ordering_array.begin() + j, i);
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			ordering_array.insert(ordering_array.begin(), i);
		}
	}
	for (int i = 0; i < ordering_array.size(); i++)
	{
		nations_unknown.push_back(allCivilizations.at(ordering_array.at(i)).identifier);
		nations_unknown_x.push_back(allCivilizations.at(ordering_array.at(i)).dist_x);
		nations_unknown_y.push_back(allCivilizations.at(ordering_array.at(i)).dist_y);
	}
}

void Civilization::report()
{
	cout << end_of_page;
	cout << "Civilization [" << identifier << "]\t-\tPosition: (" << dist_x << "," << dist_y << ")" << endl;
	cout << "Level: " << lvl << "\t" << "Tech level: " << tech_lvl << "\tAlive: " << (alive != 0) << "\t Criminals: " << criminal << endl;
	cout << "Population: " << population << "\tTroops: ";
	int troop_qnt = 0;
	for (int i = 0; i < troops.size(); i++)
		troop_qnt += troops_num.at(i);
	cout << troop_qnt;
	cout << "\tBuildings: " << buildings.size() << endl;
	cout << "Money: " << money << "\tWood: " << wood << "\tStone: " << stone << "\tRaw Food: " << raw_food << endl;
	cout << "Food: " << food << "\tSteel: " << steel << "\tChemicals: " << chemicals << "\tGear: " << gear << endl;
	cout << "Education: " << education << "\tHealth: " << health << "\tApproval: " << aproval << "\tGrowth rate: " << growing_rate << endl;
	int rawfood_gen = 0;
	int food_gen = 0;
	cout << "Raw food generation: ";
	for (int i = 0; i < buildings.size(); i++)
	{
		rawfood_gen += buildings.at(i).raw_food * buildings.at(i).integrity * lvl;
		food_gen += buildings.at(i).food * buildings.at(i).integrity * lvl;
	}
	cout << rawfood_gen;

	cout << "\tFood generation: " << food_gen << "\tNations known: " << nations_known.size() << endl;

	// cout << "Buildings: ";
	// for (int i = 0; i < troops.size(); i++)
	// 	cout << medieval_troops.at(troops_kind.at(i)).at(troops.at(i)).name << " | ";
	// for (int i = 0; i < buildings.size(); i++)
	// 	cout << buildings.at(i).name << " - Raw_food gen: " << buildings.at(i).raw_food << " | ";
	// for (int i = 0; i < nations_known.size(); i++)
	// 	cout << nations_known.at(i) << " | ";
	cout << endl;
	cout << end_of_page;
}

// Funcoes relativas ao gerenciamento de reis
// a=kingdom,b=age,c=max_age,d=hp,e=dmg,f=alignment,g=troop_capacity,h=name;
King::King(int a, int b, int c, int d, int e, int f, int g, string h)
{
	name = h;
	kingdom = a;
	age = b;
	max_age = c;
	hp = d;
	dmg = e;
	alignment = f;
	troop_capacity = g;
}

// Funcoes relativas ao gerenciamento de comandantes
// a=kingdom,b=capacity,c=loyalty,d=xp,e=dmg,f=hp,g=archery_boost,h=melee_boost,i=defender_boost,j=beast_boost,k=dmg_boost,l=hp_boost,m=foodcost_boost,n=moral_boost, o=alignment, p=name;
Champions::Champions(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, string p)
{
	name = p;
	kingdom = a;
	capacity = b;
	loyalty = c;
	xp = d;
	dmg = e;
	hp = f;
	archery_boost = g;
	melee_boost = h;
	defender_boost = i;
	beast_boost = j;
	dmg_boost = k;
	hp_boost = l;
	foodcost_boost = j;
	moral_boost = n;
	alignment = o;
}

void Champions::changeXp(int x)
{
	xp += x;
}

void Champions::raid(Civilization Obj1)
{
}

void Champions::monthlyUpdate(Civilization Obj1)
{
	lvl = (xp / 100) + 1;
	hp = hp * lvl;
	dmg = dmg * lvl;
	if (((Obj1.alignment + 30 < alignment) and (alignment > 50)) or ((Obj1.alignment - 30 > alignment) and (alignment < 50)))
	{
		raid_chance += 100 - loyalty;
	}
	if (raid_chance >= 100)
	{
		raid(Obj1);
	}
}

// Funcoes relativas ao gerenciamento de tropas
// a=kingdom,b=kind,c=ranged,d=food_cost_per_month,e=dmg,f=hp,g=size,h=name
Troops::Troops(int a, int b, int c, int d, int e, int f, int g, string h)
{
	kingdom = a;
	kind = b;
	ranged = c;
	food_cost_per_month = d;
	dmg = e;
	hp = f;
	size = g;
	name = h;
}

void setupTroops()
{
	int size1 = 4;
	int size2 = 3;
	for (int i1 = 0; i1 < size1; i1++)
	{
		for (int i2 = 0; i2 < size2; i2++)
		{
			int size3 = sizeof(medieval_troops_list[i1][i2]) / sizeof(medieval_troops_list[i1][i2][0]);
			for (int i3 = 0; i3 < size3; i3++)
			{
				if (medieval_troops_list[i1][i2][i3] == "0")
					continue;
				if (i1 == 0)
				{
					int hp = 10 + (2 * i3) + (20 * i2);
					int dmg = 10 + (2 * i3) + (20 * i2);
					string name = medieval_troops_list[i1][i2][i3];
					Troops MedievalSoldier(0, 1, 0, 3, dmg, hp, 2, name);
					medieval_troops.at(i1).push_back(MedievalSoldier);
				}
				else if (i1 == 1)
				{
					int hp = 2 + (2 * i3) + (5 * i2);
					int dmg = 5 + (2 * i3) + (15 * i2);
					string name = medieval_troops_list[i1][i2][i3];
					Troops MedievalArcher(0, 2, 1, 2, dmg, hp, 2, name);
					medieval_troops.at(i1).push_back(MedievalArcher);
				}
				else if (i1 == 2)
				{
					int hp = 15 + (5 * i3) + (30 * i2);
					int dmg = 3 + (2 * i3) + (10 * i2);
					string name = medieval_troops_list[i1][i2][i3];
					Troops MedievalShielder(0, 3, 0, 5, dmg, hp, 3, name);
					medieval_troops.at(i1).push_back(MedievalShielder);
				}
				else if (i1 == 3)
				{
					int hp = 15 + (20 * i3) + (50 * i2);
					int dmg = 15 + (10 * i2) + (15 * i2 * (i3 + 1));
					int size = 5 + (5 * (i2 * i2));
					string name = medieval_troops_list[i1][i2][i3];
					int ranged = 0;
					int food = 10;
					if ((i2 == 2) and (i3 == 2))
						ranged = 1;
					if (i2 == 2)
						food = 0;
					Troops MedievalAnimal(0, 4, ranged, food, dmg, hp, size, name);
					medieval_troops.at(i1).push_back(MedievalAnimal);
				}
			}
		}
	}
}

// Funcoes relativas ao gerenciamento de exercitos
Army::Army(Champions leader, int leader_row, int moral, Troops row1, int row1_qnt, Troops row2, int row2_qnt, Troops row3, int row3_qnt)
{
	float moral_inc = (moral / 100) * (leader.moral_boost / 100);
	float boost_array[5];
	boost_array[0] = 1.0;
	boost_array[1] = leader.melee_boost / 100;
	boost_array[2] = leader.archery_boost / 100;
	boost_array[3] = leader.defender_boost / 100;
	boost_array[4] = leader.beast_boost / 100;

	row1_hp = row1.hp * row1_qnt * boost_array[row1.kind];
	row1_dmg = row1.dmg * row1_qnt * moral_inc * boost_array[row1.kind];
	row1_ranged = row1.ranged;

	row2_hp = row2.hp * row2_qnt * boost_array[row2.kind];
	row2_dmg = row2.dmg * row2_qnt * moral_inc * boost_array[row2.kind];
	row2_ranged = row2.ranged;

	row3_hp = row3.hp * row3_qnt * boost_array[row3.kind];
	row3_dmg = row3.dmg * row3_qnt * moral_inc * boost_array[row3.kind];
	row3_ranged = row3.ranged;

	food_cost = ((row1.food_cost_per_month * row1_qnt) + (row2.food_cost_per_month * row2_qnt) + (row3.food_cost_per_month * row3_qnt)) * leader.foodcost_boost;
}

// Funcoes relativas ao gerenciamento de construcoes

// t1=tech_req,nvl=lvl_required,a=kingdom,b=sector,c=type_id, nm=name, troop_type=troops;
Buildings::Buildings(float t1, int nvl, int a, int b, int c, string nm, int troop_kind = 0, int troop_type = 0, int troop_rm = 999)
{
	// Setor 1: Estracao de recursos da natureza.
	// Setor 2: Refinamento ou utilizacao dos recursos extraidos.
	// Setor 3: Venda dos recursos ou sem relacao com os recursos e sim com as pessoas.
	name = nm;
	tech_req = t1;
	lvl_req = nvl;
	kingdom = a;
	sector = b;
	type_id = c;
	float gen = lvl_req * tech_req * 10;
	int qnt_rm = gen * (-1);
	int worker = (gen / 10) + 2;
	degradation_rate = 0.01 / tech_req;
	if (tech_req >= 10)
	{
		steel_cost = tech_req * lvl_req * 0.9;
		stone_cost = steel_cost * 2;
		cost = (steel_cost + stone_cost) / 2;
	}
	else
	{
		wood_cost = lvl_req * 2;
		stone_cost = wood_cost * 0.8;
		cost = (wood_cost + stone_cost) / 2;
	}
	if (sector == 1)
	{ // Setor 1
		switch (type_id)
		{
		case 1: // Producao de alimentos
			raw_food = gen;
			break;
		case 2: // Extracao de madeira
			wood = gen;
			break;
		case 3: // Extracao de pedras
			stone = gen;
			break;
		case 4: // Extracao de minerios
			ores = gen;
			break;
		}
	}
	else if (sector == 2)
	{ // Setor 2
		switch (type_id)
		{
		case 1: // Industria alimenticia
			raw_food = qnt_rm;
			food = gen;
			break;
		case 2: // Industria metalurgica
			ores = qnt_rm;
			steel = gen;
			break;
		case 3: // Industria quimica
			wood = qnt_rm;
			chemicals = gen;
			break;
		case 4: // Industria armamentista
			if (tech_req >= 5)
			{
				steel = qnt_rm / 2;
			}
			else
			{
				stone = qnt_rm / 2;
			}
			gear = gen;
			break;
		case 5: // Industria de bens de consumo
			wood = qnt_rm;
			products = gen;
			break;
		case 6: // Institutos de pesquisa
			chemicals = qnt_rm / 2;
			money = qnt_rm;
			tech_gen = (gen * 2) / (100 * lvl_req);
			education = gen;
			break;
		}
	}
	else if (sector == 3)
	{ // Setor 3
		switch (type_id)
		{
		case 1: // Comercios gerais
			money = gen;
			break;
		case 2: // Hospitais
			money = qnt_rm;
			chemicals -= qnt_rm / 2;
			health = gen;
			grow_rate = gen / 5;
			break;
		case 3: // Escolas
			money = qnt_rm / 2;
			education = gen;
			break;
		case 4: // Prisoes/postos de policia
			criminal = worker * -3;
			break;
		case 5: // Academias para reinamento de soldados
			if (troops_remove != 999)
				troops_remove = troop_rm;
			gear -= qnt_rm;
			troops_kind = troop_kind;
			troops = troop_type;
			troops_num = worker;
			worker = (troops_num / 10) + 1;
			break;
		}
	}
	else
	{
		cout << "Error: Bad construction setup.";
	}
}

int Buildings::buildConstruction(Civilization &Obj)
{
	if ((Obj.money >= cost) and (Obj.wood >= wood_cost) and (Obj.stone >= stone_cost) and (Obj.steel >= steel_cost) and (Obj.lvl >= lvl_req) and (Obj.tech_lvl >= tech_req))
	{
		float food_necessity = Obj.population / (abs((Obj.food * 2) + Obj.raw_food + Obj.population) + 1);
		float health_necessity = Obj.population / ((Obj.health * 4) + Obj.population + 1);
		Obj.money -= cost;
		Obj.wood -= wood_cost;
		Obj.stone -= stone_cost;
		Obj.steel -= steel_cost;
		Obj.worker += worker;
		position += Obj.buildings.size();
		Buildings Construction(tech_req, lvl_req, kingdom, sector, type_id, name, troops_kind, troops, troops_remove);
		Obj.buildings.push_back(Construction);
		if (((sector == 1) and (type_id == 1)) or ((sector == 2) and (type_id == 1)))
			Obj.aproval += 20 * food_necessity;
		if ((sector == 3) and (type_id == 2))
			Obj.aproval += 15 * health_necessity;
		return 1;
	}
	else
	{
		return 0;
	}
}

void Buildings::monthlyUpdate(Civilization &Obj)
{
	int storage;
	integrity -= degradation_rate;

	if ((Obj.money <= (abs(money) * integrity * Obj.lvl) and money < 0) or (Obj.gear <= (abs(gear) * integrity * Obj.lvl) and gear < 0) or (Obj.steel <= (abs(steel) * integrity * Obj.lvl) and steel < 0) or ((Obj.chemicals <= (abs(chemicals) * integrity * Obj.lvl)) and chemicals < 0) or (Obj.food <= (abs(food) * integrity * Obj.lvl) and food < 0) or (Obj.ores <= (abs(ores) * integrity * Obj.lvl) and ores < 0) or (Obj.wood <= (abs(wood) * integrity * Obj.lvl) and wood < 0) or (Obj.stone <= (abs(stone) * integrity * Obj.lvl) and stone < 0) or (Obj.raw_food <= (abs(raw_food) * integrity * Obj.lvl) and raw_food < 0))
	{
		return;
	}
	// if ((Obj.chemicals <= (chemicals * integrity * Obj.lvl)) and chemicals < 0 or (Obj.chemicals <= 0))
	// 	return;
	// if (chemicals < 0)
	// {
	// 	cout << "Chems: " << Obj.chemicals << "\tRmv quantity: " << chemicals * Obj.lvl << endl;
	// }
	Obj.tech_lvl += tech_gen * integrity;
	Obj.money += money * integrity * Obj.lvl;
	Obj.gear += gear * integrity * Obj.lvl;
	Obj.steel += steel * integrity * Obj.lvl;
	Obj.chemicals += chemicals * integrity * Obj.lvl;
	Obj.food += food * integrity * Obj.lvl;
	Obj.ores += ores * integrity * Obj.lvl;
	Obj.wood += wood * integrity * Obj.lvl;
	Obj.stone += stone * integrity * Obj.lvl;
	Obj.raw_food += raw_food * integrity * Obj.lvl;
	Obj.education_increase += education * integrity * Obj.lvl;
	Obj.health_increase += health * integrity * Obj.lvl;

	int troop_qnt = 0;
	for (int i = 0; i < Obj.troops.size(); i++)
		troop_qnt += Obj.troops_num.at(i);

	if (troops_kind < 500)
	{
		if ((rand() % 3 < 3) && (troop_qnt < (Obj.population * 0.1)))
		{
			Obj.setTroops(troops, troops_kind, (troops_num * Obj.lvl));
		}
	}
	if (criminal != 0)
	{
		storage = criminal;
		if (criminal > Obj.criminal)
			storage = Obj.criminal;
		Obj.criminal += storage;
		Obj.population -= storage;
	}
}

void setupBuildings()
{
	int size1 = 3;
	int size2 = 6;
	int size3 = 5;
	for (int i1 = 0; i1 < size1; i1++)
	{
		for (int i2 = 0; i2 < size2; i2++)
		{
			for (int i3 = 0; i3 < size3; i3++)
			{
				int sector = i1 + 1;
				int type_id = i2 + 1;
				int lvl_req = 1 + (i3 * 20);
				float tech_req = 1 + (i3 * 3);
				string name = medieval_buildings_list[i1][i2][i3];
				if (name == "0")
					continue;
				if ((i1 != 2) or (i2 != 4))
				{
					Buildings MedievalBuilding(tech_req, lvl_req, 0, sector, type_id, name);
					medieval_buildings.at(i1).push_back(MedievalBuilding);
				}
				else
				{
					int size4 = 4;
					for (int i4 = 0; i4 < size4; i4++)
					{
						int size5 = medieval_troops.at(i4).size();
						for (int i5 = 0; i5 < size5; i5++)
						{
							tech_req = 1 + (i5 * (14.4 / size5));
							lvl_req = 1;
							int troop_rm = i5 - 1;
							if ((i5 == 0) or (i4 == 3))
							{
								troop_rm = 999;
							}
							string tname = medieval_troops.at(i4).at(i5).name + name;
							Buildings MedievalBuilding(tech_req, lvl_req, 0, sector, type_id, tname, i4, i5, troop_rm);
							medieval_buildings.at(i1).push_back(MedievalBuilding);
						}
					}
				}
			}
		}
	}
}

// Funcoes relativas ao gerenciamento de NPCs
BotIA::BotIA(Civilization &Obj1)
{
	BotCivilization = &Obj1;
}

void BotIA::botBuild()
{
	float population = BotCivilization->population;
	int lvl = BotCivilization->lvl;

	int food_gen = 0;
	int rawfood_gen = 0;
	for (int i = 0; i < BotCivilization->buildings.size(); i++)
	{
		food_gen += BotCivilization->buildings.at(i).food * BotCivilization->buildings.at(i).integrity * lvl;
		rawfood_gen += BotCivilization->buildings.at(i).raw_food * BotCivilization->buildings.at(i).integrity * lvl;
	}
	// cout << food_gen << endl;
	float food_necessity = population * 10 / ((food_gen * 2) + rawfood_gen + 1);
	float health_necessity = 1 - BotCivilization->health;
	float tech_necessity = (((BotCivilization->money - (BotCivilization->money % 1000)) / 1000) / (BotCivilization->tech_lvl + 1)) * 0.25;
	float chem_necessity = ((tech_necessity + health_necessity) * BotCivilization->tech_lvl * lvl) / ((BotCivilization->chemicals + 1));

	int size = BotCivilization->troops.size();
	float war_power = 0.1;
	for (int i = 0; i < size; i++)
	{
		int pos = BotCivilization->troops.at(i);
		int kind = BotCivilization->troops_kind.at(i) - 1;
		float troop_power = (medieval_troops.at(kind).at(pos).hp * medieval_troops.at(kind).at(pos).dmg) / 100;
		war_power += troop_power * BotCivilization->troops_num.at(i);
	}

	float troop_necessity = population / (war_power * 100 + 1);
	if (population < (war_power * 10))
		troop_necessity = 0;
	float gear_necessity = ((troop_necessity * lvl * BotCivilization->tech_lvl) / 2) / (BotCivilization->gear + 1);
	float cost_necessity = food_necessity + health_necessity + troop_necessity + gear_necessity;
	float stone_necessity = (cost_necessity * 2 * lvl) * 10 / (BotCivilization->stone + 1);
	float wood_necessity;
	float steel_necessity;
	if (BotCivilization->tech_lvl <= 10)
	{
		wood_necessity = (cost_necessity * 2 * lvl) * 19 / (BotCivilization->wood + 1);
		steel_necessity = ((gear_necessity * lvl * BotCivilization->tech_lvl) / 2) / (BotCivilization->steel + 1);
	}
	else
	{
		wood_necessity = ((cost_necessity - troop_necessity) - gear_necessity) / (BotCivilization->wood + 1);
		steel_necessity = (((cost_necessity * lvl * BotCivilization->tech_lvl) + (gear_necessity * lvl * BotCivilization->tech_lvl) / 2)) / (BotCivilization->steel + 1);
	}
	cost_necessity += stone_necessity + steel_necessity + wood_necessity;
	float money_necessity = 30 * (cost_necessity * lvl * BotCivilization->tech_lvl) / (BotCivilization->money + 1);
	vector<float> necessities = {food_necessity, health_necessity, tech_necessity, chem_necessity, troop_necessity, gear_necessity, stone_necessity, wood_necessity, steel_necessity, money_necessity};
	size = necessities.size();
	// cout << "Food necessity: " << food_necessity << endl;
	// cout << "Health necessity: " << health_necessity << endl;
	// cout << "Tech necessity: " << tech_necessity << endl;
	// cout << "Chemicals necessity: " << chem_necessity << endl;
	// cout << "Troop necessity: " << troop_necessity << endl;
	// cout << "Gear necessity: " << gear_necessity << endl;
	// cout << "Stone necessity: " << stone_necessity << endl;
	// cout << "Wood necessity: " << wood_necessity << endl;
	// cout << "Steel necessity: " << steel_necessity << endl;
	// cout << "Money necessity: " << money_necessity << endl;

	vector<int> order;
	for (int i1 = 0; i1 < size; i1++)
	{
		float necessity = necessities.at(i1);
		bool inserted = false;
		for (size_t i2 = 0; i2 < order.size(); i2++)
		{
			if (necessity > necessities.at(order.at(i2)))
			{
				order.insert(order.begin() + i2, i1);
				inserted = true;
				break;
			}
		}
		if (!inserted)
			order.push_back(i1);
	}
	int max_amount = rand() % 4;
	for (int i1 = 0; i1 < max_amount; i1++)
	{
		int pos_in_array, build_sector;
		int unemployed = (population - BotCivilization->worker) - BotCivilization->criminal;
		int build = 0;
		int necessity = order.at(i1);
		if (necessity == 0)
		{ // Comida
			int rawfood_gen = 0;
			int food_gen = 0;
			for (int i2 = 0; i2 < BotCivilization->buildings.size(); i2++)
			{
				rawfood_gen += BotCivilization->buildings.at(i2).raw_food;
				food_gen += BotCivilization->buildings.at(i2).food;
			}
			build_sector = 1;
			pos_in_array = 0;
			if (rawfood_gen < BotCivilization->population)
			{
				build_sector = 0;
			}
			for (int i2 = pos_in_array + 4; i2 >= pos_in_array; i2 -= 1)
			{
				Buildings *actual_building = &medieval_buildings.at(build_sector).at(i2);
				if (BotCivilization->raw_food > actual_building->raw_food)
				{
					if (unemployed > actual_building->worker)
						build = actual_building->buildConstruction(*BotCivilization);
				}
				else
				{
					actual_building = &medieval_buildings.at(build_sector).at(i2);
					if (unemployed > actual_building->worker)
						build = actual_building->buildConstruction(*BotCivilization);
				}
				if (build == 1)
					break;
			}
		}
		else
		{
			switch (necessity)
			{
			case 1: // Saude
				pos_in_array = 5;
				build_sector = 2;
				break;
			case 2: // tecnologia
				pos_in_array = 25;
				build_sector = 1;
				break;
			case 3: // Produtos quimicos
				pos_in_array = 10;
				build_sector = 1;
				break;
			case 4: // Tropas
				// Para tropas a configuracao e diferente
				pos_in_array = 20;
				build_sector = 2;
				break;
			case 5: // Equipamento
				pos_in_array = 15;
				build_sector = 1;
				break;
			case 6: // Pedra
				pos_in_array = 10;
				build_sector = 0;
				break;
			case 7: // Madeira
				pos_in_array = 5;
				build_sector = 0;
				break;
			case 8: // Metal
				pos_in_array = 5;
				build_sector = 1;
				break;
			case 9: // Dinheiro
				pos_in_array = 0;
				build_sector = 2;
				break;
			default:
				break;
			}
			if (necessity == 4)
			{
				int size = medieval_buildings.at(build_sector).size();
				vector<int> buildings_pos;
				int troop_type = rand() % 3;
				int quantity;
				if (troop_type == 0)
				{
					size = 0;
					quantity = 18;
				}
				else if (troop_type == 1)
				{
					size = 18;
					quantity = 18;
				}
				else if (troop_type == 2)
				{
					size = 36;
					quantity = 9;
				}
				else if (troop_type == 3)
				{
					size = 45;
					quantity = 9;
				}
				for (int i = pos_in_array + size + quantity; i >= pos_in_array + size; i -= 1)
				{
					Buildings *actual_building = &medieval_buildings.at(build_sector).at(i);
					if (unemployed >= actual_building->worker)
						build = actual_building->buildConstruction(*BotCivilization);
					if (build == 1)
						break;
				}
			}
			else
			{
				for (int i3 = (pos_in_array + 4); i3 >= (pos_in_array); i3 -= 1)
				{
					Buildings *actual_building = &medieval_buildings.at(build_sector).at(i3);
					if (unemployed >= actual_building->worker)
						build = actual_building->buildConstruction(*BotCivilization);
					if (build == 1)

						break;
				}
			}
		}
	}
}

void BotIA::botRepair()
{
	for (int i = 0; i < BotCivilization->buildings.size(); i++)
	{
		if (BotCivilization->buildings.at(i).integrity < 0.5)
		{
			if ((BotCivilization->money >= BotCivilization->buildings.at(i).cost) and (BotCivilization->wood >= BotCivilization->buildings.at(i).wood_cost) and (BotCivilization->stone >= BotCivilization->buildings.at(i).stone_cost) and (BotCivilization->steel >= BotCivilization->buildings.at(i).steel_cost))
			{
				BotCivilization->money -= BotCivilization->buildings.at(i).cost;
				BotCivilization->wood -= BotCivilization->buildings.at(i).wood_cost;
				BotCivilization->stone -= BotCivilization->buildings.at(i).stone_cost;
				BotCivilization->steel -= BotCivilization->buildings.at(i).steel_cost;
				BotCivilization->buildings.at(i).integrity = 1;
			}
		}
	}
}

void BotIA::botTurn()
{
	if (!BotCivilization->alive)
		return;
	// Fase de exploracao
	int random1 = rand() % 4 + 1;
	BotCivilization->exploreDirection(random1);

	// Fase de construcao
	botBuild();
	botRepair();

	// cout << "Bot [" << BotCivilization->identifier << "] explored direction: " << random1 << endl;
	// BotCivilization->report();
}

// Funcoes relativas ao andamento do jogo

Civilization PlayerKingdom(0, 0, 0, 0);

int beginGame()
{
	setupTroops();
	setupBuildings();
	cout << end_of_page;
	cout << "Choose how do you want to proceed:\n1 - New game.\n2 - Load game.\nYour choice: ";
	cin >> input1;
	if (input1 == "1")
	{
		return 1;
	}
	else if (input1 == "2")
	{
		return 2;
	}
	else
	{
		cout << "No option selected, select again.\n";
		return beginGame();
	}
}

void startNewPlayer()
{
	difficulty = 1;
	style = 1;
	allCivilizations.push_back(PlayerKingdom);
	while (!difficulty)
	{
		cout << end_of_page;
		cout << "Select a difficulty:\n1 - Easy: All kingdoms start at lvl 1.\n2 - Normal: Some kingdoms are already developed.\n3 - Hard: All kingdoms are already stablished.\nYour choice: ";
		cin >> input1;
		if (input1 == "1")
			difficulty = 1;
		else if (input1 == "2")
			difficulty = 2;
		else if (input1 == "3")
			difficulty = 3;
		else
			cout << "No option selected, select again.\n";
	}
	while (!style)
	{
		cout << end_of_page;
		cout << "This game contains unrealistic elements like magic and mythical creatures, do you want to disable this elements?\n1 - Unable fantasy elements.\n2 - Keep fantasy elements.\nYour choice: ";
		cin >> input1;
		if (input1 == "1")
			style = 1;
		else if (input1 == "2")
			style = 2;
		else
			cout << "No option selected, select again.\n";
	}

	while (PlayerKingdom.emperor_name == "")
	{
		cout << end_of_page;
		cout << "Digit the name of your character: ";
		cin >> input1;
		cout << "Are you sure your character's name is: '" << input1 << "' ?\n1 - Yes.\n2 - No.\nYour choice: ";
		cin >> input2;
		if (input2 == "1")
		{
			PlayerKingdom.emperor_name = input1;
		}
	}
	while (PlayerKingdom.civilization_name == "")
	{
		cout << end_of_page;
		cout << "Digit the name of your empire: ";
		cin >> input1;
		cout << "Are you sure the your empire's name is: '" << input1 << "' ?\n1 - Yes.\n2 - No.\nYour choice: ";
		cin >> input2;
		if (input2 == "1")
		{
			PlayerKingdom.civilization_name = input1;
		}
	}
	int king_selected = 100;
	int kind_selected;
	int inputnumber;
	if (style == 2)
	{
		while (king_selected == 100)
		{
			cout << end_of_page;
			cout << "Choose a civilization kind:\n0 - Human\n1 - Holy\n2 - Evil\n3 - Deity\n4 - Witchcraft\n5 - Technology\n6 - Biotechnology\nChoose one to see the types of king you can select: ";
			while (!(cin >> kind_selected))
			{
				cout << "No option selected, choose again.\n";
				cout << end_of_page;
				cout << "Choose a civilization kind:\n0 - Human\n1 - Holy\n2 - Evil\n3 - Deity\n4 - Witchcraft\n5 - Technology\n6 - Biotechnology\nChoose one to see the types of king you can select: ";
				cin.clear();
				cin.ignore(10000, '\n');
			}
			if ((kind_selected >= 0) and (kind_selected <= 6))
			{
				vector<King> kingdom_kind = kings.at(kind_selected);
				int size = kingdom_kind.size();
				cout << "Available title options available for this kind of kingdom:\n";
				for (int i = 0; i < size; i++)
				{
					King king_kind = kingdom_kind.at(i);
					cout << "\n Title number " << i << ": ";
					cout << "Name: " << king_kind.name;
					cout << " - Alignment: " << king_kind.alignment;
					cout << " - Troop capacity when fighting: " << king_kind.troop_capacity;
					cout << " - Stats(*lvl): HP: " << king_kind.hp << " DMG: " << king_kind.dmg;
				}
				cout << "\nSelect the title number (anything other than the number to exit to civilization selection)\nYour choice: ";
				if (cin >> inputnumber)
				{
					if ((inputnumber >= 0) and (inputnumber < size))
					{
						king_selected = inputnumber;
						PlayerKingdom.king = king_selected;
						PlayerKingdom.kind = kind_selected;
						PlayerKingdom.defineEmperor();
					}
				}
				else
				{
					cin.clear();
					cin.ignore(10000, '\n');
				}
			}
			else
			{
				cout << "No option selected, choose again.\n";
			}
		}
	}
}

void generateOtherCivilizations()
{
	int count = 0;
	int size1 = 1000; // Quantidade de civilizacoes para criar
	for (int i = 0; i < size1; i++)
	{
		int x = (rand() % 100000) - 50000;
		while (x == 0)
		{
			x = (rand() % 100000) - 50000;
		}
		int y = (rand() % 100000) - 50000;
		allCivilizations.emplace_back(0, 0, x, y);
		allCivilizations.at(i).addEmperorTitle(0);
	}
	for (int i = 1; i < size1; i++)
	{
		botManagement.emplace_back(allCivilizations.at(i));
	}

	int size = allCivilizations.size();
	for (int i = 0; i < size; i++)
	{
		allCivilizations.at(i).setNationsUnknown();
	}
}

void startNPCS()
{
}

void newGame()
{
	startNewPlayer();
	generateOtherCivilizations();
}

void loadGame()
{
}

void worldEvents()
{
	for (int i = 1; i < allCivilizations.size(); i++)
	{
		allCivilizations.at(i).monthlyUpdates();
	}
}

void worldLog()
{
}

// Codigo para funcoes: 0 - Falha; 1 - Funcionamento normal; >100: Informacao nos ultimos dois digitos

int playerExplore()
{
	cout << "Select a direction to send explorers:\n1 - North\n2 - South\n3 - East\n 4 - West\nAny other thing to cancel\nYour choice: ";
	cin >> player_input;
	if ((player_input == "1") and (PlayerKingdom.explored_n >= 5000))
	{
		cout << "\nExplorer sent successfully.";
		return 101;
	}
	else if ((player_input == "2") and (PlayerKingdom.explored_s >= 5000))
	{
		cout << "\nExplorer sent successfully.";
		return 102;
	}
	else if ((player_input == "3") and (PlayerKingdom.explored_e >= 5000))
	{
		cout << "\nExplorer sent successfully.";
		return 103;
	}
	else if ((player_input == "4") and (PlayerKingdom.explored_w >= 5000))
	{
		cout << "\nExplorer sent successfully.";
		return 104;
	}
	else
	{
		if ((player_input != "1") and (player_input != "2") and (player_input != "3") and (player_input != "4"))
		{
			cout << "\nNo option selected.";
		}
		else
		{
			cout << "\nYou have already reached the border of the island in this direction.";
		}
		return 0;
	}
}

void playerTurn()
{
	int alreadyExplored, directionToExplore, buildingsMade;
	worldLog();
	cout << "Kingdom: " << PlayerKingdom.civilization_name << "\n";
	cout << "Actions: \n1 - Explore the world.\n2 - Build a construction.\n3 - Check kingdom status.\n4 - End turn.\nYour choice: ";
	cin >> player_input;
}
