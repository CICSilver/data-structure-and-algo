#include "gui.h"
#include <stdlib.h>

static char* s[] = {"ISBN", "book_name", "author", "page_size", "publish", "price"};

typedef struct
{
    GtkWidget* window;
    GtkWidget* view;
    GtkWidget* box_1;
}window_and_view;

GtkTreeModel * create_and_fill_model()
{
    GtkListStore* store;
    GtkTreeIter iter;
    node* temp_head = getHead();
    // int size = getSize(temp_head);

    store = gtk_list_store_new(NUMS_COL, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_UINT, G_TYPE_STRING, G_TYPE_DOUBLE);
    
    while(temp_head != NULL)
    {
        gtk_list_store_append(store, &iter);
        gtk_list_store_set(store,&iter, 
                            COL_ISBN, temp_head->cur->ISBN,
                            COL_NAME, temp_head->cur->book_name,
                            COL_AUTHOR, temp_head->cur->author, 
                            COL_PAGESIZE, temp_head->cur->page_size, 
                            COL_PUBLISH, temp_head->cur->publish, 
                            COL_PRICE, temp_head->cur->price,
                            -1);
        temp_head = temp_head->next;
    }
    return GTK_TREE_MODEL(store);
}

GtkTreeView * create_view_and_model()
{
    GtkTreeModel* model;
    GtkCellRenderer* renderer;
    GtkWidget* view;

    view = gtk_tree_view_new();
    

    for(int i = 0;i<NUMS_COL;i++)
    {
        renderer = gtk_cell_renderer_text_new();
        gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(view), -1, s[i], renderer,
        "text", i, NULL);
    }

    model = create_and_fill_model();

    gtk_tree_view_set_model(GTK_TREE_VIEW(view), model);

    // g_object_unref(model);

    return view;
}

void test_add_front(window_and_view *wv)
{
    Book *p_book1 = book_new("9123609048352", "文件测试一", "文件作者0", 888, "文件测试出版社", 888.0);
    add_front_by_bookInfo(p_book1, "测试书名六", "作者5");
    g_print("inserting...\n");
    wv->view = create_view_and_model();
    while (gtk_events_pending())
    {
        gtk_main_iteration();
    }

    // sleep(1);
    // gdk_window_process_all_updates();
    // gtk_widget_show_all(wv->window);
}

void gui_init(int* argc, char** argv[])
{
    window_and_view* wv = (window_and_view *)calloc(1, sizeof(window_and_view));
    // GtkWidget* window;
    // GtkWidget* view;
    //横向盒，放列表和另一个纵向盒
    // GtkWidget* wv->box_1;
    //纵向盒，放置于wv->box_1，用于存放多组控件
    GtkWidget* box_2;
    GtkWidget* label;
    GtkWidget* button;

    gtk_init(&argc, &argv);

    wv->window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    wv->box_1 = gtk_hbox_new(FALSE, 0);
    box_2 = gtk_vbox_new(FALSE, 0);
    wv->view = create_view_and_model();
    // label = gtk_label_new("ISBN");
    gtk_container_add(GTK_CONTAINER(wv->window), wv->box_1);
    button = gtk_button_new_with_label("插入测试");
    gtk_signal_connect(GTK_OBJECT(button), "clicked", G_CALLBACK(test_add_front), wv);
    gtk_box_pack_start(GTK_BOX(box_2), button, FALSE,FALSE,0);
    button = gtk_button_new_with_label("修改测试");
    gtk_box_pack_start(GTK_BOX(box_2), button, FALSE,FALSE,0);

    gtk_box_pack_start(GTK_BOX(wv->box_1), wv->view, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(wv->box_1), box_2, TRUE, TRUE, 0);

    gtk_signal_connect(GTK_OBJECT(wv->window), "delete_event", gtk_main_quit, NULL);


    gtk_container_set_border_width(GTK_CONTAINER(wv->window), 0);
    // gtk_container_add(GTK_CONTAINER(window), view);

    gtk_widget_show_all(wv->window);

    gtk_main();
}
