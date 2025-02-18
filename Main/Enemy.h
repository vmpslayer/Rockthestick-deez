#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
#include <fstream>
#include <time.h>
#include <ctime>
#include <chrono>
#include <stdlib.h>
#include <random>
#include <thread>

#include "Character.h"

class Enemy : public Character {
public:
    Enemy() : Character() {}

    int punch() { return 20; }

    int kick() {
        if (rand() % 100 < 20) { // 20% chance of miss
            return 0;
        }
        else {
            return 40;
        }
    }

    int special_attack() {
        if (rand() % 100 < 40) { // 40% chance of hit
            return 80;
        }
        else {
            return 0;
        }
    }

    void randmove() {
        int randomTime = rand() % 3;
        if (randomTime == 0) {
            std::chrono::seconds waitTime(5);
            std::this_thread::sleep_for(waitTime);
        }
        else if (randomTime == 1) {
            std::chrono::seconds waitTime(3);
            std::this_thread::sleep_for(waitTime);
        }
        else {
            std::chrono::seconds waitTime(1);
            std::this_thread::sleep_for(waitTime);
        }
    }

    bool isDead() {
        if (hp <= 0) {
            std::cout << "You Win!" << std::endl;
            return true;
        }
        else return false;
    }
};

#endif
