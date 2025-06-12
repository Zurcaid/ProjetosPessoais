#include <iostream>
#include <vector>
using namespace std;

int init_game;
int age;
int input;

class Civilization{
	public:
		// Caracteristicas gerais
		int alignment = 0; // Varia de 0 a 100
		int xp = 0; // 1 lvl = 100 xp
	    int tech_lvl = 0;
		int kind, king;
		
		// Recursos
		int money = 0;
		int ores,wood,stone,raw_food; // Primarios
		int gear,steel,paper,chemicals; // Secundarios
		
		// Construcoes
		vector<int> construcoes;
		
		// Populacao
		int population = 10;
		int doctor,teacher,farmworker,shopkeeper,worker,extractivist,guard,criminal; // Empregos
		int happyness = 50; // Varia de 0 a 100
		float growing_rate = 0.0;
		
		// Relacoes diplomaticas
		string nations_known[];
		string nk_relationship[];
		int pacts[];
		int trade_balance;
		
		vector<vector<int>> armys;      // Exercitos
		vector<vector<int>> army_qnt;   // Quantidade de tropas em cada exercito
		
		vector<string> troops;  // Tropas no pais
		vector<int> troopsNum;  // Quantidade de cada tropa
		
		void changeAlignment(int x){
			alignment += x;
		}
		void changeXp(int x){
			xp += x;
		}
		
		void setTroops(string x, int n){
			int size = troops.size();
			int pos = size+1;
			for(int i = 0; i <= size; i++){
				if(troops.at(i) == x){
					pos = i;
					break;
				}
			}
			if(pos <= size){
				troopsNum.at(pos) = troopsNum.at(pos) + n;
			}else{
				troops.push_back(x);
				troopsNum.push_back(n);
			}
		}
		void setKind(int x){
			kind = x;
		}
		void setKing(int x){
			king = x;
		}
};

Civilization Kingdom1;

class King{
	public:
		int lvl;
		int hp = 10;
		
		void passive1(int a, int b, int c, int d, int e, int f){
			int armyDmg_boost = a;
			int armyHp_boost = b;
			int moneyGen_boost = c;
		}
		void skill1(){
			
		}
};

class Champions{
	public:
		int kingdom;
		int xp;
		
};

class Troops{
	public:
		int name;
		int kingdom;
		int dmg,hp;
		
};
