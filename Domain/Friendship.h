#ifndef PROIEEEECT_FRIENDSHIP_H
#define PROIEEEECT_FRIENDSHIP_H
using namespace std;
#include <string>
#include <vector>
#include <ostream>

class Friendship {
public:
    Friendship(int id, int id1, int id2);

    Friendship(string args);

    int getId() const;

    void setId(int id);

    int getId1() const;

    void setId1(int id1);

    int getId2() const;

    void setId2(int id2);

    virtual ~Friendship();

private:
    int id;
    int id1;
    int id2;
public:

    void fromString(string args, char delimiter = ',');

    string toString(char delimiter = ',');

    friend ostream &operator<<(ostream &os, const Friendship &friendship);
};


#endif //PROIEEEECT_FRIENDSHIP_H
