--- chrome/browser/ui/views/frame/browser_view.cc.orig	Thu Apr 14 19:53:16 2016
+++ chrome/browser/ui/views/frame/browser_view.cc	Thu Apr 14 19:53:26 2016
@@ -187,7 +187,7 @@
 #include "content/public/common/mojo_shell_connection.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "ui/native_theme/native_theme_dark_aura.h"
 #endif
 
@@ -2017,7 +2017,7 @@
 #if defined(OS_WIN)
     ui::NativeThemeDarkWin::instance()->NotifyObservers();
     ui::NativeThemeWin::instance()->NotifyObservers();
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
     ui::NativeThemeDarkAura::instance()->NotifyObservers();
     ui::NativeThemeAura::instance()->NotifyObservers();
 #endif