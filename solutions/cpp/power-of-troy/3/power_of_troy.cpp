#include "power_of_troy.h"

using namespace std;

namespace troy {

void give_new_artifact(human& human, std::string name) {
	human.possession = make_unique<artifact>(name);
}

void exchange_artifacts(unique_ptr<artifact>& first, unique_ptr<artifact>& second) {
	first.swap(second);
}

void manifest_power(human& human, string effect) {
	human.own_power = make_shared<power>(effect);
	human.used_on = 1;
}

void use_power(human& user, human& target) {
	target.influenced_by = user.own_power;
	user.used_on += 1;
}

int power_intensity(human& human) {
	return human.own_power.use_count();
}
}  // namespace troy
