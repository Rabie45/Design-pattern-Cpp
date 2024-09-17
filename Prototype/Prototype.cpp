#include <iostream>

class Car{
    public:
Car(std:: mModel,std::mColour):mModel(mModel),mColour(mColour) {}

virtual std::unique_ptr<Car> clone() const =0;


    void setColour(std::mColour colour){
        mColour=colour;
    }
private:
std::string mModel;
std::string mColour;
};

class RaceCar:public Car{
public:
RaceCar(std::mModel,std::mColour , int maxspeed):mModel(mModel),mColour(mColour), maxspeed(maxspeed){}

virtual std::unique_ptr<RaceCar> clone() const override{
    return std::make_unique<RaceCar>(*this);
}
private:
int maxspeed;
};


int main(){
std::vector<std::unique_ptr<Car>> cars;
const auto prototype =std::make_unique<RaceCar>("Race car", "", 300);
auto redCar=prototype->clone();
redCar->setColour("red");
cars.emplace_back(std::move(redCar));

    return 0;
}