#include "Car.h"
#include "Utilizer.h"
#include <ctype.h>

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/

int Car::getTotalLaptime() const{
  Laptime* temp=head;
  int total=0;
  while(temp!=NULL){
    total+=temp->getLaptime();
    temp=temp->getNextLaptime();
  }
  return total;
}

void Car::nullLaptime(){
  this->head=NULL;
}

std::string surname(std::string& name){
  int pos = name.rfind(' ')+1;
  std::string ch="";
  for(int i=0; i<3; i++){
    ch.push_back(toupper(name[pos+i]));
  }
  return ch;
}

Car* Car::getNext(){
  return next;
}

void Car::setNext(Car* c){
  next=c;
}

void Car::goBackLap(int n){
  Laptime *temp=head;
  for(int i=0;i<n;i++){
    temp=temp->getNextLaptime();
  }
  Laptime *temp2=temp->getNextLaptime();
  Laptime *temp3;
  temp->addLaptime(NULL);
  while(temp2!=NULL){
    temp3=temp2->getNextLaptime();
    delete temp2;
    temp2=temp3;
  }
}

void Car::Lap2(){
  Laptime *temp=head;
  while(temp->getNextLaptime()->getNextLaptime()!=NULL){
    temp=temp->getNextLaptime();
  }
  delete temp->getNextLaptime();
  temp->setNextLaptime(NULL);
}

Laptime* Car::getLatestLaptime() const{
  if(head==NULL) return NULL;
  Laptime *temp=head;
  while(temp->getNextLaptime()!=NULL){
    temp=temp->getNextLaptime();
  }
  return temp;
}

Laptime* Car::getFastestLaptime() const{
  if(head==NULL) return NULL;
  Laptime *temp=head;
  Laptime* fastest=head;
  while(temp->getNextLaptime()!=NULL){
    if(temp->getLaptime()<fastest->getLaptime()) fastest=temp;
    temp=temp->getNextLaptime();
  }
  return fastest;
}

Car::Car(std::string name){
  performance = Utilizer::generatePerformance();
  driver_name = name;
  head=NULL; next=NULL;
}

Car::Car(const Car& rhs){
  driver_name=rhs.driver_name;
  performance=rhs.performance;
  next=NULL;

  if(rhs.head!=NULL){
    head=new Laptime(rhs.head->getLaptime());
    Laptime *temp=(rhs.head)->getNextLaptime();
    Laptime *temp2=head;
      while(temp!=NULL){
        temp2->setNextLaptime(new Laptime(temp->getLaptime()));
        temp2 = temp2->getNextLaptime();
        temp=temp->getNextLaptime();
      }
  }
  else{
    head=NULL;
  }
}

Car::~Car(){
  Laptime *temp;
  while(head!=NULL){
    temp=head->getNextLaptime();
    delete head;
    head=temp;
  }
}

std::string Car::getDriverName() const{
  return driver_name;
}

double Car::getPerformance() const{
  return performance;
}

void Car::addCar(Car *n){
  Car* temp=this;
  while(temp->next!=NULL){
    temp=temp->next;
  }
  temp->next=n;
}

bool Car::operator<(const Car& rhs) const{
  double totall = this->getTotalLaptime();
  double totalr = rhs.getTotalLaptime();
  return totall<totalr;
}

bool Car::operator>(const Car& rhs) const{
  double totall = this->getTotalLaptime();
  double totalr = rhs.getTotalLaptime();
  return totall>totalr;
}

Laptime Car::operator[](const int lap) const{
  if(lap<0) return Laptime(0);
  if(lap==0) return *head;
  else{
    Laptime *temp=head->getNextLaptime();
    int i=1;
    while(temp!=NULL){
      if(i==lap) return *temp;
      temp=temp->getNextLaptime(); i++;
    }
    return Laptime(0);
  }
}

void Car::Lap(const Laptime& average_laptime){
  Laptime *var = new Laptime(Utilizer::generateLaptimeVariance(performance));
  *var + average_laptime;
  if(this->head){
    this->head->addLaptime(var);
  }
  else{
    this->head=var;
  }
}

std::ostream& operator<<(std::ostream& os, const Car& car){
  std::string name = car.driver_name;
  std::string sur = surname(name);
  os << sur;
  os << "--";
  os<<*car.getLatestLaptime()<<"--"<<*car.getFastestLaptime()<<"--"<<Laptime(car.getTotalLaptime());
}
