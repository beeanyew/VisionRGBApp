/* (06-Sep-2016) [Tab/Indent: 8/8][Line/Box: 80/74]          (CRichEditView.h) *
********************************************************************************
|                                                                              |
|                   Copyright (c) 2016, Robert C. Tausworthe                   |
|                             All Rights Reserved.                             |
|                          robert.c.tausworthe@ieee.org                        |
|                                                                              |
===============================================================================*

    Contents Description: Declaration of the CRichEditView class for the
    CommonDialogs sample  application using the Win32++ Windows interface
    classes, Copyright (c) 2005-2016 David Nash, under permissions granted
    therein.

        Caveats: The copyright displayed above extends only to the author's
    original contributions to the subject class, and to the alterations,
    additions, deletions, and other treatments of materials that may have
    been extracted from the cited sources.  Unaltered portions of those
    materials retain their original copyright status. The author hereby
    grants permission to any person obtaining a copy of this treatment
    of the subject class and any associated documentation composed by
    the author, to utilize this material, free of charge and without
    restriction or limitation, subject to the following conditions:

        The above copyright notice, as well as that of David Nash
        and Win32++, together with the respective permission
        conditions shall be included in all copies or substantial
        portions of this material so copied, modified, merged,
        published, distributed, or otherwise held by others.

    These materials are provided "as is", without warranty of any kind,
    express or implied, including but not limited to: warranties of
    merchantability, fitness for a particular purpose, and non-infringement.
    In no event shall the authors or copyright holders be liable for any
    claim, damages, or other liability, whether in an action of contract,
    tort or otherwise, arising from, out of, or in connection with, these
    materials, the use thereof, or any other other dealings therewith.


    Special Conventions:

    Acknowledgement:
        The author would like to thank and acknowledge the advice,
        critical review, insight, and assistance provided by David Nash
        in the development of this work.

    Programming Notes:
               The programming standards roughly follow those established
                by the 1997-1999 Jet Propulsion Laboratory Deep Space Network
        Planning and Preparation Subsystem project for C++ programming.

********************************************************************************

    Declaration of the CRichEditView class

*******************************************************************************/

#ifndef CRICHEDITVIEW_H
#define CRICHEDITVIEW_H

#include "PrintInfo.h"

/*============================================================================*/
    class
CRichEditView : public CRichEdit                                        /*

*-----------------------------------------------------------------------------*/
{
    public:
        CRichEditView();
        virtual ~CRichEditView();

        void    Clean();
        void    DoPrintRichView(const CString& sDocPath);
        void    DoPrintView();
        BOOL    IsSelected();
        void    SetColors(COLORREF txfg, COLORREF txbg, COLORREF bg);
        void    SetDocPath(const CString& s)
                  { m_sDocPath = s;}
        void    SetFont(HFONT hFont, BOOL bRedraw) const;
        void    SetPrintPath(const CString& s)
                  { m_sPrintPath = s;}
        void    SetWrapping(int wrap);
        BOOL    StreamInFile(const CFile& file, BOOL mode);
        BOOL    StreamOutFile(const CFile& file, BOOL mode);

    protected:
        BOOL    DoPreparePrinting(CPrintInfo& info);
        void    OnAttach();
        void    GetPageBreaks(CPrintInfo&);
        void    OnBeginPrinting(CDC& DC, CPrintInfo& info);
        void    OnEndPrinting(CDC& DC, CPrintInfo& info);
        void    OnPrepareDC(CDC& DC, CPrintInfo& info);
        BOOL    OnPreparePrinting(CPrintInfo& info);
        void    OnPrint(CDC& DC, CPrintInfo& info);
        void    SetAppBanding(BOOL b) { m_bAppBanding = b;}

        static  DWORD CALLBACK StreamInCallback(DWORD dwCookie,
                LPBYTE pbBuff, LONG cb, LONG *pcb);
        static  DWORD CALLBACK StreamOutCallback(DWORD dwCookie,
                LPBYTE pbBuff, LONG cb, LONG *pcb);


    private:
        long    m_nTextLength;
        CString m_sDocPath;    // document path name
        CString m_sPrintPath;  // print-to-file path (not supported)
        CString m_sDataType;   // data ised t0o record print job
        BOOL    m_bAppBanding; // TRUE if app banding supported
        FORMATRANGE m_fr;
        std::vector<int> m_page_first_char;
};
/*----------------------------------------------------------------------------*/
#endif  // CRICHEDITVIEW_H
