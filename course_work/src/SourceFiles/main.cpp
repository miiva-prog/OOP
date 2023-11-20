#include <iostream>
#include <cstdio>
#include <cstring>
#include <unistd.h>
#include <stdlib.h>
#include <fstream>
#include <ctime>

#include "Wolf.h"
#include "Rabbit.h"
#include "Model.h"

using namespace std;

int main()
{
    srand(time(NULL));

    int n = 10;
    int m = 10;
    int countWolfes,countRabbits,x,y;

    Model model(n,m);

    cout << "Count rabbits -> ";
    cin >> countRabbits;

    for(int i = 0;i < countRabbits;i++){
        x = rand() % n;
        y = rand() % m;

        Rabbit *rabbit = new Rabbit(x,y);

        model.set_rabbit(rabbit);
    }

    while(true){
        std::cout << "\x1B[2J\x1B[H";

        model.printModel();

        cout << "wolves -> " << model.get_countWolves() << endl;
        cout << "rabbits -> " << model.get_countRabbits() << endl;
        cout << "carrots -> " << model.get_countCarrots() << endl;

        model.newStep();
        sleep(3);
    }

    return 0;
}