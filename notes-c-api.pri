# インクルードファイル

INCLUDEPATH += $${NOTES_C_API_PATH}/include
DEPENDPATH += $${NOTES_C_API_PATH}/include

# ライブラリファイル

LIBS += -lnotes

# マクロ

DEFINES += PRODUCTION_VERSION

# Windows以外
!win32 {
  DEFINES += HANDLE_IS_32BITS LONGIS64BIT
  LIBS += -L$${NOTES_EXEC_PATH}
}

# Windows
win32 {
  DEFINES += W32 W NT

  # 64bit
  contains(QMAKE_TARGET.arch, x86_64) {
    DEFINES += W64 ND64 _AMD64_
    LIBS += -L$${NOTES_C_API_PATH}/lib/mswin64
  }
  # 32bit
  else {
    DEFINES += _X86_
    LIBS += -L$${NOTES_C_API_PATH}/lib/mswin32
  }
}

# MacOSX
else:macx {
  DEFINES += MAC
}

# Linux64
else:unix {
  DEFINES += W32 W ND64 UNIX LINUX LINUX86 LINUX64 NDUNIX64
  LIBS += -Wl,-rpath,$${NOTES_EXEC_PATH}
}

DISTFILES += \
    $$PWD/profile.pri
