#ifndef CALCLOGIC_H
#define CALCLOGIC_H
class calcLogic{
private:
    double result = 0;
    bool f = false;
public:
    calcLogic(){};
    double sum(double first){
        if(!result)
            return result = first;
        else return result = first + result;
    }
    double multi(double  first){
        if(!result)
            return result = first;
        else return result = first * result;
    }
    double sub(double  first){
        if(!result)
            return result = first;
        else return result = result - first;
    }
    double divide(double  first){
        if(!result)
            return result = first;
        else return result = result/first;
    }



};

#endif  //CALCLOGIC_H
