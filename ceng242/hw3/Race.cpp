#include "Race.h"
#include "Utilizer.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/

static int count=0;
static int r=0;
static const std::string alph="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

std::string Race::randomName() {
  std::string s=alph.substr(r,r+3)+" "+alph.substr(r,r+3);
  if(r==23) r=0; else r++;
  return s;
}

void Race::sortCars(Car *start){
  int swapped=1, i;
  Car *ptr1;
  Car *lptr = NULL;
  if (start == NULL)
      return;
  while(swapped){
      swapped = 0;
      ptr1 = start;
      while (ptr1->getNext() != lptr){
          if (*ptr1 > *(ptr1->getNext())){
              swap(ptr1, ptr1->getNext());
              swapped = 1;
          }
          ptr1 = ptr1->getNext();
      }
      lptr = ptr1;
  }
}

void Race::swap(Car *c1, Car *c2){
  Car* p1=findPrev(c1->getDriverName());
  Car* p2=findPrev(c2->getDriverName());
  Car* a1=c1->getNext();
  Car* a2=c2->getNext();

  p1->setNext(c2); c2->setNext(a1);
  p2->setNext(c1); c1->setNext(a2);
}

Car* Race::findPrev(std::string name){
  Car* temp=head;
  while(temp!=NULL){
    if(temp->getNext()->getDriverName()==name) return temp;
    temp=temp->getNext();
  }
}

Race::Race(std::string name):
  average_laptime(Laptime(Utilizer::generateAverageLaptime())) {
  race_name=name;
  head=NULL;
}

Race::Race(const Race& rhs): average_laptime(rhs.average_laptime){
  race_name=rhs.race_name;
  if(rhs.head!=NULL){
    head=new Car(rhs.head->getDriverName());
    Car *temp=(rhs.head)->getNext();
    Car *temp2=head;
      while(temp!=NULL){
        temp2->setNext(new Car(temp->getDriverName()));
        temp2 = temp2->getNext();
        temp=temp->getNext();
      }
  }
  else{
    head=NULL;
  }
}

Race::~Race(){
  Car *temp;
  while(head!=NULL){
    temp=head->getNext();
    delete head;
    head=temp;
  }
}

std::string Race::getRaceName() const{
  return race_name;
}

void Race::addCartoRace(){
  if(head==NULL){
    head=new Car(randomName());
  }
  else{
    Car* temp=head;
    head=new Car(randomName());
    head->setNext(temp);
  }
  count++;
}

void Race::addCartoRace(Car& car){
  if(head==NULL){
    head=new Car(car.getDriverName());
  }
  else{
    Car* temp=head;
    head=new Car(car.getDriverName());;
    head->setNext(temp);
  }
  count++;
}

int Race::getNumberOfCarsinRace(){
  return count;
}

void Race::goBacktoLap(int lap){
  Car* cars=head;
  while(cars!=NULL){
    cars->goBackLap(lap);
    cars=cars->getNext();
  }
  sortCars(head);
}

void Race::operator++(){
  Car *temp=head;
  while(temp!=NULL){
    temp->Lap(Laptime(Utilizer::generateAverageLaptime()));
    temp=temp->getNext();
  }
  sortCars(head);
}

void Race::operator--(){
  Car *temp=head;
  while(temp!=NULL){
    temp->Lap2();
    temp=temp->getNext();
  }
  sortCars(head);
}

Car Race::operator[](const int car_in_position){
  if(car_in_position==0) return *head;
  else{
    Car* temp=head->getNext();
    for(int i=1;i<this->getNumberOfCarsinRace();i++){
      if(i==car_in_position) return *temp;
      temp=temp->getNext();
    }
  }
}

Car Race::operator[](std::string driver_name){
  Car *temp=head;
  while(temp!=NULL){
    if(temp->getDriverName()==driver_name) return *temp;
    temp=temp->getNext();
  }
}

Race& Race::operator=(const Race& rhs){
  Race r=Race(rhs.race_name);
  r.average_laptime=rhs.average_laptime;
  r.head=rhs.head;

  if(r.head!=NULL){
    Car *temp=rhs.head->getNext();
    Car *temp2=r.head->getNext();
    while(temp!=NULL){
      temp2->setNext(new Car(*temp));
      temp=temp->getNext();
      temp2=temp2->getNext();
    }
  }
}

std::ostream& operator<<(std::ostream& os, const Race& race){
  if(race.head==NULL) return os;
  Car *temp=race.head;
  while(temp!=NULL){
    os<<temp->getDriverName()<<"\n";
    temp=temp->getNext();
  }
}
