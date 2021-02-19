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

// bool operator==(const Point &other) {
// 		return x == other.x && y == other.y;
// }

// bool doOverlap(Point l1, Point r1, Point l2, Point r2) 
// { 
//     // If one rectangle is on left side of other 
//     if (l1.x >= r2.x || l2.x >= r1.x) 
//         return false; 
  
//     // If one rectangle is above other 
//     if (l1.y <= r2.y || l2.y <= r1.y) 
//         return false; 
  
//     return true; 
// }

bool Rectangle::Overlaps(Rectangle& other){
    
    if(this->p1_.x >= other.get_p2().x || this->p2_.x >= other.get_p1().x){
        return false;
    }
    if(this->p1_.y <= other.get_p2().y || this->p2_.y <= other.get_p1().y){
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