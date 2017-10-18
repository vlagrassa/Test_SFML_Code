/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ball.h
 * Author: student
 *
 * Created on October 13, 2017, 9:01 PM
 */

#ifndef BALL_H
#define BALL_H


#include <SFML/Graphics.hpp>

class Ball {
public:
    void setX(float n);
    void setY(float n);
    void setAngle(float n);
    void setSpeed(float n);
    void setRadius(int n);
    
    void changeX(float n);
    void changeY(float n);
    void changeAngle(float n);
    void changeSpeed(float n);
    void changeRadius(int n);
    
    float getX();
    float getY();
    float getAngle();
    float getSpeed();
    int getRadius();
    
    sf::CircleShape getCircle();
    
    void setPos(float x, float y);
    void hit(float a, float s);
    
    void setColor(sf::Color c);
    void scale(int x, int y);
    void scale(const sf::Vector2f &factor);
    
    Ball(float x, float y, float a, float m, float r);
    Ball(const Ball& orig);
    virtual ~Ball();

private:
    float angle;
    float speed;
    int radius;
    sf::CircleShape circle;
};

#endif /* BALL_H */

