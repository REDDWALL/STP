#pragma once

#include <cassert>
#include "../TProc/TProc.h"
#include "../TFrac/TFrac.h"

using namespace std;

void constructorTest() {
    TProc<int> proc = TProc<int>();
    assert(proc.Lop_Res_Get() == int());
    assert(proc.Rop_Get() == int());
    assert(proc.OprtnGet() == None);
}

void resetTest() {
    TProc<int> proc = TProc<int>();
    proc.Lop_Res_Set(10);
    proc.Rop_Set(15);
    proc.OprtnSet(Add);
    proc.ReSet();
    assert(proc.Lop_Res_Get() == int());
    assert(proc.Rop_Get() == int());
    assert(proc.OprtnGet() == None);
}

void clearTest() {
    TProc<int> proc = TProc<int>();
    proc.OprtnSet(Add);
    proc.OprtnClear();
    assert(proc.OprtnGet() == None);
}

void operationRunTest() {
    TProc<float> proc = TProc<float>();
    proc.Lop_Res_Set(1.5);
    proc.Rop_Set(2.7);
    proc.OprtnSet(Mul);
    proc.OprtnRun();
    assert(proc.Lop_Res_Get() == 4.05f);
    assert(proc.Rop_Get() == 2.7f);
    assert(proc.OprtnGet() == Mul);
}

void functionRunTest() {
    TProc<TFrac> proc = TProc<TFrac>();
    TFrac frac(3, 4);
    proc.Rop_Set(frac);
    proc.FuncRun(Rev);
    assert(proc.Rop_Get() == frac.reverse());
}

void gettersTest() {
    TProc<TFrac> proc = TProc<TFrac>();
    assert(proc.Lop_Res_Get() == TFrac());
    assert(proc.Rop_Get() == TFrac());
    assert(proc.OprtnGet() == None);
}

void settersTest() {
    TProc<TFrac> proc = TProc<TFrac>();
    TFrac frac_1(1, 2), frac_2(10, 20);
    proc.Lop_Res_Set(frac_1);
    proc.Rop_Set(frac_2);
    proc.OprtnSet(Mul);
    assert(proc.Lop_Res_Get() == frac_1);
    assert(proc.Rop_Get() == frac_2);
    assert(proc.OprtnGet() == Mul);
}
