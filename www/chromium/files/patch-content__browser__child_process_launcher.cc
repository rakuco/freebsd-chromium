--- content/browser/child_process_launcher.cc.orig	2016-03-04 22:27:56.807672733 +0100
+++ content/browser/child_process_launcher.cc	2016-03-04 22:34:35.624645928 +0100
@@ -229,7 +229,7 @@ void LaunchOnLauncherThread(const NotifyCallback& call
   // We need to close the client end of the IPC channel to reliably detect
   // child termination.
 
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
   ZygoteHandle* zygote_handle = delegate->GetZygote();
   // If |zygote_handle| is null, a zygote should not be used.
   if (zygote_handle) {
@@ -333,7 +333,7 @@ void TerminateOnLauncherThread(ZygoteHandle zygote, ba
   process.Terminate(RESULT_CODE_NORMAL_EXIT, false);
   // On POSIX, we must additionally reap the child.
 #if defined(OS_POSIX)
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
   if (zygote) {
     // If the renderer was created via a zygote, we have to proxy the reaping
     // through the zygote process.
@@ -435,7 +435,7 @@ void ChildProcessLauncher::Launch(
 
 void ChildProcessLauncher::UpdateTerminationStatus(bool known_dead) {
   DCHECK(CalledOnValidThread());
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
   if (zygote_) {
     termination_status_ = zygote_->GetTerminationStatus(
         process_.Handle(), known_dead, &exit_code_);
@@ -505,7 +505,7 @@ void ChildProcessLauncher::Notify(ZygoteHandle zygote,
   starting_ = false;
   process_ = std::move(process);
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
   zygote_ = zygote;
 #endif
   if (process_.IsValid()) {
