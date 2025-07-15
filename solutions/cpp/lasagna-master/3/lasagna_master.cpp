#include "lasagna_master.h"

using namespace std;

namespace lasagna_master {

// TODO: add your solution here

amount::amount(int amt_noodles, double amt_sauce) {
		noodles = amt_noodles;
		sauce = amt_sauce;
	}

int preparationTime(vector<string> layers, int prep_time_per_min) {
	int num_layers = layers.size();
	return num_layers * prep_time_per_min;
}

int preparationTime(vector<string> layers) {
	int num_layers = layers.size();
	return num_layers * 2;
}

amount quantities(vector<string> layers) {
	int amt_noodles = 0;
	double amt_sauce = 0;
	string layer_type;


	for (int idx = 0; idx < layers.size(); idx++) {
		layer_type = layers.at(idx);
		if (layer_type == "sauce") {
			amt_sauce += 0.2;
		}
		else if (layer_type == "noodles") {
			amt_noodles += 50;
		}
	}
	return amount(amt_noodles, amt_sauce);

}

void addSecretIngredient(vector<string>& my_recipe, const vector<string>& other_recipe) {
	my_recipe.back() = other_recipe.back();
}

void addSecretIngredient(vector<string>& my_recipe, const string aunties_ingredient) {
	my_recipe.back() = aunties_ingredient;
}

vector<double> scaleRecipe(const vector<double> two_portion_amts, int num_portions) {
	double scaling = num_portions / 2.0;
	vector<double> new_recipe;

	int siz = two_portion_amts.size();

	for (int idx = 0; idx < siz; idx++) {
		new_recipe.emplace_back(two_portion_amts.at(idx) * scaling);
	}

	return new_recipe;

}

}  // namespace lasagna_master


