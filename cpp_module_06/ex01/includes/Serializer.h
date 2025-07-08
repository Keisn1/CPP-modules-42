#ifndef SERIALIZER_H
#define SERIALIZER_H
#include <stdint.h>

struct Data;

class Serializer {
private:
    Serializer(void);
    Serializer(const Serializer&);
    Serializer& operator=(const Serializer&);
    ~Serializer(void);

public:
    static uintptr_t serialize(Data*);
    static Data* deserialize(uintptr_t);
};


#endif // SERIALIZER_H
