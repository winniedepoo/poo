#include <iostream>
#include <stdlib.h>
#include <iomanip>

class Cutie{
    
    private:
    float lungime, latime, inaltime;
    
    public:
    
    Cutie(float lungime, float latime, float inaltime) {
        this -> lungime = lungime;
        this -> latime = latime;
        this -> inaltime = inaltime;
    }
    
    void set_lungime(float lungime){
        this -> lungime = lungime;
    }
    
    float get_lungime(){
        return this -> lungime;
    }
    
    void set_latime(float latime){
        this -> latime = latime;
    }
    
    float get_latime(){
        return this -> latime;
    }
    
    void set_inaltime(float inaltime){
        this -> inaltime = inaltime;
    }
    
    float get_inaltime(){
        return this -> inaltime;
    }
 
    void display() {
     std :: cout << std :: fixed;
     std :: cout << std :: setprecision(3);
     std :: cout << this -> lungime << " "<< this -> latime << " "<< this -> inaltime;
    {
    
};

int main() {
    
    float v_lungime, v_latime, v_inaltime;
    
    std :: cin >> v_lungime;
    std :: cin >> v_latime;
    std :: cin >> v_inaltime;
    
    Cutie c(v_lungime, v_latime, v_inaltime);
    c.display();
    
    return 0;
}
