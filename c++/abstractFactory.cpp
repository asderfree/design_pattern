//
// Created by 33028 on 2021/6/12.
//

#include <iostream>
#include <string>

using namespace std;

class IUser {
public:
    virtual void insert() = 0;

    virtual void getUser() = 0;

    virtual ~IUser() = default;
};

class SqlserverUser : public IUser {
public:
    void insert() override {
        cout << "Insert user data into sqlserver!\n";
    }

    void getUser() override {
        cout << "Get User information from sqlserver\n";
    }

    ~SqlserverUser() override = default;
};

class MysqlUser : public IUser {
public:
    void insert() override {
        cout << "Insert user data into mysql\n" ;
    }

    void getUser() override {
        cout << "Get user information from mysql\n";
    }

    ~MysqlUser() override = default;
};

class IDepartment{
public:
    virtual void insert() = 0;
    virtual void getDepartment() =0 ;
    virtual ~IDepartment() = default;
};

class SqlDepartment : public IDepartment{
public:
    void insert() override{
        cout << "Insert department information into Sqlserver\n";
    }

    void getDepartment() override {
        cout << "Get department information from sqlserver\n";
    }

    ~SqlDepartment() override = default;
};

class MysqlDepartment : public IDepartment{
public:
    void insert() override {
        cout << "Insert department information into MysqlServer\n";
    }

    void getDepartment() override {
        cout << "Get department information from mysqlServer\n";
    }

    ~MysqlDepartment() override = default;
};

// 抽象工厂
class Factory{
public:
    void factoryPrint(){
        cout << "factory" << endl;
    }

    virtual IUser* createUser() = 0;
    virtual IDepartment* createDepartment() =0;
    virtual ~Factory() = default;
};

class SqlserverFactory : public Factory{
public:
    IUser *createUser() override {
        return new SqlserverUser();
    }

    IDepartment *createDepartment() override {
        return new SqlDepartment();
    }

    ~SqlserverFactory() override = default;
};

class MysqlServerFactory : public Factory{
public:
    IUser *createUser() override {
        return new MysqlUser();
    }

    IDepartment *createDepartment() override {
        return new MysqlDepartment();
    }

    ~MysqlServerFactory() override = default;
};

int main(){
    Factory* factory = new SqlserverFactory();
    IUser* iu = factory->createUser();
    iu->insert();
    iu->getUser();

    IDepartment* id = factory->createDepartment();
    id->insert();
    id->getDepartment();

    delete iu;
    delete factory;
    delete id;
}



