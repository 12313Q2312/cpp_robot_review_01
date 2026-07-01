#ifndef MOTOR_H
#define MOTOR_H
#include <string>

class Motor
{
private:
    std::string motorName;
    int rpm;
public:
    explicit Motor(std::string name);
    void setRPM(int r);
    int getRPM() const;
    void stop();
    void printStatus() const;
};

#endif
