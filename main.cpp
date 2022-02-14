#include <iostream>
#include<bits/stdc++.h>
#include<stdio.h>
class Automobil{
   public:
        Automobil(std::string tip, std::string nume,int capacitate,
                  float viteza_medie):tip(tip),nume(nume),capacitate(capacitate),
                  viteza_medie(viteza_medie){}

        int Getcapacitate() { return capacitate; }
        void Setcapacitate(int val) { capacitate = val; }
        float Getviteza_medie() { return viteza_medie; }
        void Setviteza_medie(float val) { viteza_medie = val; }
        std::string Gettip() { return tip; }
        void Settip(std::string val) { tip = val; }
        std::string Getnume() { return nume; }
        void Setnume(std::string val) { nume = val; }
        void afisare()
        {
            std::cout<<this->nume<<std::endl;
            std::cout<<this->capacitate<<std::endl;
            std::cout<<this->viteza_medie<<std::endl;
        }
    private:
        int capacitate;
        float viteza_medie;
        std::string tip;
        std::string nume;
}**p_automobil;
class Masina:public Automobil
{

};
class Autoturism:public Automobil
{

};
float round(float var)
{
    float value = (int)(var * 100 + .5);
    return (float)value / 100;
}
int main()
{
    int comanda,nr_automobile,i;
    std::string tip;
    std::string model;
    int capacitate;
    float viteza;
    std::cin>>comanda>>nr_automobile;
    //citire date
    p_automobil = new Automobil*;
    for(i=0;i<nr_automobile;i++)
    {
        std::cin.get();
        std::getline(std::cin,tip);
        //std::cin.get();
        std::getline(std::cin,model);
        std::cin>>capacitate>>viteza;
        p_automobil[i] = new Automobil(tip,model,capacitate,viteza);

    }
    switch (comanda)
    {
    case 1:
        {
            for(i=0;i<nr_automobile;i++)
                p_automobil[i]->afisare();
        }
    case 2:
        {
            int nr_persoane;
            std::cin>>nr_persoane;
            int nr_necesar_de_masini;
            for(i=0;i<nr_automobile;i++)
            {
                nr_necesar_de_masini = nr_persoane/p_automobil[i]->Getcapacitate();
                if(nr_necesar_de_masini*p_automobil[i]->Getcapacitate()!=nr_persoane)
                    nr_necesar_de_masini++;
                std::cout<<p_automobil[i]->Getnume()<<std::endl;
                std::cout<<nr_necesar_de_masini<<std::endl;
            }
        }
    case 3:
        {
            float distanta,durata;
            std::cin>>distanta>>durata;
            for(i=0;i<nr_automobile;i++)
            {
                durata = distanta/p_automobil[i]->Getviteza_medie();
                std::cout<<p_automobil[i]->Getnume()<<std::endl;
                //std::cout<<round(durata)<<std::endl;
                printf("%.2f\n",durata);
            }
        }
    case 4:
        {

        }
    }
    return 0;
}
