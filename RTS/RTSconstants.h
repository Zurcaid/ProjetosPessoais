#ifndef RTS_CONSTANTS_H
#define RTS_CONSTANTS_H

#include <iostream>
#include <vector>
using namespace std;


class Civilization{
	public:
		// Caracteristicas gerais
		int alignment = 0; // Varia de 0 a 100
		int xp = 0; // 1 lvl = 100 xp
		int tech_lvl = 0;
		int kind, king;
		string name;

// Recursos
		int money = 0;
		int ores,wood,stone,raw_food; // Primarios
		int gear,steel,paper,chemicals,food; // Secundarios

		// Construcoes
		vector<int> buildings;
		int city_dur = 100;

		// Populacao
		int population = 10;
		int doctor,teacher,farmworker,shopkeeper,worker,extractivist,guard,criminal; // Empregos
		int aproval = 50; // Varia de 0 a 100
		float growing_rate = 0.0;

		// Relacoes diplomaticas
		vector<string> nations_known;
		vector<int> nk_relationship;
		vector<int> pacts;
		int trade_balance;

		int moral = 80;

		vector<vector<int>> armys;      // Exercitos
		vector<vector<int>> army_qnt;   // Quantidade de tropas em cada exercito

		vector<string> troops;  // Tropas no pais
		vector<int> troopsNum;  // Quantidade de cada tropa

		vector<string> champions;

		Civilization(int a, int b, int c);

		void changeAlignment(int x);
		void changeXp(int x);
		void changeMoral(int x);
		void setTroops(string x, int n);
		void setKind(int x);
		void setKing(int x);

};

class King{
	public:
		int name;
		int lvl;
		int hp = 10;
		int dmg = 10;

};

class Champions{
	public:
		string name;
		string kingdom;
		int capacity;
		int loyalty;
		int xp;

};


class Troops{
	public:
		string name;
		string kingdom;
		int dmg, hp;

};


class Buildings{
    public:
    	int kind;
    	int sector;
    	string kingdom;
    	int cost;
    	float durability = 1;
		int money;
		int ores,wood,stone,raw_food; // Primarios
		int products,gear,steel,paper,chemicals,food; // Secundarios
		int tech_req;
		float tech_gen;
		int population;
		int doctor,teacher,farmworker,shopkeeper,worker,extractivist,guard,criminal; // Empregos
		int aproval; // Varia de 0 a 100
		int education;
		int growing_rate;
		
		int troops, troops_num;
		// t1=tech_req,ap=aproval,pop=population,a=kind,b=sector,c=kingdom,d=cost,e=money,f=ores/teacher,g=wood/doctor,h=stone/guard,i=raw_food/criminal,j=products,k=gear,l=steel,m=paper,n=chemicals,o=food,p=worker,q=farmworker,r=extractivist,s=shopkeeper,t=troops,u=troopsnum,t2=tech_gen;
		// Setor 1: Estruturas relacionadas ao consumo ou producao de material.
		// Setor 2: Outras estruturas (hospitais, escolas, etc).
		Buildings(int t1,int ap,int pop,int a,int b,string c,int d,int e,int f,int g,int h,int i,int j,int k,int l,int m,int n,int o,int p,int q,int r,int s,int t,int u,int t2);

		void buildConstruction();
		void monthlyUpdate();
};	

#endif
