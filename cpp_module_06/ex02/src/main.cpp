#include "Base.h"
#include "functions.h"

int main() {
    Base* p = generate();
    identify(p);
    identify(*p);
    delete p;
    return 0;
}
