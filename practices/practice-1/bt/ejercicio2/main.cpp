#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("omit-frame-pointer")
#pragma GCC optimize("unroll-loops")
#pragma comment(linker, "/stack:200000000")


#include <algorithm>
#include <vector>
#include <assert.h>
#include <string>
#include <iostream>
#include <bitset>

using namespace std;

constexpr int INV_SIZE = 10;
constexpr int NB_TIERS = 4;

namespace Ingredients {

	typedef int Ingredients;
	Ingredients NEGATIVE_MASK = 0b00100000010000010000010000010000;
	Ingredients OVERFLOW_MASK = 0b10111111011111011111011111011111;

	string toString(Ingredients ingredients) {
		//xxTTTTTTx33333x22222x11111x00000
		int8_t t0 = (ingredients >> (6 * 0)) & 0x1F; t0 <<= 3; t0 >>= 3;
		int8_t t1 = (ingredients >> (6 * 1)) & 0x1F; t1 <<= 3; t1 >>= 3;
		int8_t t2 = (ingredients >> (6 * 2)) & 0x1F; t2 <<= 3; t2 >>= 3;
		int8_t t3 = (ingredients >> (6 * 3)) & 0x1F; t3 <<= 3; t3 >>= 3;
		int8_t total = (ingredients >> (6 * 4)) & 0x3F; total <<= 3; total >>= 3;
		return "{ total : " + to_string(total) + "," +
			" tiers : [" + to_string(t0) + "," + to_string(t1) + "," + to_string(t2) + "," + to_string(t3) + "] }"; 
			//" tiers : " + std::bitset<32>(ingredients).to_string() + " }";
	}

	Ingredients makeIngredients(int t0, int t1, int t2, int t3) {
		//xxTTTTTTx33333x22222x11111x00000
		int8_t total = t0 + t1 + t2 + t3;
		Ingredients::Ingredients ingredients = 0;
		ingredients |= ((0x1F & t0) << (6 * 0));
		ingredients |= ((0x1F & t1) << (6 * 1));
		ingredients |= ((0x1F & t2) << (6 * 2));
		ingredients |= ((0x1F & t3) << (6 * 3));
		ingredients |= ((0x3F & total) << (6 * 4));
		return ingredients;
	}

	int getTier(Ingredients ingredients, int i) {
		int8_t ti = (ingredients >> (6 * i)) & 0x1F; ti <<= 3; ti >>= 3;
		return ti;
	}

	int getTotal(Ingredients ingredients) {
		int8_t total = (ingredients >> (6 * 4)) & 0x3F; total <<= 3; total >>= 3;
		return total;
	}
	/*
	int distanceTo(Ingredients inventory, Ingredients recipe) {
		//xxTTTTTTx33333x22222x11111x00000


	}
	*/
	
	Ingredients consume(Ingredients ing1, Ingredients ing2){
		Ingredients result = ing1 + ing2;
		result &= OVERFLOW_MASK;
		return result;
	}
	
	bool canConsume(Ingredients inventory, Ingredients spell) {
		Ingredients result = inventory + spell;
		return (result & NEGATIVE_MASK) == 0 && getTotal(result) <= INV_SIZE;
	}

}




Ingredients::Ingredients spells[][4] = {
	{2, 0, 0,  0},
	{-1, 1, 0, 0},
	{0, -1, 1, 0},
	{0, 0, -1, 1},
	{-3, 0, 0, 1},
	{3, -1, 0, 0},
	{1, 1, 0,  0},
	{0, 0, 1,  0},
	{3, 0, 0,  0},
	{2, 3, -2, 0},
	{2, 1, -2, 1},
	{3, 0, 1, -1},
	{3, -2, 1, 0},
	{2, -3, 2, 0},
	{2, 2, 0, -1},
	{-4, 0, 2, 0},
	{2, 1, 0,  0},
	{4, 0, 0,  0},
	{0, 0, 0,  1},
	{0, 2, 0,  0},
	{1, 0, 1,  0},
	{-2, 0, 1, 0},
	{-1, -1, 0,1},
	{0, 2, -1, 0},
	{2, -2, 0, 1},
	{-3, 1, 1, 0},
	{0, 2, -2, 1},
	{1, -3, 1, 1},
	{0, 3, 0, -1},
	{0, -3, 0, 2},
	{1, 1, 1, -1},
	{1, 2, -1, 0},
	{4, 1, -1, 0},
	{-5, 0, 0, 2},
	{-4, 0, 1, 1},
	{0, 3, 2, -2},
	{1, 1, 3, -2},
	{-5, 0, 3, 0},
	{-2, 0, -1,2},
	{0, 0, -3, 3},
	{0, -3, 3, 0},
	{-3, 3, 0, 0},
	{-2, 2, 0, 0},
	{0, 0, -2, 2},
	{0, -2, 2, 0},
	{0, 0, 2, -1}
};

Ingredients::Ingredients recipes[][4] = {
	{-2, -2, -0, -0},
	{-3, -2, -0, -0},
	{-0, -4, -0, -0},
	{-2, -0, -2, -0},
	{-2, -3, -0, -0},
	{-3, -0, -2, -0},
	{-0, -2, -2, -0},
	{-0, -5, -0, -0},
	{-2, -0, -0, -2},
	{-2, -0, -3, -0},
	{-3, -0, -0, -2},
	{-0, -0, -4, -0},
	{-0, -2, -0, -2},
	{-0, -3, -2, -0},
	{-0, -2, -3, -0},
	{-0, -0, -2, -2},
	{-0, -3, -0, -2},
	{-2, -0, -0, -3},
	{-0, -0, -5, -0},
	{-0, -0, -0, -4},
	{-0, -2, -0, -3},
	{-0, -0, -3, -2},
	{-0, -0, -2, -3},
	{-0, -0, -0, -5},
	{-2, -1, -0, -1},
	{-0, -2, -1, -1},
	{-1, -0, -2, -1},
	{-2, -2, -2, -0},
	{-2, -2, -0, -2},
	{-2, -0, -2, -2},
	{-0, -2, -2, -2},
	{-1, -1, -1, -1},
	{-3, -1, -1, -1},
	{-1, -3, -1, -1},
	{-1, -1, -3, -1},
	{-1, -1, -1, -3}
};



namespace Taxes {
	typedef uint32_t Taxes;

	constexpr uint32_t TAX_MASK = 0b000010000100001000010000100001;

	inline Taxes makeTaxes(uint8_t taxes[6]) {
		return
			taxes[0] << 5*0 +
			taxes[1] << 5*1 +
			taxes[2] << 5*2 +
			taxes[3] << 5*3 +
			taxes[4] << 5*4 +
			taxes[5] << 5*5;
	}

	inline Taxes makeTaxes(uint8_t tax0, uint8_t tax1, uint8_t tax2, uint8_t tax3, uint8_t tax4, uint8_t tax5) {
		return
			(tax0 << 5 * 0) |
			(tax1 << 5 * 1) |
			(tax2 << 5 * 2) |
			(tax3 << 5 * 3) |
			(tax4 << 5 * 4) |
			(tax5 << 5 * 5) ;
	}
	
	inline Taxes addTax(Taxes taxes, uint8_t i) {
		return taxes + (TAX_MASK >> ((6 - i) * 5));
	}

	inline uint8_t getTax(Taxes taxes, uint8_t i) {
		return (taxes >> (i * 5)) & 0b11111;
	}

	inline string toString(Taxes taxes) {
		return
			"["
			+ to_string(getTax(taxes, 0)) + ", "
			+ to_string(getTax(taxes, 1)) + ", "
			+ to_string(getTax(taxes, 2)) + ", "
			+ to_string(getTax(taxes, 3)) + ", "
			+ to_string(getTax(taxes, 4)) + ", "
			+ to_string(getTax(taxes, 5)) +
			"]";
	}
}

namespace Recipes {
	typedef int8_t Recipes;

	inline Recipes makeRecipes() {
		return 0b0011111;
	}

	inline bool hasRecipe(Recipes recipes,int i) {
		return (recipes >> i) & 1;
	}

	inline Recipes useRecipe(Recipes recipes, int i) {
		return (~(1 << i)) & recipes;
	}

	inline string toString(Recipes recipes) {
		return "{ [" +
			to_string(hasRecipe(recipes, 0)) + ", " +
			to_string(hasRecipe(recipes, 1)) + ", " +
			to_string(hasRecipe(recipes, 2)) + ", " +
			to_string(hasRecipe(recipes, 3)) + ", " +
			to_string(hasRecipe(recipes, 4)) + "] }";
	}
}
#pragma pack(push,1)

struct GameState {
	Ingredients::Ingredients inventory;
	bitset<32> exhausted;
	bitset<32> notLearned;
	Taxes::Taxes taxes;
	uint8_t rupees : 6;
	uint8_t brews : 2;
	struct {
		uint8_t type : 2;
		uint8_t index : 5;
		uint8_t amount : 4;
	} action;
	Recipes::Recipes recipes;
	float score;

};
#pragma pack(pop)

int main(int argc, char **argv) {
	Taxes::Taxes taxes = Taxes::makeTaxes(3,1,0,0,0,0);
	cout<<Taxes::toString(taxes)<<endl;
	cout<<taxes<<endl;
	cout<<sizeof(GameState)<<endl;
	for(int a=0;a<=10;a++){
		for(int b=0;b<=10;b++){
			for(int c=0;c<=10;c++){
				for(int d=0;d<=10;d++){
					int total=a+b+c+d;
					if(total<=10){
						Ingredients::Ingredients inv = Ingredients::makeIngredients(a,b,c,d);
						int invArr[4]={a,b,c,d};
						for(auto spell : spells){
							Ingredients::Ingredients spellIng = Ingredients::makeIngredients(spell[0],spell[1],spell[2],spell[3]);
							int total2=spell[0]+spell[1]+spell[2]+spell[3];
							
							auto sum = inv;
							bool flag=true;
							for(int i=0;i<4;i++)
								flag&=(0<=spell[i]+invArr[i]&&spell[i]+invArr[i]<=10);
							flag&=(0<=total+total2&&total+total2<=10);
							
							int inv2Arr[4]={a,b,c,d};
							int total3 = total;
							int its=0;
							while(flag){
								its++;
								//cerr<<Ingredients::toString(sum)<<" + "<<Ingredients::toString(spellIng)<<" = "<<Ingredients::toString(Ingredients::consume(sum,spellIng))<<endl;
								sum = Ingredients::consume(sum,spellIng);
								total3+=total2;
								for(int i=0;i<4;i++)
									inv2Arr[i]+=spell[i];
									
								for(int i=0;i<4;i++)
									assert(Ingredients::getTier(sum,i)==(inv2Arr[i]));
								assert(Ingredients::getTotal(sum)==total3);
								
								flag=true;
								for(int i=0;i<4;i++)
									flag&=(0<=inv2Arr[i]+spell[i]&&inv2Arr[i]+spell[i]<=10);
								flag&=(0<=total3+total2&&total3+total2<=10);
								
								assert(flag==Ingredients::canConsume(sum,spellIng));
							}
							assert(its<11);
							//cerr<<Ingredients::toString(sum)<<" + "<<Ingredients::toString(spellIng)<<" /= "<<Ingredients::toString(sum)<<endl;
							assert(flag==Ingredients::canConsume(sum,spellIng));
						}
						
						for(auto recipe : recipes){
							Ingredients::Ingredients recipeIng = Ingredients::makeIngredients(recipe[0],recipe[1],recipe[2],recipe[3]);
							int total2=recipe[0]+recipe[1]+recipe[2]+recipe[3];
							auto sum = inv + recipeIng;
							//cerr<<Ingredients::toString(inv)<<" + "<<Ingredients::toString(recipeIng)<<" = "<<Ingredients::toString(sum)<<endl;
							for(int i=0;i<4;i++)
								assert(Ingredients::getTier(sum,i)==(invArr[i]+recipe[i]));
							assert(Ingredients::getTotal(sum)==(total+total2));
							
							bool flag=true;
							for(int i=0;i<4;i++)
								flag&=(0<=recipe[i]+invArr[i]&&recipe[i]+invArr[i]<=10);
							flag&=(0<=total+total2&&total+total2<=10);
							
							assert(flag==Ingredients::canConsume(inv,recipeIng));
						}
					}
				}
			}
		}
	}
}



