#include "Video.hpp"

ostream& operator<<(ostream& out, const Video & video) {
    out << "title:" << video.title << ",genre:" << video.genre << endl;
    return out;
}

/* TO-DO: method implementations below */

 Video::Video(){
   title=string();
   genre=string();
 }

 Video::Video(string p_title,string p_genre){
   title=p_title;
   genre=p_genre;
 }

Video::~Video(){
  delete &title;
  delete &genre;
}

const string& Video::getTitle() const{
  return title;
}

void Video::setTitle(const string& p_title){
  title=p_title;
}

const string& Video::getGenre() const{
  return genre;
}

void Video::setGenre(const string& p_genre){
  title=p_genre;
}

bool Video::operator==(const Video & rhs) const{
  return (getTitle()==rhs.getTitle());
}

