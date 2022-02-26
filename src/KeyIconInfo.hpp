#include <windows.h>

// class NIData : public NOTIFYICONDATA {
// public:
//     NIData();
// };

// NIData::NIData() {
//     ;
// }

class KeyIconInfo {
private:
    INT icon_rid;       // Icon resource ID
    INT mitem_id;       // Menu item ID
    INT vtkey_id;       // Virtual Key ID
    LPCTSTR tip_text;   // Icon tool tip text
    NOTIFYICONDATA *nidata;
public:
    KeyIconInfo(INT icon_rid, INT);
    ~KeyIconInfo();
};

KeyIconInfo::KeyIconInfo() {
    icon_rid = 0;
    mitem_id = 0;
    vtkey_id = 0;
    tip_text = 0;
    nidata = new NOTIFYICONDATA();

}
