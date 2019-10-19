#include "Laptime.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/

Laptime::Laptime(int laptime){
  this->laptime=laptime;
  this->next=NULL;
}

Laptime::Laptime(const Laptime& rhs){
  this->laptime=rhs.laptime;
  this->next=NULL;
}

Laptime::~Laptime(){}

void Laptime::addLaptime(Laptime *n){
  Laptime* temp=this;
  while(temp->next!=NULL){
    temp=temp->next;
  }
  temp->next=n;
}

bool Laptime::operator<(const Laptime& rhs) const{
  return (this->laptime<rhs.laptime);
}

bool Laptime::operator>(const Laptime& rhs) const{
  return (this->laptime>rhs.laptime);
}

Laptime& Laptime::operator+(const Laptime& rhs){
  this->laptime+=rhs.laptime;
  return *this;
}

std::ostream& operator<<(std::ostream& os, const Laptime& l){
  int min = l.laptime / 60000;
  int sec = (l.laptime-60000*min)/1000;
  int ms = (l.laptime-60000*min-1000*sec);
  if(sec<10){
    if(ms<10){
      os << min << ":0" << sec << ".00" << ms;
    }
    else if(ms<100){
      os << min << ":0" << sec << ".0" << ms;
    }
    else{
      os << min << ":0" << sec << "." << ms;
    }
  }
  else{
    if(ms<10){
      os << min << ":" << sec << ".00" << ms;
    }
    else if(ms<100){
      os << min << ":" << sec << ".0" << ms;
    }
    else{
      os << min << ":" << sec << "." << ms;
    }
  }
  return os;
}

int Laptime::getLaptime() const{
  return laptime;
}

Laptime* Laptime::getNextLaptime() const{
  return next;
}

void Laptime::setNextLaptime(Laptime *l){
  next=l;
}
