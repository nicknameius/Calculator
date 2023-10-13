#ifndef UNICODE
#define UNICODE
#endif 

#include "main.h"

#define BTN_WIDTH 80
#define BTN_HEIGTH 70

//Button DEFINE
#pragma region
#define BTN_ZERO 100
#define BTN_ONE 101
#define BTN_TWO 102
#define BTN_THREE 103
#define BTN_FOUR 104
#define BTN_FIVE 105
#define BTN_SIX 106
#define BTN_SEVEN 107
#define BTN_EIGHT 108
#define BTN_NINE 109
#define BTN_PLUS 110
#define BTN_MINUS 111
#define BTN_EQL 112
#define BTN_DOT 113
#define BTN_SIGNED 114
#define BTN_MULT 115
#define BTN_DIV 116
#define BTN_CLEARALL 117
#define BTN_CLEAR 118
#define BTN_BACKSPACE 119
#define WRESULT 120
#pragma endregion

//Button handle
#pragma region
HWND hwndResult = NULL;
HWND hwndButton0 = NULL;
HWND hwndButton1 = NULL;
HWND hwndButton2 = NULL;
HWND hwndButton3 = NULL;
HWND hwndButton4 = NULL;
HWND hwndButton5 = NULL;
HWND hwndButton6 = NULL;
HWND hwndButton7 = NULL;
HWND hwndButton8 = NULL;
HWND hwndButton9 = NULL;
HWND hwndButtonp = NULL;
HWND hwndButtonm = NULL;
HWND hwndButtone = NULL;
HWND hwndButtond = NULL;
HWND hwndButtons = NULL;
HWND hwndButtonM = NULL;
HWND hwndButtonD = NULL;
HWND hwndButtonC = NULL;
HWND hwndButtonCE = NULL;
HWND hwndButtonBACK = NULL;
#pragma endregion

HBRUSH brush = CreateSolidBrush(RGB(32, 32, 32));
double fontSize = 30;

LPCWSTR RESULT = NULL;
std::wstring result = L"";
double nums[10] = { NULL };
int operations[10] = { NULL };
int i=0;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
void addDigit(std::wstring digit);
void delNums();
void addOperation(int op);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
    // Register the window class.
    const wchar_t CLASS_NAME[] = L"Sample Window Class";

    WNDCLASS wc = { };

    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    // Create the window.

    HWND hwnd = CreateWindowEx(
        0,                              // Optional window styles.
        CLASS_NAME,                     // Window class
        L"Calculator",                  // Window text
        WS_OVERLAPPEDWINDOW,            // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, 330, 525,

        NULL,       // Parent window    
        NULL,       // Menu
        hInstance,  // Instance handle
        NULL        // Additional application data
    );

    if (hwnd == NULL)
    {
        return 0;
    }

    //Buttons creation
#pragma region

    hwndResult = CreateWindowEx(
        0, L"STATIC", L"RESULT", WS_VISIBLE | WS_CHILD | SS_OWNERDRAW,
        0, 0, 0, 0,
        hwnd, (HMENU)WRESULT, (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);
        
    hwndButton0 = CreateWindowEx(
        0, L"BUTTON", L"0", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW,
        0, 0, 0, 0,
        hwnd, (HMENU)BTN_ZERO, (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);

    hwndButton1 = CreateWindowEx(
        0, L"BUTTON", L"1", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW,
        0, 0, 0, 0,
        hwnd, (HMENU)BTN_ONE, (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);

    hwndButton2 = CreateWindowEx(
        0, L"BUTTON", L"2", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW,
        0, 0, 0, 0,
        hwnd, (HMENU)BTN_TWO, (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);

    hwndButton3 = CreateWindowEx(
        0, L"BUTTON", L"3", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW,
        0, 0, 0, 0,
        hwnd, (HMENU)BTN_THREE, (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);

    hwndButton4 = CreateWindowEx(
        0, L"BUTTON", L"4", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW,
        0, 0, 0, 0,
        hwnd, (HMENU)BTN_FOUR, (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);

    hwndButton5 = CreateWindowEx(
        0, L"BUTTON", L"5", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW,
        0, 0, 0, 0,
        hwnd, (HMENU)BTN_FIVE, (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);

    hwndButton6 = CreateWindowEx(
        0, L"BUTTON", L"6", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW,
        0, 0, 0, 0,
        hwnd, (HMENU)BTN_SIX, (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);

    hwndButton7 = CreateWindowEx(
        0, L"BUTTON", L"7", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW,
        0, 0, 0, 0,
        hwnd, (HMENU)BTN_SEVEN, (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);

    hwndButton8 = CreateWindowEx(
        0, L"BUTTON", L"8", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW,
        0, 0, 0, 0,
        hwnd, (HMENU)BTN_EIGHT, (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);

    hwndButton9 = CreateWindowEx(
        0, L"BUTTON", L"9", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW,
        0, 0, 0, 0,
        hwnd, (HMENU)BTN_NINE, (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);

    hwndButtonp = CreateWindowEx(
        0, L"BUTTON", L"+", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW,
        0, 0, 0, 0,
        hwnd, (HMENU)BTN_PLUS, (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);

    hwndButtonm = CreateWindowEx(
        0, L"BUTTON", L"-", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW,
        0, 0, 0, 0,
        hwnd, (HMENU)BTN_MINUS, (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);

    hwndButtone = CreateWindowEx(
        0, L"BUTTON", L"=", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW,
        0, 0, 0, 0,
        hwnd, (HMENU)BTN_EQL, (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);

    hwndButtond = CreateWindowEx(
        0, L"BUTTON", L".", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW,
        0, 0, 0, 0,
        hwnd, (HMENU)BTN_DOT, (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);

    hwndButtons = CreateWindowEx(
        0, L"BUTTON", L"+/-", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW,
        0, 0, 0, 0,
        hwnd, (HMENU)BTN_SIGNED, (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);

    hwndButtonM = CreateWindowEx(
        0, L"BUTTON", L"X", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW,
        0, 0, 0, 0,
        hwnd, (HMENU)BTN_MULT, (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);

    hwndButtonD = CreateWindowEx(
        0, L"BUTTON", L"/", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW,
        0, 0, 0, 0,
        hwnd, (HMENU)BTN_DIV, (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);

    hwndButtonC = CreateWindowEx(
        0, L"BUTTON", L"C", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW,
        0, 0, 0, 0,
        hwnd, (HMENU)BTN_CLEARALL, (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);

    hwndButtonCE = CreateWindowEx(
        0, L"BUTTON", L"CE", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW,
        0, 0, 0, 0,
        hwnd, (HMENU)BTN_CLEAR, (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);

    hwndButtonBACK = CreateWindowEx(
        0, L"BUTTON", L"BACK", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW,
        0, 0, 0, 0,
        hwnd, (HMENU)BTN_BACKSPACE, (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);
#pragma endregion



    ShowWindow(hwnd, nCmdShow);

    // Run the message loop.

    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}


LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) 
{

    switch (uMsg)
    {
    case WM_CREATE:
    {
        
    }
    break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);
        FillRect(hdc, &ps.rcPaint, (HBRUSH)(brush));
        EndPaint(hwnd, &ps);
    }
    break;

    case WM_COMMAND:
        //Button functions
        switch (LOWORD(wParam)) 
        {
        case BTN_ZERO:
            addDigit(L"0");
            break;
        case BTN_ONE:
            addDigit(L"1");
            break;
        case BTN_TWO:
            addDigit(L"2");
            break;
        case BTN_THREE:
            addDigit(L"3");
            break;
        case BTN_FOUR:
            addDigit(L"4");
            break;
        case BTN_FIVE:
            addDigit(L"5");
            break;
        case BTN_SIX:
            addDigit(L"6");
            break;
        case BTN_SEVEN:
            addDigit(L"7");
            break;
        case BTN_EIGHT:
            addDigit(L"8");
            break;
        case BTN_NINE:
            addDigit(L"9");
            break;
        case BTN_PLUS:
            addOperation(1);
            break;
        case BTN_MINUS:
            addOperation(2);
            break;
        case BTN_EQL:
            addOperation(0);
            
            for (int x = 0; x < i; x++)
            {

                switch (operations[x])
                {
                case 0:
                    break;
                case 1:
                    nums[0] += nums[x + 1];
                    break;
                case 2:
                    nums[0] -= nums[x + 1];
                    break;
                case 3:
                    nums[0] *= nums[x + 1];
                    break;
                case 4:
                    nums[0] /= nums[x + 1];
                    break;
                }
            }
            result = std::to_wstring(nums[0]);
            result.erase(result.find_last_not_of('0') + 1, std::string::npos);
            result.erase(result.find_last_not_of('.') + 1, std::string::npos);
            RESULT = result.c_str();
            i = 0;
            break;
        case BTN_DOT:
            addDigit(L".");
            break;
        case BTN_SIGNED:
            
            break;
        case BTN_MULT:
            addOperation(3);
            break;
        case BTN_DIV:
            addOperation(4);
            break;
        case BTN_CLEARALL:
            result = L"";
            RESULT = result.c_str();
            delNums();
            break;
        case BTN_CLEAR:
            result = L"";
            RESULT = result.c_str();
            break;
        case BTN_BACKSPACE:
            
            break;
        }
        InvalidateRect(hwndResult, NULL, FALSE);
        UpdateWindow(hwndResult);
        break;

    case WM_DRAWITEM:
        {
            LPDRAWITEMSTRUCT lpDIS = (LPDRAWITEMSTRUCT)lParam;

            SetDCBrushColor(lpDIS->hDC, RGB(64, 64, 64));

            SelectObject(lpDIS->hDC, GetStockObject(DC_BRUSH));

            RoundRect(lpDIS->hDC, lpDIS->rcItem.left, lpDIS->rcItem.top,
                lpDIS->rcItem.right, lpDIS->rcItem.bottom, 5, 5);
            SetBkMode(lpDIS->hDC, TRANSPARENT);
            SetTextColor(lpDIS->hDC, RGB(240, 240, 240));

            HFONT hFont = (HFONT)GetStockObject(DEFAULT_GUI_FONT);
            LOGFONT logfont;
            GetObject(hFont, sizeof(LOGFONT), &logfont);

            logfont.lfHeight = fontSize;

            HFONT hNewFont = CreateFontIndirect(&logfont);
            HFONT hOldFont = (HFONT)SelectObject(lpDIS->hDC, hNewFont);
            
            // Gives every button its respective symbol
            switch (lpDIS->CtlID) 
            {
            case WRESULT:
                DrawText(lpDIS->hDC, RESULT, -1, &lpDIS->rcItem, DT_RIGHT |DT_SINGLELINE | DT_VCENTER);
                break;
            case BTN_ZERO:
                DrawText(lpDIS->hDC, L"0", 1, &lpDIS->rcItem, DT_CENTER | DT_SINGLELINE | DT_VCENTER);
                break;
            case BTN_ONE:
                DrawText(lpDIS->hDC, L"1", 1, &lpDIS->rcItem, DT_CENTER | DT_SINGLELINE | DT_VCENTER);
                break;
            case BTN_TWO:
                DrawText(lpDIS->hDC, L"2", 1, &lpDIS->rcItem, DT_CENTER | DT_SINGLELINE | DT_VCENTER);
                break;
            case BTN_THREE:
                DrawText(lpDIS->hDC, L"3", 1, &lpDIS->rcItem, DT_CENTER | DT_SINGLELINE | DT_VCENTER);
                break;
            case BTN_FOUR:
                DrawText(lpDIS->hDC, L"4", 1, &lpDIS->rcItem, DT_CENTER | DT_SINGLELINE | DT_VCENTER);
                break;
            case BTN_FIVE:
                DrawText(lpDIS->hDC, L"5", 1, &lpDIS->rcItem, DT_CENTER | DT_SINGLELINE | DT_VCENTER);
                break;
            case BTN_SIX:
                DrawText(lpDIS->hDC, L"6", 1, &lpDIS->rcItem, DT_CENTER | DT_SINGLELINE | DT_VCENTER);
                break;
            case BTN_SEVEN:
                DrawText(lpDIS->hDC, L"7", 1, &lpDIS->rcItem, DT_CENTER | DT_SINGLELINE | DT_VCENTER);
                break;
            case BTN_EIGHT:
                DrawText(lpDIS->hDC, L"8", 1, &lpDIS->rcItem, DT_CENTER | DT_SINGLELINE | DT_VCENTER);
                break;
            case BTN_NINE:
                DrawText(lpDIS->hDC, L"9", 1, &lpDIS->rcItem, DT_CENTER | DT_SINGLELINE | DT_VCENTER);
                break;
            case BTN_PLUS:
                DrawText(lpDIS->hDC, L"+", 1, &lpDIS->rcItem, DT_CENTER | DT_SINGLELINE | DT_VCENTER);
                break;
            case BTN_MINUS:
                DrawText(lpDIS->hDC, L"-", 1, &lpDIS->rcItem, DT_CENTER | DT_SINGLELINE | DT_VCENTER);
                break;
            case BTN_EQL:
                DrawText(lpDIS->hDC, L"=", 1, &lpDIS->rcItem, DT_CENTER | DT_SINGLELINE | DT_VCENTER);
                break;
            case BTN_DOT:
                DrawText(lpDIS->hDC, L".", 1, &lpDIS->rcItem, DT_CENTER | DT_SINGLELINE | DT_VCENTER);
                break;
            case BTN_SIGNED:
                DrawText(lpDIS->hDC, L"+/-", 3, &lpDIS->rcItem, DT_CENTER | DT_SINGLELINE | DT_VCENTER);
                break;
            case BTN_MULT:
                DrawText(lpDIS->hDC, L"X", 1, &lpDIS->rcItem, DT_CENTER | DT_SINGLELINE | DT_VCENTER);
                break;
            case BTN_DIV:
                DrawText(lpDIS->hDC, L"/", 1, &lpDIS->rcItem, DT_CENTER | DT_SINGLELINE | DT_VCENTER);
                break;
            case BTN_CLEARALL:
                DrawText(lpDIS->hDC, L"C", 1, &lpDIS->rcItem, DT_CENTER | DT_SINGLELINE | DT_VCENTER);
                break;
            case BTN_CLEAR:
                DrawText(lpDIS->hDC, L"CE", 2, &lpDIS->rcItem, DT_CENTER | DT_SINGLELINE | DT_VCENTER);
                break;
            case BTN_BACKSPACE:
                DrawText(lpDIS->hDC, L"<-", 2, &lpDIS->rcItem, DT_CENTER | DT_SINGLELINE | DT_VCENTER);
                break;
            }

            SelectObject(lpDIS->hDC, hOldFont);
            DeleteObject(hNewFont);
            DeleteObject(hFont);
            DeleteObject(hOldFont);
        }
        break;

    case WM_CTLCOLORBTN:
    {
        return (LRESULT)brush;
    }
    break;

    case WM_SIZE:
    {
        double width = LOWORD(lParam);
        double height = HIWORD(lParam);
        double btn_width = (width - 35) / 4;
        double btn_height = (height - 70) / 7;
        fontSize = btn_height*0.5;
        
        SetWindowPos(hwndResult, NULL,  10, 10, width-20, height-5*btn_height-45, SWP_SHOWWINDOW | SWP_NOCOPYBITS);
        SetWindowPos(hwndButton0, NULL, btn_width + 15, height - btn_height - 10, btn_width, btn_height, SWP_SHOWWINDOW);
        SetWindowPos(hwndButton1, NULL, 10, height - btn_height * 2 - 15, btn_width, btn_height, SWP_SHOWWINDOW);
        SetWindowPos(hwndButton2, NULL, btn_width + 15, height - btn_height * 2 - 15, btn_width, btn_height, SWP_SHOWWINDOW);
        SetWindowPos(hwndButton3, NULL, 2 * btn_width + 20, height - btn_height * 2 - 15, btn_width, btn_height, SWP_SHOWWINDOW);
        SetWindowPos(hwndButton4, NULL, 10, height - btn_height * 3 - 20, btn_width, btn_height, SWP_SHOWWINDOW);
        SetWindowPos(hwndButton5, NULL, btn_width + 15, height - btn_height * 3 - 20, btn_width, btn_height, SWP_SHOWWINDOW);
        SetWindowPos(hwndButton6, NULL, 2 * btn_width + 20, height - btn_height * 3 - 20, btn_width, btn_height, SWP_SHOWWINDOW);
        SetWindowPos(hwndButton7, NULL, 10, height - btn_height * 4 - 25, btn_width, btn_height, SWP_SHOWWINDOW);
        SetWindowPos(hwndButton8, NULL, btn_width + 15, height - btn_height * 4 - 25, btn_width, btn_height, SWP_SHOWWINDOW);
        SetWindowPos(hwndButton9, NULL, 2 * btn_width + 20, height - btn_height * 4 - 25, btn_width, btn_height, SWP_SHOWWINDOW);
        SetWindowPos(hwndButtonp, NULL, btn_width * 3 + 25, height - btn_height * 2 - 15, btn_width, btn_height, SWP_SHOWWINDOW);
        SetWindowPos(hwndButtonm, NULL, 3 * btn_width + 25, height - btn_height * 3 - 20, btn_width, btn_height, SWP_SHOWWINDOW);
        SetWindowPos(hwndButtone, NULL, 3 * btn_width + 25, height - btn_height - 10, btn_width, btn_height, SWP_SHOWWINDOW);
        SetWindowPos(hwndButtond, NULL, 2 * btn_width + 20, height - btn_height - 10, btn_width, btn_height, SWP_SHOWWINDOW);
        SetWindowPos(hwndButtons, NULL, 10, height - btn_height - 10, btn_width, btn_height, SWP_SHOWWINDOW);
        SetWindowPos(hwndButtonM, NULL, 3 * btn_width + 25, height - 4 * btn_height - 25, btn_width, btn_height, SWP_SHOWWINDOW);
        SetWindowPos(hwndButtonD, NULL, 3 * btn_width + 25, height - 5 * btn_height - 30, btn_width, btn_height, SWP_SHOWWINDOW);
        SetWindowPos(hwndButtonC, NULL, btn_width + 15, height - 5 * btn_height - 30, btn_width, btn_height, SWP_SHOWWINDOW);
        SetWindowPos(hwndButtonCE, NULL, 10, height - 5 * btn_height - 30, btn_width, btn_height, SWP_SHOWWINDOW);
        SetWindowPos(hwndButtonBACK, NULL, 2 * btn_width + 20, height - 5 * btn_height - 30, btn_width, btn_height, SWP_SHOWWINDOW);
            
    }
        
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

void addDigit(std::wstring digit)
{
    if (result == L"")
        result = digit;
    else if (result != L"")
    {
        result += digit;
    }
    RESULT = result.c_str();
}

void delNums()
{
    for (int x : nums)
        nums[x] = -1;

    for (int x : operations)
        operations[x] = -1;
}

void addOperation(int op)
{
    switch (op)
    {
    case 0:
        if (result != L"")
        {
            nums[i] = std::stod(result);
            operations[i] = 0;
            i++;
        }

        result = L"";
        RESULT = result.c_str();
        break;
    case 1:
        if (result != L"")
        {
            nums[i] = std::stod(result);
            operations[i] = 1;
            i++;
        }

        result = L"";
        RESULT = result.c_str();
        break;
    case 2:
        if (result != L"")
        {
            nums[i] = std::stod(result);
            operations[i] = 2;
            i++;
        }

        result = L"";
        RESULT = result.c_str();
        break;
    case 3:
        if (result != L"")
        {
            nums[i] = std::stod(result);
            operations[i] = 3;
            i++;
        }

        result = L"";
        RESULT = result.c_str();
        break;
    case 4:
        if (result != L"")
        {
            nums[i] = std::stod(result);
            operations[i] = 4;
            i++;
        }

        result = L"";
        RESULT = result.c_str();
        break;
    }
}