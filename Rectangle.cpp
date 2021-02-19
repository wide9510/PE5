/** Non-buggy Rectangle.cpp
 * Names: Jaclyn Stickrod and William Dellinger
*/
#include <iostream>
#include "Rectangle.h"

//Rectangle could be reversed into negative space
Rectangle::Rectangle(Point p1, Point p2){
    if((p2.y < p1.y) || (p2.x < p1.x)){
        this->p1_ = p2;
        this->p2_ = p1;
    }
    else{
        this->p1_ = p1;
        this->p2_ = p2;
    }
}
//no bugs found
int Rectangle::GetWidth(){
    return this->p2_.x - this->p1_.x;
}
//no bugs found
int Rectangle::GetHeight(){
    return this->p2_.y - this->p1_.y;
}
//failed for partial overlaps
bool Rectangle::Overlaps(Rectangle& other){
    
    if( (other.get_p1().y > this->p2_.y) || (this->p1_.y > other.get_p2().y)){
        return false;
    }
    if( (this->p2_.x < other.get_p1().x) || (other.get_p2().x < this->p1_.x)){
        return false;
    }

    return true;


}
//no bugs found
int Rectangle::CalculateArea(){
    int width = this->GetWidth();
    int height = this-> GetHeight();
    return width * height;
}
//no bugs found
void Rectangle::Expand(){
    p1_.x--;
    p1_.y--;
    p2_.x++;
    p2_.y++;
}
//shrink past a point
void Rectangle::Shrink(){
    if( (p1_.x != p2_.x) && (p1_.y != p2_.y)){
        p1_.x++;
        p1_.y++;
        p2_.x--;
        p2_.y--;
    }
}
