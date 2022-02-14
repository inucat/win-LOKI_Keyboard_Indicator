#pragma once

// Tray icons total
#define NUM_TRAYICONS    4

// Bit mask for GetKeyState() toggled state
#define GKS_IS_TOGGLED  1

/* --- CONFig file definitions --- */
#define CONF_FILENAME       "\\loki.ini"
#define CONF_HIDESECT       "HiddenFlag"
#define CONF_NOTISECT       "Notification"
#define CONF_NOTISKEY       "Enabled"

/* --- REGistry Keys & Value Names --- */
/* Current UI theme (Dark or Light) */
#define REGK_UITHEME    "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize"
#define REGVN_UITHEME   "AppsUseLightTheme"
/* User's auto run entry */
#define REGK_USERAUTORUN    "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run"
#define REGVN_AUTORUN       "LOKI-{48D10A91-BF2A-40A4-AE41-55BA0662EC6E}"

#define STR_ABOUT "Version:\t" STR_APPVER "\n" \
                  "Release:\t" STR_RELEASEDATE "\n" \
                  "Author:\t" STR_AUTHOR

/// App-specific Window Messages
/// @note The values over WM_APP can be used.
enum APP_DEFINED_WINDOW_MESSAGE {
    WM_TRAYICONCLICKED = ((WM_APP) + 100),
    WM_UITHEMECHANGED,
    WM_LLKEYHOOKED
};

// IDs to distinguish each NOTIFYICONDATA
enum NID_ID {
    NIDID_NUML,
    NIDID_CAPL,
    NIDID_SCRL,
    NIDID_INS
};

struct key_icon_struct {
    INT iconID;     // Icon resource ID
    INT menuitemID; // Menu item ID
    INT nidID;      // NOTIFYICONDATA ID
    INT virtkeyID;  // Virtual Key ID
    INT nFlagMask;  // unused
    LPCTSTR szTip;  // Icon tool tip text
};


/// Check/Uncheck Menu Item
/// @param UINT Menu item ID
/// @param BOOL State (TRUE=checked, FALSE=unchecked)
static void set_mitem_check_state(UINT, BOOL);

/// Checks which Windows theme currently applied, Dark or Light
/// @return TRUE if Light theme is selected and FALSE otherwise.
static BOOL check_theme_is_light(void);

/// Get icon resource ID corresponding to the key state & Win theme
/// @param key_icon_struct* Pointer to the key
/// @param BOOL True when Light theme is applied
/// @return Icon resource ID
static INT get_icon_rsrc_id(const struct key_icon_struct*, BOOL);
