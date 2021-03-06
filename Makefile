#############################################################################
# Makefile for building: LgUploader
# Generated by qmake (2.01a) (Qt 4.6.2) on: ?? 28. ??? 12:43:24 2013
# Project:  LgUploader.pro
# Template: app
# Command: d:\apps\qt\4.6.2\bin\qmake.exe -spec ..\..\..\..\Apps\Qt\4.6.2\mkspecs\win32-g++ -win32 CONFIG+=release -o Makefile LgUploader.pro
#############################################################################

first: release
install: release-install
uninstall: release-uninstall
MAKEFILE      = Makefile
QMAKE         = d:\apps\qt\4.6.2\bin\qmake.exe
DEL_FILE      = del
CHK_DIR_EXISTS= if not exist
MKDIR         = mkdir
COPY          = copy /y
COPY_FILE     = $(COPY)
COPY_DIR      = xcopy /s /q /y /i
INSTALL_FILE  = $(COPY_FILE)
INSTALL_PROGRAM = $(COPY_FILE)
INSTALL_DIR   = $(COPY_DIR)
DEL_FILE      = del
SYMLINK       = 
DEL_DIR       = rmdir
MOVE          = move
CHK_DIR_EXISTS= if not exist
MKDIR         = mkdir
SUBTARGETS    =  \
		release \
		debug

release: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release
release-make_default: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release 
release-make_first: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release first
release-all: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release all
release-clean: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release clean
release-distclean: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release distclean
release-install: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release install
release-uninstall: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release uninstall
debug: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug
debug-make_default: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug 
debug-make_first: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug first
debug-all: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug all
debug-clean: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug clean
debug-distclean: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug distclean
debug-install: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug install
debug-uninstall: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug uninstall

Makefile: LgUploader.pro  ../../../../Apps/Qt/4.6.2/mkspecs/win32-g++/qmake.conf ../../../../Apps/Qt/4.6.2/mkspecs/qconfig.pri \
		../../../../Apps/Qt/4.6.2/mkspecs/features/qt_functions.prf \
		../../../../Apps/Qt/4.6.2/mkspecs/features/qt_config.prf \
		../../../../Apps/Qt/4.6.2/mkspecs/features/exclusive_builds.prf \
		../../../../Apps/Qt/4.6.2/mkspecs/features/default_pre.prf \
		../../../../Apps/Qt/4.6.2/mkspecs/features/win32/default_pre.prf \
		../../../../Apps/Qt/4.6.2/mkspecs/features/release.prf \
		../../../../Apps/Qt/4.6.2/mkspecs/features/debug_and_release.prf \
		../../../../Apps/Qt/4.6.2/mkspecs/features/default_post.prf \
		../../../../Apps/Qt/4.6.2/mkspecs/features/win32/default_post.prf \
		../../../../Apps/Qt/4.6.2/mkspecs/features/win32/rtti.prf \
		../../../../Apps/Qt/4.6.2/mkspecs/features/win32/exceptions.prf \
		../../../../Apps/Qt/4.6.2/mkspecs/features/win32/stl.prf \
		../../../../Apps/Qt/4.6.2/mkspecs/features/shared.prf \
		../../../../Apps/Qt/4.6.2/mkspecs/features/warn_on.prf \
		../../../../Apps/Qt/4.6.2/mkspecs/features/qt.prf \
		../../../../Apps/Qt/4.6.2/mkspecs/features/win32/thread.prf \
		../../../../Apps/Qt/4.6.2/mkspecs/features/moc.prf \
		../../../../Apps/Qt/4.6.2/mkspecs/features/win32/windows.prf \
		../../../../Apps/Qt/4.6.2/mkspecs/features/resources.prf \
		../../../../Apps/Qt/4.6.2/mkspecs/features/uic.prf \
		../../../../Apps/Qt/4.6.2/mkspecs/features/yacc.prf \
		../../../../Apps/Qt/4.6.2/mkspecs/features/lex.prf \
		../../../../Apps/Qt/4.6.2/mkspecs/features/incredibuild_xge.prf \
		d:/Apps/Qt/4.6.2/lib/qtmain.prl
	$(QMAKE) -spec ..\..\..\..\Apps\Qt\4.6.2\mkspecs\win32-g++ -win32 CONFIG+=release -o Makefile LgUploader.pro
..\..\..\..\Apps\Qt\4.6.2\mkspecs\qconfig.pri:
..\..\..\..\Apps\Qt\4.6.2\mkspecs\features\qt_functions.prf:
..\..\..\..\Apps\Qt\4.6.2\mkspecs\features\qt_config.prf:
..\..\..\..\Apps\Qt\4.6.2\mkspecs\features\exclusive_builds.prf:
..\..\..\..\Apps\Qt\4.6.2\mkspecs\features\default_pre.prf:
..\..\..\..\Apps\Qt\4.6.2\mkspecs\features\win32\default_pre.prf:
..\..\..\..\Apps\Qt\4.6.2\mkspecs\features\release.prf:
..\..\..\..\Apps\Qt\4.6.2\mkspecs\features\debug_and_release.prf:
..\..\..\..\Apps\Qt\4.6.2\mkspecs\features\default_post.prf:
..\..\..\..\Apps\Qt\4.6.2\mkspecs\features\win32\default_post.prf:
..\..\..\..\Apps\Qt\4.6.2\mkspecs\features\win32\rtti.prf:
..\..\..\..\Apps\Qt\4.6.2\mkspecs\features\win32\exceptions.prf:
..\..\..\..\Apps\Qt\4.6.2\mkspecs\features\win32\stl.prf:
..\..\..\..\Apps\Qt\4.6.2\mkspecs\features\shared.prf:
..\..\..\..\Apps\Qt\4.6.2\mkspecs\features\warn_on.prf:
..\..\..\..\Apps\Qt\4.6.2\mkspecs\features\qt.prf:
..\..\..\..\Apps\Qt\4.6.2\mkspecs\features\win32\thread.prf:
..\..\..\..\Apps\Qt\4.6.2\mkspecs\features\moc.prf:
..\..\..\..\Apps\Qt\4.6.2\mkspecs\features\win32\windows.prf:
..\..\..\..\Apps\Qt\4.6.2\mkspecs\features\resources.prf:
..\..\..\..\Apps\Qt\4.6.2\mkspecs\features\uic.prf:
..\..\..\..\Apps\Qt\4.6.2\mkspecs\features\yacc.prf:
..\..\..\..\Apps\Qt\4.6.2\mkspecs\features\lex.prf:
..\..\..\..\Apps\Qt\4.6.2\mkspecs\features\incredibuild_xge.prf:
d:\Apps\Qt\4.6.2\lib\qtmain.prl:
qmake: qmake_all FORCE
	@$(QMAKE) -spec ..\..\..\..\Apps\Qt\4.6.2\mkspecs\win32-g++ -win32 CONFIG+=release -o Makefile LgUploader.pro

qmake_all: FORCE

make_default: release-make_default debug-make_default FORCE
make_first: release-make_first debug-make_first FORCE
all: release-all debug-all FORCE
clean: release-clean debug-clean FORCE
distclean: release-distclean debug-distclean FORCE
	-$(DEL_FILE) Makefile

release-mocclean: $(MAKEFILE).Release
	$(MAKE) -f $(MAKEFILE).Release mocclean
debug-mocclean: $(MAKEFILE).Debug
	$(MAKE) -f $(MAKEFILE).Debug mocclean
mocclean: release-mocclean debug-mocclean

release-mocables: $(MAKEFILE).Release
	$(MAKE) -f $(MAKEFILE).Release mocables
debug-mocables: $(MAKEFILE).Debug
	$(MAKE) -f $(MAKEFILE).Debug mocables
mocables: release-mocables debug-mocables
FORCE:

$(MAKEFILE).Release: Makefile
$(MAKEFILE).Debug: Makefile
