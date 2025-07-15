#pragma once
#include <string>
#include <vector>

namespace lasagna_master {

struct amount {

    amount(int amt_noodles, double amt_sauce);

    int noodles;
    double sauce;
};

// Prep time methods. 
int preparationTime(const std::vector<std::string>& layers, int prep_time_per_min);
int preparationTime(const std::vector<std::string>& layers);

// Quantities method.
amount quantities(const std::vector<std::string>& layers);

void addSecretIngredient(std::vector<std::string>& my_recipe, const std::vector<std::string>& other_recipe);
void addSecretIngredient(std::vector<std::string>& my_recipe, const std::string& aunties_ingredient);

std::vector<double> scaleRecipe(std::vector<double>& two_portion_amts, int num_portions);

}  // namespace lasagna_master
