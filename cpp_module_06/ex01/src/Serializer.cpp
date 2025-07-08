#include "Serializer.h"
#include "Data.h"
#include <stdint.h>

Serializer::Serializer(void) {}

uintptr_t Serializer::serialize(Data* ptr) { return reinterpret_cast< uintptr_t >(ptr); }

Data* Serializer::deserialize(uintptr_t raw) { return reinterpret_cast< Data* >(raw); }
