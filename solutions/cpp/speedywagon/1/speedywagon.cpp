#include "speedywagon.h"

using namespace std;

namespace speedywagon {

// Enter your code below:

// Please don't change the interface of the uv_light_heuristic function
int uv_light_heuristic(std::vector<int>* data_array) {
    double avg{};
    for (auto element : *data_array) {
        avg += element;
    }
    avg /= data_array->size();
    int uv_index{};
    for (auto element : *data_array) {
        if (element > avg) ++uv_index;
    }
    return uv_index;
}

bool connection_check(pillar_men_sensor* sensor_read) {
    return (sensor_read != nullptr);
}

int activity_counter(pillar_men_sensor* first_read, int capacity) {
    int total_activity = 0, idx = 0;
    while (idx < capacity) {
        total_activity += (first_read + idx)->activity;
        idx++;
    }
    return total_activity;
}

bool alarm_control(pillar_men_sensor* sensing_data) {
    return (connection_check(sensing_data) && sensing_data->activity > 0);
}

bool uv_alarm(pillar_men_sensor* sensing_data) {
    if (!connection_check(sensing_data)) {
        return false;
    }

    vector<int>* data = &sensing_data->data;
    return (uv_light_heuristic(data) > sensing_data->activity);
}

}  // namespace speedywagon
