#include <iostream>
#include <string>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

void addNode(struct Node **head, int data){
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  node->data = data;
  node->next = *head;
  *head = node;
}

class Box {
  private:
    int h;
    int w;
    int l; 
  public:
    double getVolume();
    void setHeight(int height);
    void setWidth(int width);
    void setLength(int length);
    bool HasMoreVolume(Box box){
      return this->getVolume() > box.getVolume();
    }
    Box(int height, int width, int length);
    Box();
    Box operator+(const Box &b){                
        return Box(b.h+this->h, b.w+this->w, b.l+this->l);
    }
    Box operator*(const Box &b){                
        return Box(b.h*this->h, b.w*this->w, b.l*this->l);
    }
};







Box::Box(int height, int width, int length){
  h = height;
  w = width;
  l = length;
  cout << h << " " << w << " " << l << endl;
}

double Box::getVolume(){
  return h*w*l;
}

void Box::setHeight(int height){
  h = height;
}

void Box::setWidth(int width){
  w = width;
}

void Box::setLength(int length){
  l = length;
}

class Rectangle {
  private:
    int h, w;
  public:
    void setHeight(int height){
        h = height;
    };
    void setWidth(int width){
        w = width;
    }
};

class ColoredRectangle : public Rectangle {
    public:
        string color;               
};



int main(){
  Box box1 = Box(1, 2, 3);
  Box box2 = Box(1, 2, 4);

  ColoredRectangle coloredRectangle = ColoredRectangle();
  coloredRectangle.color = "Blue";
  coloredRectangle.setHeight(1);
  coloredRectangle.setWidth(3);  


  box1.setHeight(1);    
  box1.setWidth(2);
  box1.setLength(3);
  
  cout << box1.getVolume() << endl;
  cout << box2.getVolume() << endl;
  cout << ( box2.HasMoreVolume(box1) ? "True" : "False") << endl;
    
  Box box3 = box1+box2;
  cout << box3.getVolume() << endl;

  Box box4 = box1*box2;
  cout << box4.getVolume() << endl;


  return 0;
}