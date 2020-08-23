#define HP 1
#define LP 2

class Person{
    int id;
    float weight;
    int init;
    int dest;
    int priority; // 1 for high, 2 for low
    bool completed;
    bool inside;

public:
    Person(int id, float w, int i, int d, int p) : id(id), weight(w), init(i), dest(d), priority(p){
        completed = false;
        inside=false;
    }

    int getID() const {
        return id;
    }

    float getWeight() const {
        return weight;
    }

    int getInit() const {
        return init;
    }

    int getDest() const {
        return dest;
    }

    int getPriority() const {
        return priority;
    }

    void setCompleted(bool c){
        completed=c;
    }

    bool getCompleted() const{
        return completed;
    }

    void setInside(bool c){
        inside=c;
    }

    bool getInside() const{
        return inside;
    }
};