#ifndef RTS_CONSTANTS_H
#define RTS_CONSTANTS_H

#include <iostream>
#include <vector>
using namespace std;

extern int init_game;
extern int month;
extern int year;
extern string input;

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
		int gear,steel,paper,chemicals; // Secundarios
		
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
		int lvl;
		int hp = 10;
		
};

class Champions{
	public:
		int kingdom;
		int xp;
		
};

class Troops{
	public:
		string kingdom;
		int dmg, hp;
		
};

class Buildings{
    public:
        int income;
        
};

#endif
