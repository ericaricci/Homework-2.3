#include <iostream>
#include <queue>
//sourced from chatgpt
class Aircraft {
public:
    Aircraft(int id) : id(id) {}

    int getId() const {
        return id;
    }

private:
    int id;
};

class AirTrafficController {
public:
    AirTrafficController() : asleep(true), talking(false), capacity(3) {}

    void processAircraft(const Aircraft& aircraft) {
        if (asleep) {
            std::cout << "ATC is asleep. Aircraft " << aircraft.getId() << " wakes up ATC." << std::endl;
            asleep = false;
            handleAircraft(aircraft);
        }
        else {
            if (talking) {
                std::cout << "ATC is busy. Aircraft " << aircraft.getId() << " is diverted." << std::endl;
            }
            else {
                handleAircraft(aircraft);
            }
        }
    }

    void handleAircraft(const Aircraft& aircraft) {
        if (trafficPattern.size() < capacity) {
            std::cout << "Aircraft " << aircraft.getId() << " enters the traffic pattern." << std::endl;
            trafficPattern.push(aircraft);
        }
        else {
            std::cout << "Traffic pattern is full. Aircraft " << aircraft.getId() << " is diverted." << std::endl;
        }
    }

    void finishCommunication() {
        if (!trafficPattern.empty()) {
            Aircraft aircraft = trafficPattern.front();
            trafficPattern.pop();
            std::cout << "ATC finishes talking to Aircraft " << aircraft.getId() << "." << std::endl;
        }
        if (trafficPattern.empty()) {
            asleep = true;
            std::cout << "ATC falls asleep." << std::endl;
        }
    }

private:
    bool asleep;
    bool talking;
    int capacity;
    std::queue<Aircraft> trafficPattern;
};

int main() {
    AirTrafficController atc;
    for (int i = 1; i <= 10; ++i) {
        Aircraft aircraft(i);
        atc.processAircraft(aircraft);
        if (i % 3 == 0) {
            atc.finishCommunication();
        }
    }
    return 0;
}
