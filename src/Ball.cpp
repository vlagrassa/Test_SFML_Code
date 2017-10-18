/* 
 * File:   Ball.cpp
 * Author: Vince LaGrassa
 * Created on October 13, 2017, 9:01 PM
 */

#include "Ball.h"

#include <SFML/Graphics.hpp>

void Ball::setX(float n) {
    //circle.setOrigin(n, circle.)
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
    circle.setRadius(n-3);
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

void Ball::setPos(float x, float y) {
    circle.setPosition(x, y);
}

void Ball::scale(int x, int y) {
    circle.scale(x, y);
}

void Ball::setColor(sf::Color c) {
    circle.setFillColor(c);
}

Ball::Ball(float x, float y, float a, float m, float r) {
    circle.setOrigin(r, r);
    circle.setPosition(x, y);
    circle.setRadius(r-3);
    circle.setOutlineThickness(3);
    circle.setOutlineColor(sf::Color::Black);
    setAngle(a);
    setSpeed(m);
    setRadius(r);
}

Ball::Ball(const Ball& orig) {
}

Ball::~Ball() {
}
