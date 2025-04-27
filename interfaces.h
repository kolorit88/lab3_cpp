
#include <iostream>
#include <unknwn.h>
#include <objbase.h>

using namespace std;

extern const IID IID_IX;
extern const IID IID_IY;
extern const IID IID_IZ;
extern const IID IID_IUnknown1;

interface IX : IUnknown {
    virtual void __stdcall Fx() = 0;
};

interface IY : IUnknown {
    virtual void __stdcall Fy() = 0;
};

interface IZ : IUnknown {
    virtual void __stdcall Fz() = 0;
};

// Компонент
class CA : public IX, public IY, public IZ {
    public: ULONG m_cRef = 0;

    // Реализация методов класса IUnknown

    virtual ULONG __stdcall AddRef();
    virtual ULONG __stdcall Release();
    virtual HRESULT __stdcall QueryInterface(const IID &iid, void **ppv);

    virtual void __stdcall Fx();
    virtual void __stdcall Fy();


};

// Функция создания компонента
IUnknown* CreateInstance();