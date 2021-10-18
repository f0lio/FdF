#ifndef _MACROS_H
# define _MACROS_H

# define PROGRAM_NAME       "fdf"

# define WINDOW_WIDTH       1080
# define WINDOW_HEIGHT      720

# define ERR_MLX_WIN        "FAILED AT OPENING WINDOW"
# define ERR_CLOSE          "FAILED AT CLOSING FILE"
# define ERR_OPEN           "FAILED AT OPENING FILE"
# define ERR_ARG            "You must provide one valid map as an argument"

# define FALSE              0
# define TRUE               1
# define BOOL               char

#if __APPLE__
    # define KEY_ESC        53
    # define EXIT_BTN       17
    # define KEY_LEFT       123
    # define KEY_RIGHT      124
    # define KEY_DOWN       125
    # define KEY_UP         126
    # define KEY_PLUS       69
    # define KEY_MINUS      78
    # define KEY_V          9
    # define KEY_SPACE      49
    # define MOUSE_CLICK    1
    # define MOUSE_DOWN     4
    # define MOUSE_UP       5
    # define KEY_ANGLE_UP   13
    # define KEY_ANGLE_DOWN 1
# else // Tested on: Ubuntu-20.04.2
    # define KEY_ESC        65307
    # define EXIT_BTN       -1
    # define KEY_UP         65362
    # define KEY_LEFT       65361
    # define KEY_RIGHT      65363
    # define KEY_DOWN       65364
    # define KEY_PLUS       61
    # define KEY_MINUS      45
    # define KEY_V          118
    # define KEY_SPACE      32
    # define MOUSE_DOWN     4
    # define MOUSE_CLICK    1
    # define MOUSE_UP       5
    # define KEY_ANGLE_UP   119
    # define KEY_ANGLE_DOWN 115
# endif

# define PI                 3.14159265359
# define ANGLE              .8
# define ZOOM               20
# define ZOOM_SPEED         2
# define MIN_ZOOM           5
# define MAX_ZOOM           100
# define SHIFT_SPEED        4

# define INFO_OFFSET        15

# define DEFAULT_COLOR      WHITE
# define WHITE              0xffffff
# define BLACK              0x000
# define GREEN              0x00ff00
# define BLUE               0x0000ff
# define CYAN               0xd7f0

#endif
