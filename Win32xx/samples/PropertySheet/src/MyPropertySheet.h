//////////////////////////////////////////////
// MyPropertySheet.h

#ifndef MYPROPERTYSHEET_H
#define MYPROPERTYSHEET_H


class CMyPropertySheet : public CPropertySheet
{
public:
    CMyPropertySheet(LPCTSTR caption = NULL, HWND hParent = NULL);
    virtual void OnClose() { TRACE("OnClose\n"); CPropertySheet::OnClose(); }
    virtual void OnDestroy() { TRACE("OnDestroy\n"); }
    virtual void OnInitialUpdate();
    virtual LRESULT WndProc(UINT msg, WPARAM wparam, LPARAM lparam);

};

class CButtonPage : public CPropertyPage
{
public:
    CButtonPage(UINT templateID, LPCTSTR title = NULL);
    virtual INT_PTR DialogProc(UINT msg, WPARAM wparam, LPARAM lparam);
    virtual BOOL OnApply();
    virtual void OnCancel();
    virtual BOOL OnInitDialog();
    virtual void OnOK();
    virtual BOOL OnQueryCancel();
    virtual BOOL OnSetActive();
    virtual BOOL Validate();
};

class CComboPage : public CPropertyPage
{
public:
    CComboPage(UINT templateID, LPCTSTR title  = NULL);
    virtual INT_PTR DialogProc(UINT msg, WPARAM wparam, LPARAM lparam);
    virtual BOOL OnInitDialog();
    virtual BOOL OnSetActive();
    virtual BOOL OnApply()
    {
        SetModified(TRUE);
        return TRUE;
    }

};


#endif // MYPROPERTYSHEET_H

