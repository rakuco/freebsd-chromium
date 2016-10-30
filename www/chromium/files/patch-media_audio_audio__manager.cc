--- media/audio/audio_manager.cc.orig	2016-07-20 22:03:25.000000000 +0300
+++ media/audio/audio_manager.cc	2016-08-01 04:22:25.372043000 +0300
@@ -92,7 +92,7 @@
   }
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   void set_app_name(const std::string& app_name) { app_name_ = app_name; }
   const std::string& app_name() const { return app_name_; }
 #endif
@@ -250,7 +250,7 @@
   std::unique_ptr<base::win::ScopedCOMInitializer> com_initializer_for_testing_;
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   std::string app_name_;
 #endif
 
@@ -359,7 +359,7 @@
   g_helper.Pointer()->enable_crash_key_logging();
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 // static
 void AudioManager::SetGlobalAppName(const std::string& app_name) {
   g_helper.Pointer()->set_app_name(app_name);
