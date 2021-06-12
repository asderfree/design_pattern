/**
 * Created by vastgrass on 2021/6/12.
 * File name: Factory.cpp
 * File Token: 
 * Abstract: This File will take the cloth as example to explain the factory design pattern
 * Current version: 1.0
 * Forward version: NONE
 */
#include <string>
#include <iostream>
using namespace std;

class Cloth{
public:
    virtual ~Cloth() = default;
    virtual void onDressed() = 0;
    virtual std::string operation() = 0;
    virtual void wash() = 0;
};

class T_shirt : public Cloth{
public:
    ~T_shirt() override = default;

    void onDressed() override {
        cout << "The T-shirt was on dressed\n";
    }

    std::string operation() override {
        cout << "The T-shirt was modified to what it should be\n";
        return "T-shirt modified!";
    }

    void wash() override {
        cout << "Wash the T-shirt!";
    }
};

class Pants :public Cloth{
public:
    ~Pants() override = default;

    void onDressed() override {
        cout << "The pants was on dressed!\n";
    }

    string operation() override {
        cout << "The pants was too long, we should cut it shorter!\n";
        return "Cut the pants shorter!";
    }

    void wash() override {
        cout << "The pants need be washed by hands!\n";
    }
};

// 工厂类
class Factory{
public:
    virtual ~Factory() = default;
    virtual Cloth* getCloth() = 0;
};

class T_shirtFactory : public Factory{
public:
    ~T_shirtFactory() override = default;

    Cloth *getCloth() override {
        return new T_shirt();
    }
};

class PantsFactory : public Factory{
public:
    ~PantsFactory() override = default;

    Cloth *getCloth() override {
        return new Pants();
    }
};

void TheOneDayOfTheCloth(Cloth *cloth){
    cloth->onDressed();
    cout << cloth->operation() << endl;
    cloth->wash();
}

int main() {
    Factory* factory = new T_shirtFactory();
    Cloth* cloth = factory->getCloth();
    TheOneDayOfTheCloth(cloth);

    factory = new PantsFactory();
    Cloth* pant = factory->getCloth();
    TheOneDayOfTheCloth(pant);
}












