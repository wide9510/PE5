#include <iostream>
#include "Rectangle.h"



Rectangle::Rectangle(Point p1, Point p2){
    this->p1_ = p1;
    this->p2_ = p2;
}

int Rectangle::GetWidth(){
    return this->p2_.x - this->p1_.x;
}

int Rectangle::GetHeight(){
    return this->p2_.y - this->p1_.y;
}

bool Rectangle::Overlaps(Rectangle& other){
    
    if( (other.get_p1().y > this->p2_.y) || (this->p1_.y > other.get_p2().y)){
        return false;
    }
    if( (this->p2_.x < other.get_p1().x) || (other.get_p2().x < this->p1_.x)){
        return false;
    }

    return true;


}

int Rectangle::CalculateArea(){
    int width = this->GetWidth();
    int height = this-> GetHeight();
    return width * height;
}

void Rectangle::Expand(){
    p1_.x--;
    p1_.y--;
    p2_.x++;
    p2_.y++;
}

void Rectangle::Shrink(){
    p1_.x++;
    p1_.y++;
    p2_.x--;
    p2_.y--;
}

// int main() 