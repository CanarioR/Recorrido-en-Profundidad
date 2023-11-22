#ifndef NEURONA_H
#define NEURONA_H
#include <iostream>
#include <string>

class Neurona{
private:
    int id, posicion_x, posicion_y, red, blue, green;
    float voltaje;
public:
    Neurona(int i, int x, int y, int r, int g, int b, float v) : id(0), posicion_x(0), posicion_y(0),red(0), blue(0), green(0),voltaje(0){};

    void setID(const int& i){id = i;}
    void setPX(const int& x){ posicion_x = x;}
    void setPY(const int& y){posicion_y = y;}
    void setRed(const int& r){red = r;}
    void setBlue(const int& b){blue = b;}
    void setGreen(const int& g){green = g;}
    void setVolt(const float v){voltaje = v;}

    int getID()const{return id;}
    int getPX()const{return posicion_x;}
    int getPY()const{return posicion_y;}
    int getRed()const{return red;}
    int getBlue()const{return blue;}
    int getGreen()const{return green;}
    float getaVolt()const{return voltaje;}


    std::string print(){
        std::string res;
        res += "\nID: " + std::to_string(id) + "\nPosicion x:" + std::to_string(posicion_x) + "\nPosicion y: " + std::to_string(posicion_y) + "\nRed: "+ std::to_string(red) + "\nGreen: "+ std::to_string(green) +  "\nBlue: "+ std::to_string(blue) + "\nVoltaje: "+ std::to_string(voltaje);
        return res;
    }

    friend std::ostream& operator<<(std::ostream& os, const Neurona& n) {
        os << n.id, os <<n.posicion_x, os <<n.posicion_y, os <<n.red, os<<n.blue, os << n.green, os << n.voltaje;
        return os;
    }
};

#endif //NEURONA_H
