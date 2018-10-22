#pragma once

#include <cassert>
#include "../TMemory/TMemory.h"

using namespace std;

void constructorTest() {
    TMemory<int> memory = TMemory<int>();
    assert(memory.getFState() == "_Off");
    assert(memory.get() == int() && memory.getFState() == "_On");
}

void addTest() {
    TMemory<int> memory = TMemory<int>();
    memory.set(10);
    memory.add(10);
    assert(memory.getFNumber() == 20);
}

void clearTest() {
    TMemory<string> memory = TMemory<string>();
    memory.set("test");
    assert(memory.getFState() == "_On");
    memory.clear();
    assert(memory.getFState() == "_Off");
}

void gettersTest() {
    TMemory<float> memory = TMemory<float>();
    assert(memory.getFState() == "_Off");
    assert(memory.get() == float() && memory.getFState() == "_On");
    assert(memory.getFNumber() == float());
}

void settersTest() {
    TMemory<float> memory = TMemory<float>();
    memory.set(5.6f);
    assert(memory.get() == 5.6f && memory.getFState() == "_On");
}
