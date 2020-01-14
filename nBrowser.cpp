#include <iostream>
#include <gtkmm.h>
#include <webkit2/webkit2.h>

using namespace std;
using namespace Gtk;
 
class SimpleBrowser : public Window
{
    // controls
 
    protected: 
        VBox vBoxMain;
        HBox hBoxUrl;
        //Label labelUrl;
        Entry textUrl;
        Button buttonGo;
	Gtk::Window window;
	WebKitWebView * wv;
	Gtk::Widget * webkitWebViewWidget;
 
    // methods
 
    public: SimpleBrowser()
    {
	// Root Window	
	set_default_size(1080, 1670);
        set_border_width(10);
	set_hide_titlebar_when_maximized(FALSE);
	set_title("simple webkit browser");
 
	// vBoxMain
        add(vBoxMain);
        vBoxMain.show();
 
	// hBoxUrl
        vBoxMain.add(hBoxUrl);
        hBoxUrl.show();
 
        // labelUrl
	/*
        labelUrl.set_label("URL:");
        hBoxUrl.add(labelUrl);
        labelUrl.show();
	*/
 
        // textUrl
        textUrl.set_text("https://webkit.org/");
        textUrl.set_size_request(960, 40);
        hBoxUrl.add(textUrl);
        textUrl.show();
 
        // buttonGo
        buttonGo.set_label("Go");
        buttonGo.signal_clicked().connect
        (
            sigc::mem_fun
            (
                *this,
                &SimpleBrowser::buttonGoClicked
            )
        );
        hBoxUrl.add(buttonGo);
        buttonGo.show();

        // webkitWebViewWidget
        wv =  WEBKIT_WEB_VIEW( webkit_web_view_new() );
	webkit_web_view_load_uri(wv, "https://webkit.org/");
	webkitWebViewWidget = Glib::wrap(GTK_WIDGET(wv));
	webkitWebViewWidget->set_size_request(1060, 1630); 	
        vBoxMain.add(*webkitWebViewWidget);
        webkitWebViewWidget->show();
    }
 
    // event handlers
 
    protected: void buttonGoClicked()
    {
        gchar * urlString = (gchar *)g_uri_unescape_string(g_uri_escape_string(textUrl.get_text().c_str(), NULL, FALSE), NULL);
        // cout << "URL is : " << urlString;
	webkit_web_view_load_uri(wv, urlString); 
    }
};
 
int main (int argc, char *argv[])
{
    Main kit(argc, argv);
    SimpleBrowser SimpleBrowser;
    Main::run(SimpleBrowser);
    return 0;
}

