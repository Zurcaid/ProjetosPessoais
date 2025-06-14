#ifndef RTS_CONSTANTS_H
#define RTS_CONSTANTS_H

#include <iostream>
#include <vector>
using namespace std;

class Buildings;
class Troops;
class Champions;

class Civilization
{
  public:
	// Caracteristicas gerais
	int alignment; // Varia de 0 a 100
	int xp = 0;	   // 1 lvl = 100 xp
	int lvl;
	int tech_lvl = 0;
	int kind, king;
	string name;
	int location;

	// Recursos
	int money = 0;
	int ores, wood, stone, raw_food;		 // Primarios
	int gear, steel, paper, chemicals, food; // Secundarios

	// Construcoes
	vector<Buildings> buildings;
	int city_dur = 100;

	// Populacao
	int population = 10;
	int doctor, teacher, farmworker, shopkeeper, worker, extractivist, guard, criminal; // Empregos
	int aproval = 50;																	// Varia de 0 a 100
	float growing_rate = 0.0;
	float education = 1.0;

	// Relacoes diplomaticas
	vector<string> nations_known;
	vector<int> nk_relationship;
	vector<int> pacts;
	int trade_balance;

	int moral = 80;

	vector<vector<int>> armys;	  // Exercitos
	vector<vector<int>> army_qnt; // Quantidade de tropas em cada exercito

	vector<int> troops;		// Tropas no pais
	vector<int> troops_num; // Quantidade de cada tropa

	vector<string> champions;

	Civilization(int a, int b, int c, int d);

	void changeAlignment(int x);
	void changeXp(int x);
	void changeMoral(int x);
	void setTroops(int x, int n);
	void setKind(int x);
	void setKing(int x);
	void buildingsMonthlyUpdates();
};

class King
{
  public:
	string name;
	int xp;
	int lvl;
	int hp = 10;
	int dmg = 10;
};

class Champions
{
  public:
	string name;
	int kingdom;
	int capacity;
	int loyalty;
	int xp;
	int lvl;
	int dmg, hp;

	int archery_boost, melee_boost, defender_boost, beast_boost;
	int dmg_boost, hp_boost, foodcost_boost, moral_boost;
	// a=kingdom,b=capacity,c=loyalty,d=xp,e=dmg,f=hp,g=archery_boost,h=melee_boost,i=defender_boost,j=beast_boost,k=dmg_boost,l=hp_boost,m=foodcost_boost,n=moral_boost, o=name;
	Champions(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, string o);
	void changeXp(int x);
	void monthlyUpdate();
};

class Troops
{
  public:
	string name;
	int kingdom;
	int dmg, hp;
	int kind;
	int food_cost_per_month;
	int ranged;
	// a=kingdom,b=kind,c=ranged,d=food_cost_per_month,e=dmg,f=hp,g=name
	Troops(int a, int b, int c, int d, int e, int f, string g);
};

class Army
{
  public:
	int champion_hp, champion_dmg, champion_row;
	int row1_hp, row1_dmg, row1_ranged;
	int row2_hp, row2_dmg, row2_ranged;
	int row3_hp, row3_dmg, row3_ranged;
	int front_row = 1;
};

class Buildings
{
  public:
	string name;
	int kind;
	int position;
	int sector;
	int kingdom;
	int cost;
	int wood_cost;
	int stone_cost;
	int steel_cost;
	float durability = 1;
	int money;
	int ores, wood, stone, raw_food;				   // Primarios
	int products, gear, steel, paper, chemicals, food; // Secundarios
	int tech_req;
	float tech_gen;
	int population;
	int doctor, teacher, farmworker, shopkeeper, worker, extractivist, guard, criminal; // Empregos
	float aproval;																		// Varia de 0 a 100
	int education;
	int growing_rate;

	int troops, troops_num;
	// t1=tech_req,ap=aproval,pop=population,a=kind,b=sector,c=kingdom,d=cost,e=money,f=ores/teacher,g=wood/doctor,h=stone/guard,i=raw_food/criminal,j=products/education,k=gear,l=steel,m=paper,n=chemicals,o=food,p=worker,q=farmworker,r=extractivist,s=shopkeeper,t=troops,u=troopsnum,t2=tech_gen;
	// Setor 1: Estruturas relacionadas ao consumo ou producao de material.
	// Setor 2: Outras estruturas (hospitais, escolas, etc).
	Buildings(int t1, float ap, int pop, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p, int q, int r, int s, int t, int u, int t2, int wc, int stone_c, int steel_c, string nm);

	void buildConstruction(Civilization &Obj);
	void monthlyUpdate(Civilization &Obj);
};







// t1=tech_req,ap=aproval,pop=population,a=kind,b=sector,c=kingdom,d=cost,e=money,f=ores/teacher,g=wood/doctor,h=stone/guard,i=raw_food/criminal,j=products,k=gear,l=steel,m=paper,n=chemicals,o=food,p=worker,q=farmworker,r=extractivist,s=shopkeeper,t=troops,u=troopsnum,t2=tech_gen,wc=wood_cost,stone_c=stone_cost,steel_c=steel_cost;
Buildings FruitFarm1(0, 1.0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 3, 2, 0, "Small fruit farm"), AnimalFarm1(0, 1.0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 3, 2, 0, "Small animal farm");

#endif