/* 
 * File:   Ball.cpp
 * Author: Vince LaGrassa
 * Created on October 13, 2017, 9:01 PM
 */

#include "Ball.h"

#include <SFML/Graphics.hpp>

void Ball::setX(float n) {
    circle.setPosition(n, circle.getPosition().y);
}
void Ball::setY(float n) {
    circle.setPosition(circle.getPosition().x, n);
}
void Ball::setAngle(float n) {
    angle = n;
}
void Ball::setSpeed(float n) {
    speed = n;
}
void Ball::setRadius(int n) {
    radius = n;
}

void Ball::changeX(float n) {
    circle.move(n, 0);
}
void Ball::changeY(float n) {
    circle.move(0, n);
}
void Ball::changeAngle(float n) {
    angle += n;
}
void Ball::changeSpeed(float n) {
    speed += n;
}
void Ball::changeRadius(int n) {
    radius += n;
}

float Ball::getX() {
    return circle.getPosition().x;
}
float Ball::getY() {
    return circle.getPosition().y;
}
float Ball::getAngle() {
    return angle;
}
float Ball::getSpeed() {
    return speed;
}
int Ball::getRadius() {
    return radius;
}

sf::CircleShape Ball::getCircle() {
    return circle;
}

Ball::Ball(float x, float y, float a, float m, float r) {
    circle.setPosition(x, y);
    circle.setRadius(r);
    setAngle(a);
    setSpeed(m);
    setRadius(r);
}

Ball::Ball(const Ball& orig) {
}

Ball::~Ball() {
}
