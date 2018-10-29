#pragma once

enum TOprtn {
    None,
    Add,
    Sub,
    Mul,
    Dvd
};

enum TFunc {
    Rev,
    Sqr
};

template<class T>
class TProc {
private:
    T Lop_Res;
    T Rop;
    TOprtn Operation;
public:
    TProc() : Lop_Res(T()), Rop(T()) {
        Operation = None;
    }

    void ReSet() {
        Lop_Res = T();
        Rop = T();
        Operation = None;
    }

    void OprtnClear() {
        Operation = None;
    }

    void OprtnRun() {
        switch (Operation) {
            case Add:
                Lop_Res = Lop_Res + Rop;
                break;
            case Sub:
                Lop_Res = Lop_Res - Rop;
                break;
            case Mul:
                Lop_Res = Lop_Res * Rop;
                break;
            case Dvd:
                Lop_Res = Lop_Res / Rop;
                break;
            case None:
                break;
        }
    }

    void FuncRun(enum TFunc func) {
        switch (func) {
            case Rev:
                Rop = Rop.reverse();
                break;
            case Sqr:
                Rop = Rop.square();
                break;
            default:
                break;
        }
    }

    T Lop_Res_Get() {
        return Lop_Res;
    }

    void Lop_Res_Set(T value) {
        Lop_Res = value;
    }

    T Rop_Get() {
        return Rop;
    }

    void Rop_Set(T value) {
        Rop = value;
    }

    TOprtn OprtnGet() {
        return Operation;
    }

    void OprtnSet(TOprtn value) {
        Operation = value;
    }
};