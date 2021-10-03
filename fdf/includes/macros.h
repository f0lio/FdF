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
# else // Tested on: Ubuntu-20.04.2
    # define KEY_ESC        65307
    # define EXIT_BTN       -1
    # define KEY_UP         65362
    # define KEY_LEFT       65361
    # define KEY_RIGHT      65363
    # define KEY_DOWN       65364
    # define KEY_PLUS       61
    # define KEY_MINUS      45
    # define MOUSE_DOWN     4
    # define MOUSE_UP       5
# endif

# define ANGLE              .8
# define ZOOM               20
# define ZOOM_SPEED         5
# define MIN_ZOOM           10
# define MAX_ZOOM           100
# define SHIFT_SPEED        3

# define DEFAULT_COLOR      WHITE
# define WHITE              0xffffff
# define BLACK              0x000

#endif
