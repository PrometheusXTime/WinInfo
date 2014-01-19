

#ifndef TREE_CONTROL_H_
#define TREE_CONTROL_H_

#include <windows.h>
#include <commctrl.h>
#include <tchar.h>

#include <map>

#include "Helper.h"
#include "IWindow.h"

/*
http://msdn.microsoft.com/en-us/library/windows/desktop/ms633497%28v=vs.85%29.aspx (EnumWindows function)

http://www.experts-exchange.com/Programming/Languages/CPP/A_655-How-to-provide-a-CALLBACK-function-into-a-C-class-object.html (How to provide a CALLBACK function into a C++ class object)
*/

using namespace std;

class TreeControl
{
    private:
	    HWND hWnd;

		multimap<HWND, HWND> hwndTree;

		BOOL isPairExist(pair<HWND, HWND> p);
		static BOOL CALLBACK addWndHandle(HWND hWnd, LPARAM lParam);
		static BOOL CALLBACK addChildWndHandle(HWND hWnd, LPARAM lParam);
		
		static BOOL addToWndTree(HWND hWnd, TreeControl *treeCtrl);
		BOOL addParentChildPairsToWndTree();
		void buildTree(HWND hWnd, HTREEITEM parent);
    public:
		TreeControl(HWND hWnd);
		~TreeControl();

};


#endif

