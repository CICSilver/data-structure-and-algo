#ifndef _GUI_H
#define _GUI_H

#include <gtk-2.0/gtk/gtk.h>
#include "book_manager.h"

enum
{
    COL_ISBN = 0,
    COL_NAME,
    COL_AUTHOR,
    COL_PAGESIZE,
    COL_PUBLISH,
    COL_PRICE,
    NUMS_COL
};



GtkTreeModel * create_and_fill_model();

GtkTreeView * create_view_and_model();

void gui_init(int* argc, char** argv[]);



#endif