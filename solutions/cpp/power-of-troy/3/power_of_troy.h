#pragma once

#include <string>
#include <memory>

namespace troy {

struct artifact {
    // constructors needed (until C++20)
    artifact(std::string name) : name(name) {}
    std::string name;
};

struct power {
    // constructors needed (until C++20)
    power(std::string effect) : effect(effect) {}
    std::string effect;
};

struct human {
    human() {};
    std::unique_ptr<artifact> possession;

    std::shared_ptr<power> own_power;
    std::shared_ptr<power> influenced_by;

    int used_on = 0;
};


void give_new_artifact(human& human, std::string name);
void exchange_artifacts(std::unique_ptr<artifact>& first, std::unique_ptr<artifact>& second);

void manifest_power(human& human, std::string effect);
void use_power(human& user, human& target);

int power_intensity(human& human);

}  // namespace troy
